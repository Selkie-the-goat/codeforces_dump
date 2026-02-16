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
const int INF = 1e9;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    vector<int> dp(7, 0);

    for (int v = 1; v <= 6; ++v) {
        dp[v] = (a[0] == v ? 0 : 1);
    }

    for (int i = 1; i < n; ++i) {
        vector<int> next_dp(7, INF);
        for (int v = 1; v <= 6; ++v) {
            int cost = (a[i] == v ? 0 : 1);
            
            for (int u = 1; u <= 6; ++u) {
                if (u != v && u + v != 7) {
                    next_dp[v] = min(next_dp[v], dp[u] + cost);
                }
            }
        }
        dp = next_dp;
    }

    int ans = INF;
    for (int v = 1; v <= 6; ++v) {
        ans = min(ans, dp[v]);
    }
    cout << ans << endl;
}