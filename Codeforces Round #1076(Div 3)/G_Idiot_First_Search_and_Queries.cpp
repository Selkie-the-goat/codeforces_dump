#include <bits/stdc++.h>
using namespace std;
/*---------------------Boring-stuff----------------------*/
string yes = "YES", no = "NO";
#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size()) 
#define all(a) (a).begin(), (a).end()
const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
void solve();
int main() {
    ios::sync_with_stdio(false); 
    cin.tie(0); 
    cout.tie(0);
    //Input/Output go bRRRRRRRRR!!!!
    int t=1; 
    cin >> t;
    while (t--) {
        solve();
    }
 
    return 0;
}
/*---------------------☆*: .｡. o(≧▽≦)o .｡.:*☆----------------------*/
struct State {
    int u, phase;
};

void solve() {
    int n, q_count;
    cin >> n >> q_count;

    vector<int> l(n + 1), r(n + 1), p(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> l[i] >> r[i];
        if (l[i] != 0) {
            p[l[i]] = i; p[r[i]] = i;
        }
    }

    vector<int> order;
    queue<int> q; q.push(1);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        order.push_back(u);
        if (l[u]) { q.push(l[u]); q.push(r[u]); }
    }

    vector<ll> E(n + 1);
    for (int i = n - 1; i >= 0; --i) {
        int u = order[i];
        if (l[u] == 0) E[u] = 1;
        else E[u] = E[l[u]] + E[r[u]] + 3;
    }

    vector<ll> P(n + 1);
    vector<vector<int>> up(n + 1, vector<int>(20, 0));
    P[1] = E[1];
    for (int u : order) {
        if (u == 1) continue;
        P[u] = P[p[u]] + E[u];
        up[u][0] = p[u];
        for (int i = 1; i < 20; ++i) up[u][i] = up[up[u][i - 1]][i - 1];
    }

    vector<int> tour;
    vector<int> pos1(n + 1);
    vector<State> st = {{1, 0}};
    while (!st.empty()) {
        State& top = st.back();
        if (top.phase == 0) {
            pos1[top.u] = tour.size();
            tour.push_back(top.u);
            if (l[top.u] == 0) st.pop_back();
            else { top.phase = 1; st.push_back({l[top.u], 0}); }
        } else if (top.phase == 1) {
            tour.push_back(top.u);
            top.phase = 2; st.push_back({r[top.u], 0});
        } else {
            tour.push_back(top.u); st.pop_back();
        }
    }

    for (int i = 0; i < q_count; ++i) {
        int v; ll k; cin >> v >> k;
        int curr = v;
        for (int j = 19; j >= 0; --j) {
            int anc = up[curr][j];
            if (anc != 0 && (P[v] - P[anc] <= k)) curr = anc;
        }
        cout << tour[pos1[curr] + (int)(k - (P[v] - P[curr]))] << (i == q_count - 1 ? "" : " ");
    }
    cout << endl;
}