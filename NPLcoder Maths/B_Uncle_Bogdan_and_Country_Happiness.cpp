#include <bits/stdc++.h>

using namespace std;

string yes = "YES", no = "NO";
#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

vector<int> adj[MAX_N];
ll p[MAX_N], h[MAX_N], s[MAX_N], g[MAX_N];
bool possible;

void dfs(int u, int p_node) {
    s[u] = p[u];
    ll children_g_sum = 0;

    for (int v : adj[u]) {
        if (v == p_node) continue;
        dfs(v, u);
        s[u] += s[v];
        children_g_sum += g[v];
    }

    if ((s[u] + h[u]) % 2 != 0) possible = false;
    
    g[u] = (s[u] + h[u]) / 2;

    if (g[u] < 0 || g[u] > s[u]) possible = false;
    if (g[u] < children_g_sum) possible = false;
}

void solve() {
    int n;
    ll m;
    cin >> n >> m;
    
    possible = true;
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        s[i] = 0;
        g[i] = 0;
    }

    for (int i = 1; i <= n; i++) cin >> p[i];
    for (int i = 1; i <= n; i++) cin >> h[i];

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);

    if (possible) cout << yes << "\n";
    else cout << no << "\n";
}

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(0); 
    cout.tie(0);

    int t; 
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}