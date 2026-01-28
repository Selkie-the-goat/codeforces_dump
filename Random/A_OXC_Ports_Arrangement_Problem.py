import sys
from collections import defaultdict
import heapq
import random

def solve():
    N, S, L = map(int, input().split())
    M, K, P = map(int, input().split())
    R = N * (S // P) * K
    sp = S // P
    k_total = sp * K
    
    # Precompute port information
    port_info = [[None] * R for _ in range(M)]
    for m in range(M):
        plane = m // (M // P)
        for p in range(R):
            g = p // k_total
            rem = p % k_total
            s_local = rem // K
            k = rem % K
            s_global = plane * sp + s_local
            port_info[m][p] = (g, s_global, k, s_local)
    
    # Store previous config to minimize adjustment cost
    prev_oxc_config = [[-1] * R for _ in range(M)]
    oxc_config = [[-1] * R for _ in range(M)]
    
    for query_idx in range(5):
        Q = int(input())
        flows = []
        demand = defaultdict(int)
        leaf_demand = defaultdict(lambda: defaultdict(int))  # (gA, lA) -> (gB, lB) -> count
        
        for i in range(Q):
            gA, lA, gB, lB = map(int, input().split())
            flows.append((gA, lA, gB, lB))
            u, v = (gA, gB) if gA < gB else (gB, gA)
            demand[(u, v)] += 1
            leaf_demand[(gA, lA)][(gB, lB)] += 1
        
        # Copy previous config
        for m in range(M):
            for p in range(R):
                oxc_config[m][p] = prev_oxc_config[m][p]
        
        # Track existing connections
        existing = defaultdict(list)
        used_ports = set()
        for m in range(M):
            for p in range(R):
                if oxc_config[m][p] > p:
                    q = oxc_config[m][p]
                    gA, gB = port_info[m][p][0], port_info[m][q][0]
                    u, v = (gA, gB) if gA < gB else (gB, gA)
                    existing[(u, v)].append((m, p, q))
                    used_ports.add((m, p))
                    used_ports.add((m, q))
        
        # Find free ports per group per OXC
        free = defaultdict(list)
        for m in range(M):
            for p in range(R):
                if (m, p) not in used_ports:
                    g = port_info[m][p][0]
                    free[(g, m)].append(p)
        
        # Sort demands by count
        demands_list = [(cnt, u, v) for (u, v), cnt in demand.items()]
        demands_list.sort(reverse=True)
        
        # Allocate links more intelligently
        allocated = {(u, v): len(existing[(u, v)]) for _, u, v in demands_list}
        
        def add_link(u, v, prefer_existing_oxc=False):
            # Try to add on OXC that already has links for this pair
            if prefer_existing_oxc and existing[(u, v)]:
                used_oxcs = set(m for m, _, _ in existing[(u, v)])
                for m in used_oxcs:
                    if (u, m) in free and (v, m) in free and free[(u, m)] and free[(v, m)]:
                        pA = free[(u, m)].pop()
                        pB = free[(v, m)].pop()
                        oxc_config[m][pA] = pB
                        oxc_config[m][pB] = pA
                        used_ports.add((m, pA))
                        used_ports.add((m, pB))
                        existing[(u, v)].append((m, pA, pB))
                        return True
            
            # Try all OXCs
            for m in range(M):
                if (u, m) in free and (v, m) in free and free[(u, m)] and free[(v, m)]:
                    pA = free[(u, m)].pop()
                    pB = free[(v, m)].pop()
                    oxc_config[m][pA] = pB
                    oxc_config[m][pB] = pA
                    used_ports.add((m, pA))
                    used_ports.add((m, pB))
                    existing[(u, v)].append((m, pA, pB))
                    return True
            return False
        
        # Aggressive link allocation to minimize conflicts
        # Target: aim for max conflict of 1 (ideal)
        # Strategy: allocate enough links so that flows can be distributed evenly
        # For conflict=1, we ideally want at least cnt links (one per flow)
        # But we can be smarter: if we have enough total capacity, allocate more
        
        target_max_conflict = 1  # Aim for conflict of 1
        
        # Calculate total available capacity
        total_free_ports = sum(len(ports) for ports in free.values())
        total_demand = sum(cnt for cnt, _, _ in demands_list)
        
        pq = []
        for cnt, u, v in demands_list:
            # Target: enough links to achieve conflict <= target_max_conflict
            # For conflict=1, we need at least cnt links ideally
            # But if capacity is limited, we'll distribute more evenly
            target_links = max(1, (cnt + target_max_conflict - 1) // target_max_conflict)
            
            # If we have plenty of capacity, be more aggressive
            if total_free_ports >= total_demand * 2:
                target_links = max(target_links, cnt)  # Aim for conflict=1
            elif total_free_ports >= total_demand:
                # Moderate capacity: aim for conflict <= 2
                target_links = max(target_links, (cnt + 1) // 2)
            
            if allocated[(u, v)] < target_links:
                # Priority: higher demand and larger deficit
                deficit = target_links - allocated[(u, v)]
                priority = deficit * cnt * cnt  # Square to prioritize high-demand pairs
                heapq.heappush(pq, (-priority, cnt, u, v, target_links))
        
        # First pass: prefer existing OXCs to minimize adjustment cost
        max_iter = min(50000, sum(d[0] for d in demands_list) * 10)
        iter_count = 0
        while pq and iter_count < max_iter:
            iter_count += 1
            neg_priority, cnt, u, v, target_links = heapq.heappop(pq)
            if allocated[(u, v)] >= target_links:
                continue
            
            if add_link(u, v, prefer_existing_oxc=True):
                allocated[(u, v)] += 1
                if allocated[(u, v)] < target_links:
                    deficit = target_links - allocated[(u, v)]
                    priority = deficit * cnt * cnt
                    heapq.heappush(pq, (-priority, cnt, u, v, target_links))
        
        # Second pass: add more links if still needed (without preference)
        # Recalculate capacity after first pass
        total_free_ports = sum(len(ports) for ports in free.values())
        
        pq2 = []
        for cnt, u, v in demands_list:
            target_links = max(1, (cnt + target_max_conflict - 1) // target_max_conflict)
            if total_free_ports >= total_demand:
                target_links = max(target_links, cnt)
            if allocated[(u, v)] < target_links:
                deficit = target_links - allocated[(u, v)]
                priority = deficit * cnt * cnt
                heapq.heappush(pq2, (-priority, cnt, u, v, target_links))
        
        iter_count2 = 0
        max_iter2 = min(30000, sum(d[0] for d in demands_list) * 8)
        while pq2 and iter_count2 < max_iter2:
            iter_count2 += 1
            neg_priority, cnt, u, v, target_links = heapq.heappop(pq2)
            if allocated[(u, v)] >= target_links:
                continue
            
            if add_link(u, v, prefer_existing_oxc=False):
                allocated[(u, v)] += 1
                if allocated[(u, v)] < target_links:
                    deficit = target_links - allocated[(u, v)]
                    priority = deficit * cnt * cnt
                    heapq.heappush(pq2, (-priority, cnt, u, v, target_links))
        
        # Output OXC configuration
        for m in range(M):
            print(' '.join(map(str, oxc_config[m])))
        
        # Advanced flow routing with multi-constraint load balancing
        # We need to minimize the maximum load across:
        # 1. Leaf-Spine links: (group, leaf, spine)
        # 2. Spine-OXC links: (group, spine, link_num, oxc)
        
        link_data = {}
        for (u, v), links in existing.items():
            link_data[(u, v)] = [[m, p, q, 0] for m, p, q in links]  # [m, p, q, load]
        
        # Track loads at all levels
        leaf_spine_load = defaultdict(int)  # (g, l, s) -> load
        spine_oxc_load = defaultdict(int)   # (g, s, k, m) -> load
        
        # Build heaps for each group pair, but we'll use a smarter routing strategy
        heaps = {}
        for key, links in link_data.items():
            if links:
                # Store links with their current load
                heaps[key] = [(0, i) for i in range(len(links))]
                heapq.heapify(heaps[key])
        
        # Route flows with constraint-aware load balancing
        routes = []
        for gA, lA, gB, lB in flows:
            u, v = (gA, gB) if gA < gB else (gB, gA)
            
            if (u, v) not in heaps or not heaps[(u, v)]:
                routes.append((0, 0, 0, 0, 0))
                continue
            
            # Find best route by trying all available links
            # Score each link based on maximum load it would create
            best_route = None
            best_max_load = float('inf')
            
            for idx, link in enumerate(link_data[(u, v)]):
                m, pA, pB, link_load = link
                
                # Determine which port is for which group
                if port_info[m][pA][0] == gA:
                    sA, kA = port_info[m][pA][1], port_info[m][pA][2]
                    sB, kB = port_info[m][pB][1], port_info[m][pB][2]
                else:
                    sA, kA = port_info[m][pB][1], port_info[m][pB][2]
                    sB, kB = port_info[m][pA][1], port_info[m][pA][2]
                
                # Calculate what the loads would be after routing through this link
                new_ls_A = leaf_spine_load[(gA, lA, sA)] + 1
                new_ls_B = leaf_spine_load[(gB, lB, sB)] + 1
                new_so_A = spine_oxc_load[(gA, sA, kA, m)] + 1
                new_so_B = spine_oxc_load[(gB, sB, kB, m)] + 1
                new_link_load = link_load + 1
                
                # Maximum load across all constraints
                max_load = max(new_ls_A, new_ls_B, new_so_A, new_so_B, new_link_load)
                
                if max_load < best_max_load:
                    best_max_load = max_load
                    best_route = (sA, kA, m, sB, kB, idx)
            
            if best_route:
                sA, kA, m, sB, kB, idx = best_route
                link = link_data[(u, v)][idx]
                
                # Update all loads
                link[3] += 1
                leaf_spine_load[(gA, lA, sA)] += 1
                leaf_spine_load[(gB, lB, sB)] += 1
                spine_oxc_load[(gA, sA, kA, m)] += 1
                spine_oxc_load[(gB, sB, kB, m)] += 1
                
                routes.append((sA, kA, m, sB, kB))
            else:
                routes.append((0, 0, 0, 0, 0))
        
        # Output routes
        for route in routes:
            print(f"{route[0]} {route[1]} {route[2]} {route[3]} {route[4]}")
        
        # Update previous config for next query
        for m in range(M):
            for p in range(R):
                prev_oxc_config[m][p] = oxc_config[m][p]

if __name__ == "__main__":
    solve()
