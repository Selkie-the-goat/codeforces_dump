<<<<<<< HEAD
#include <bits/stdc++.h>

using namespace std;

struct Edge {
    int u, v, w;
};

struct DSU {
    vector<int> parent;
    DSU(int n) : parent(n + 1) {
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int i) {
        return parent[i] == i ? i : parent[i] = find(parent[i]);
    }
    bool unite(int i, int j) {
        int ri = find(i), rj = find(j);
        if (ri != rj) {
            parent[ri] = rj;
            return true;
        }
        return false;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<Edge> edges(m);
    for (auto& e : edges) {
        cin >> e.u >> e.v >> e.w;
    }

    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
        return a.w < b.w;
    });

    // Build MST
    DSU dsu(n);
    vector<int> mst;
    ll mst_sum = 0;
    
    for (int i = 0; i < m; ++i) {
        if (dsu.unite(edges[i].u, edges[i].v)) {
            mst.push_back(i);
            mst_sum += edges[i].w;
        }
    }

    // If graph is disconnected, just take first n-1 edges
    if (mst.size() < n - 1) {
        ll sum = 0;
        for (int i = 0; i < n - 1; ++i) {
            sum += edges[i].w;
        }
        cout << sum << "\n";
        return;
    }

    // If only n-1 edges total, no solution
    if (m == n - 1) {
        cout << -1 << "\n";
        return;
    }

    // Try removing each MST edge and adding each non-MST edge
    ll ans = LLONG_MAX;
    
    set<int> mst_set(mst.begin(), mst.end());
    
    for (int remove : mst) {
        for (int add = 0; add < m; ++add) {
            if (mst_set.count(add)) continue;
            
            // Check if this gives us a disconnected graph
            DSU test(n);
            int components = n;
            
            for (int idx : mst) {
                if (idx == remove) continue;
                if (test.unite(edges[idx].u, edges[idx].v)) {
                    components--;
                }
            }
            
            if (test.unite(edges[add].u, edges[add].v)) {
                components--;
            }
            
            if (components > 1) {
                // Disconnected!
                ll cost = mst_sum - edges[remove].w + edges[add].w;
                ans = min(ans, cost);
            }
        }
    }
    
    cout << (ans == LLONG_MAX ? -1 : ans) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
=======
#include <bits/stdc++.h>

using namespace std;

struct Edge {
    int u, v, w;
};

struct DSU {
    vector<int> parent;
    DSU(int n) : parent(n + 1) {
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int i) {
        return parent[i] == i ? i : parent[i] = find(parent[i]);
    }
    bool unite(int i, int j) {
        int ri = find(i), rj = find(j);
        if (ri != rj) {
            parent[ri] = rj;
            return true;
        }
        return false;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<Edge> edges(m);
    for (auto& e : edges) {
        cin >> e.u >> e.v >> e.w;
    }

    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
        return a.w < b.w;
    });

    // Build MST
    DSU dsu(n);
    vector<int> mst;
    ll mst_sum = 0;
    
    for (int i = 0; i < m; ++i) {
        if (dsu.unite(edges[i].u, edges[i].v)) {
            mst.push_back(i);
            mst_sum += edges[i].w;
        }
    }

    // If graph is disconnected, just take first n-1 edges
    if (mst.size() < n - 1) {
        ll sum = 0;
        for (int i = 0; i < n - 1; ++i) {
            sum += edges[i].w;
        }
        cout << sum << "\n";
        return;
    }

    // If only n-1 edges total, no solution
    if (m == n - 1) {
        cout << -1 << "\n";
        return;
    }

    // Try removing each MST edge and adding each non-MST edge
    ll ans = LLONG_MAX;
    
    set<int> mst_set(mst.begin(), mst.end());
    
    for (int remove : mst) {
        for (int add = 0; add < m; ++add) {
            if (mst_set.count(add)) continue;
            
            // Check if this gives us a disconnected graph
            DSU test(n);
            int components = n;
            
            for (int idx : mst) {
                if (idx == remove) continue;
                if (test.unite(edges[idx].u, edges[idx].v)) {
                    components--;
                }
            }
            
            if (test.unite(edges[add].u, edges[add].v)) {
                components--;
            }
            
            if (components > 1) {
                // Disconnected!
                ll cost = mst_sum - edges[remove].w + edges[add].w;
                ans = min(ans, cost);
            }
        }
    }
    
    cout << (ans == LLONG_MAX ? -1 : ans) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
>>>>>>> f4a3ee5404bcb997bd906211f57ce621ed833c48
}