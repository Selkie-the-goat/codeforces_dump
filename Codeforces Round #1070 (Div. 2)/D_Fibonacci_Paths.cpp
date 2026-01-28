<<<<<<< HEAD
#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;

    vector<long long> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    vector<vector<pair<long long, int>>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back({a[v], v});
    }

    for (int i = 1; i <= n; ++i) {
        sort(adj[i].begin(), adj[i].end());
    }

    vector<map<long long, int>> dp(n + 1);
    long long ans = 0;
    long long MOD = 998244353;

    for (int u = 1; u <= n; ++u) {
        for (auto& edge : adj[u]) {
            long long val_v = edge.first;
            int v = edge.second;
            // The previous value for v is a[u]
            dp[v][a[u]] = (dp[v][a[u]] + 1) % MOD;
            ans = (ans + 1) % MOD;
        }
    }

    for (int len = 3; len <= 100; ++len) {
        vector<map<long long, int>> next_dp(n + 1);
        bool possible = false;

        for (int u = 1; u <= n; ++u) {
            if (dp[u].empty()) continue;

            for (auto const& [prev_val, count] : dp[u]) {
                long long target = prev_val + a[u];
                
                auto it = lower_bound(adj[u].begin(), adj[u].end(), make_pair(target, -1));
                
                while (it != adj[u].end() && it->first == target) {
                    int v = it->second;
                    next_dp[v][a[u]] = (next_dp[v][a[u]] + count) % MOD;
                    ans = (ans + count) % MOD;
                    possible = true;
                    it++;
                }
            }
        }

        if (!possible) break;
        dp = move(next_dp);
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
=======
#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;

    vector<long long> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    vector<vector<pair<long long, int>>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back({a[v], v});
    }

    for (int i = 1; i <= n; ++i) {
        sort(adj[i].begin(), adj[i].end());
    }

    vector<map<long long, int>> dp(n + 1);
    long long ans = 0;
    long long MOD = 998244353;

    for (int u = 1; u <= n; ++u) {
        for (auto& edge : adj[u]) {
            long long val_v = edge.first;
            int v = edge.second;
            // The previous value for v is a[u]
            dp[v][a[u]] = (dp[v][a[u]] + 1) % MOD;
            ans = (ans + 1) % MOD;
        }
    }

    for (int len = 3; len <= 100; ++len) {
        vector<map<long long, int>> next_dp(n + 1);
        bool possible = false;

        for (int u = 1; u <= n; ++u) {
            if (dp[u].empty()) continue;

            for (auto const& [prev_val, count] : dp[u]) {
                long long target = prev_val + a[u];
                
                auto it = lower_bound(adj[u].begin(), adj[u].end(), make_pair(target, -1));
                
                while (it != adj[u].end() && it->first == target) {
                    int v = it->second;
                    next_dp[v][a[u]] = (next_dp[v][a[u]] + count) % MOD;
                    ans = (ans + count) % MOD;
                    possible = true;
                    it++;
                }
            }
        }

        if (!possible) break;
        dp = move(next_dp);
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
>>>>>>> f4a3ee5404bcb997bd906211f57ce621ed833c48
}