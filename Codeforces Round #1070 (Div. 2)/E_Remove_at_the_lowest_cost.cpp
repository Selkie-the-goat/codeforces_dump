<<<<<<< HEAD
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>

using namespace std;

typedef long long ll;

// Global variables for values, costs, partners, and total cost
vector<ll> a, c, c_original;
vector<int> L, R;
vector<ll> current_min_costs;
ll total_min_cost;

/**
 * @brief Calculates the Nearest Left Greater-or-Equal (NLGE) and Nearest Right Greater-or-Equal (NRGE) indices.
 * * Uses a monotonic stack to find L[i] and R[i] for all i in O(n).
 */
void precalculate_partners(int n) {
    L.assign(n + 2, 0); 
    R.assign(n + 2, n + 1); 
    stack<int> s;

    // Calculate L[i]
    for (int i = 1; i <= n; ++i) {
        // Pop elements smaller than a[i]
        while (!s.empty() && a[s.top()] < a[i]) {
            s.pop();
        }
        if (!s.empty()) {
            L[i] = s.top();
        }
        s.push(i);
    }

    // Clear stack for R[i] calculation
    while (!s.empty()) {
        s.pop();
    }

    // Calculate R[i]
    for (int i = n; i >= 1; --i) {
        // Pop elements smaller than a[i]
        while (!s.empty() && a[s.top()] < a[i]) {
            s.pop();
        }
        if (!s.empty()) {
            R[i] = s.top();
        }
        s.push(i);
    }
}

/**
 * @brief Calculates the minimum removal cost for element i.
 * * Cost = min(c_i, min(c_L[i], c_R[i])). c_0 and c_{n+1} are considered infinite.
 */
ll calculate_min_cost_i(int i, int n) {
    // A large constant for "infinity"
    const ll INF = 3000000000000000000LL; 
    
    // Partner cost to the left
    ll cost_l = (L[i] != 0) ? c[L[i]] : INF;
    
    // Partner cost to the right
    ll cost_r = (R[i] != n + 1) ? c[R[i]] : INF;
    
    // The minimum cost to remove element i
    return min(c[i], min(cost_l, cost_r));
}

/**
 * @brief Solves the problem for a single test case.
 */
void solve() {
    int n;
    if (!(cin >> n)) return;

    // Input values, using 1-based indexing
    a.assign(n + 2, 0);
    for (int i = 1; i <= n; ++i) cin >> a[i];

    c.assign(n + 2, 0);
    c_original.assign(n + 2, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> c[i];
        c_original[i] = c[i];
    }

    vector<int> p(n);
    for (int i = 0; i < n; ++i) cin >> p[i];

    // Pre-calculate partners (NLGE and NRGE)
    precalculate_partners(n);

    // Dynamic approach: Solve the n+1 problems in reverse order
    vector<ll> results;
    results.reserve(n + 1);

    // Set all costs to their final zeroed state for the start of the reverse process
    for (int index : p) {
        c[index] = 0;
    }

    // Calculate total cost for the final state (all n zeroings applied)
    current_min_costs.assign(n + 2, 0);
    total_min_cost = 0;
    for (int i = 1; i <= n; ++i) {
        current_min_costs[i] = calculate_min_cost_i(i, n);
        total_min_cost += current_min_costs[i];
    }
    results.push_back(total_min_cost); // Cost after n zeroings

    // Reverse operations: k = n-1 down to 0 (restoring p[k])
    for (int k = n - 1; k >= 0; --k) {
        int index_to_restore = p[k];
        
        // Use a set to track affected indices uniquely
        set<int> affected_indices;
        
        // 1. The element itself is affected
        if (index_to_restore >= 1 && index_to_restore <= n) {
            affected_indices.insert(index_to_restore);
        }

        // 2. Indices j for which index_to_restore is L[j] or R[j] are affected
        for (int j = 1; j <= n; ++j) {
            if (L[j] == index_to_restore || R[j] == index_to_restore) {
                affected_indices.insert(j);
            }
        }
        
        // --- Update total_min_cost: Remove old costs ---
        for (int i : affected_indices) {
            total_min_cost -= current_min_costs[i];
        }

        // --- Restore the original cost ---
        c[index_to_restore] = c_original[index_to_restore];

        // --- Update total_min_cost: Add new costs ---
        for (int i : affected_indices) {
            // Calculate and add the new cost
            current_min_costs[i] = calculate_min_cost_i(i, n);
            total_min_cost += current_min_costs[i];
        }
        
        // The total cost is now the cost after k zeroings
        results.push_back(total_min_cost);
    }

    // The results are calculated in reverse order of the query.
    // Reverse to get: [Cost Before Zeroing, Cost After 1st Zeroing, ..., Cost After nth Zeroing]
    reverse(results.begin(), results.end());

    // Output the n+1 results
    for (size_t i = 0; i < results.size(); ++i) {
        cout << results[i] << (i == results.size() - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }

    return 0;
=======
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>

using namespace std;

typedef long long ll;

// Global variables for values, costs, partners, and total cost
vector<ll> a, c, c_original;
vector<int> L, R;
vector<ll> current_min_costs;
ll total_min_cost;

/**
 * @brief Calculates the Nearest Left Greater-or-Equal (NLGE) and Nearest Right Greater-or-Equal (NRGE) indices.
 * * Uses a monotonic stack to find L[i] and R[i] for all i in O(n).
 */
void precalculate_partners(int n) {
    L.assign(n + 2, 0); 
    R.assign(n + 2, n + 1); 
    stack<int> s;

    // Calculate L[i]
    for (int i = 1; i <= n; ++i) {
        // Pop elements smaller than a[i]
        while (!s.empty() && a[s.top()] < a[i]) {
            s.pop();
        }
        if (!s.empty()) {
            L[i] = s.top();
        }
        s.push(i);
    }

    // Clear stack for R[i] calculation
    while (!s.empty()) {
        s.pop();
    }

    // Calculate R[i]
    for (int i = n; i >= 1; --i) {
        // Pop elements smaller than a[i]
        while (!s.empty() && a[s.top()] < a[i]) {
            s.pop();
        }
        if (!s.empty()) {
            R[i] = s.top();
        }
        s.push(i);
    }
}

/**
 * @brief Calculates the minimum removal cost for element i.
 * * Cost = min(c_i, min(c_L[i], c_R[i])). c_0 and c_{n+1} are considered infinite.
 */
ll calculate_min_cost_i(int i, int n) {
    // A large constant for "infinity"
    const ll INF = 3000000000000000000LL; 
    
    // Partner cost to the left
    ll cost_l = (L[i] != 0) ? c[L[i]] : INF;
    
    // Partner cost to the right
    ll cost_r = (R[i] != n + 1) ? c[R[i]] : INF;
    
    // The minimum cost to remove element i
    return min(c[i], min(cost_l, cost_r));
}

/**
 * @brief Solves the problem for a single test case.
 */
void solve() {
    int n;
    if (!(cin >> n)) return;

    // Input values, using 1-based indexing
    a.assign(n + 2, 0);
    for (int i = 1; i <= n; ++i) cin >> a[i];

    c.assign(n + 2, 0);
    c_original.assign(n + 2, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> c[i];
        c_original[i] = c[i];
    }

    vector<int> p(n);
    for (int i = 0; i < n; ++i) cin >> p[i];

    // Pre-calculate partners (NLGE and NRGE)
    precalculate_partners(n);

    // Dynamic approach: Solve the n+1 problems in reverse order
    vector<ll> results;
    results.reserve(n + 1);

    // Set all costs to their final zeroed state for the start of the reverse process
    for (int index : p) {
        c[index] = 0;
    }

    // Calculate total cost for the final state (all n zeroings applied)
    current_min_costs.assign(n + 2, 0);
    total_min_cost = 0;
    for (int i = 1; i <= n; ++i) {
        current_min_costs[i] = calculate_min_cost_i(i, n);
        total_min_cost += current_min_costs[i];
    }
    results.push_back(total_min_cost); // Cost after n zeroings

    // Reverse operations: k = n-1 down to 0 (restoring p[k])
    for (int k = n - 1; k >= 0; --k) {
        int index_to_restore = p[k];
        
        // Use a set to track affected indices uniquely
        set<int> affected_indices;
        
        // 1. The element itself is affected
        if (index_to_restore >= 1 && index_to_restore <= n) {
            affected_indices.insert(index_to_restore);
        }

        // 2. Indices j for which index_to_restore is L[j] or R[j] are affected
        for (int j = 1; j <= n; ++j) {
            if (L[j] == index_to_restore || R[j] == index_to_restore) {
                affected_indices.insert(j);
            }
        }
        
        // --- Update total_min_cost: Remove old costs ---
        for (int i : affected_indices) {
            total_min_cost -= current_min_costs[i];
        }

        // --- Restore the original cost ---
        c[index_to_restore] = c_original[index_to_restore];

        // --- Update total_min_cost: Add new costs ---
        for (int i : affected_indices) {
            // Calculate and add the new cost
            current_min_costs[i] = calculate_min_cost_i(i, n);
            total_min_cost += current_min_costs[i];
        }
        
        // The total cost is now the cost after k zeroings
        results.push_back(total_min_cost);
    }

    // The results are calculated in reverse order of the query.
    // Reverse to get: [Cost Before Zeroing, Cost After 1st Zeroing, ..., Cost After nth Zeroing]
    reverse(results.begin(), results.end());

    // Output the n+1 results
    for (size_t i = 0; i < results.size(); ++i) {
        cout << results[i] << (i == results.size() - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }

    return 0;
>>>>>>> f4a3ee5404bcb997bd906211f57ce621ed833c48
}