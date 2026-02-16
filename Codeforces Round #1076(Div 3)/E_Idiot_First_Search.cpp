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
void solve() {
    int n;
    cin >> n;

    vector<int> l(n + 1, 0), r(n + 1, 0), p(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> l[i] >> r[i];
        if (l[i] != 0) {
            p[l[i]] = i;
            p[r[i]] = i;
        }
    }
    p[1] = 0; 

    vector<int> order;
    order.reserve(n);
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);
        if (l[u] != 0) {
            q.push(l[u]);
            q.push(r[u]);
        }
    }

    vector<ll> E(n + 1, 0);
    for (int i = n - 1; i >= 0; --i) {
        int u = order[i];
        if (l[u] == 0) {
            E[u] = 1; 
        } else {
            E[u] = (E[l[u]] + E[r[u]] + 3) % MOD; 
        }
    }

    vector<ll> f(n + 1, 0);
    f[1] = E[1];
    for (int i = 1; i < n; ++i) {
        int u = order[i];
        f[u] = (E[u] + f[p[u]]) % MOD;
    }

    for (int i = 1; i <= n; ++i) {
        cout << f[i] << (i == n ? "" : " ");
    }
    cout << endl;
}