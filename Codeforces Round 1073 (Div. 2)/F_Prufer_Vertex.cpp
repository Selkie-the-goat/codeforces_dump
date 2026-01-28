#include <bits/stdc++.h>
using namespace std;

const long long MOD = 998244353;

long long power(long long a, long long b) {
    long long res = 1;
    a %= MOD;
    while (b > 0) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

int find(int x, vector<int>& par) {
    return par[x] == x ? x : par[x] = find(par[x], par);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n, m;
        cin >> n >> m;
        
        vector<int> par(n + 1);
        iota(par.begin(), par.end(), 0);
        
        vector<int> deg(n + 1, 0);
        
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            deg[u]++;
            deg[v]++;
            int pu = find(u, par), pv = find(v, par);
            if (pu != pv) par[pu] = pv;
        }
        
        map<int, int> compSize;
        for (int i = 1; i <= n; i++) {
            compSize[find(i, par)]++;
        }
        
        int k = compSize.size();
        long long prod = 1;
        for (auto& [root, sz] : compSize) {
            prod = prod * sz % MOD;
        }
        
        int nComp = find(n, par);
        long long base = power(n, max(0, k - 2));
        
        for (int v = 1; v < n; v++) {
            int vComp = find(v, par);
            long long ans;
            
            if (vComp != nComp) {
                // Different component: count based on how v connects
                ans = base * prod % MOD * power(n, MOD - 2) % MOD;
            } else {
                // Same component: depends on degrees
                ans = base * prod % MOD * power(n, MOD - 2) % MOD * (n - v) % MOD;
            }
            
            cout << ans;
            if (v < n - 1) cout << " ";
        }
        cout << "\n";
    }
    
    return 0;
}