#include <bits/stdc++.h>

using namespace std;

string yes = "YES", no = "NO";
#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size()) //haha probably won't even use(┬┬﹏┬┬)
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

/* -----------------------selkie------------------------------*/
void solve();
int main() {
    ios::sync_with_stdio(false); 
    cin.tie(0); 
    cout.tie(0);
    //Input/Output go bRRRRRRRRR!!!!
    int t; cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> p(m);
    for (int i = 0; i < m; i++) {
        cin >> p[i];
    }

    vector<int> ans(n + 1, -1);
    unordered_set<int> seen;

    int distinct = 0; 

    for (int t = 1; t <= m; t++) {
        if (!seen.count(p[t - 1])) {
            seen.insert(p[t - 1]);
            distinct++;

            if (distinct <= n) {
                int removedPost = n - distinct + 1;
                ans[removedPost] = t;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
}