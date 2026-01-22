#include <bits/stdc++.h>
using namespace std;
#define el "\n"
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(x) x.begin(), x.end()
string yes = "YES", no = "NO";
typedef long long ll;
void solve() {
    string r;
    cin >> r;
    for (char c : r) {
        assert(c == 's' || c == 'u');
    }
    int n = r.length();
    int dp0 = (r[0] == 'u');
    int dp1 = 1e9; 
    for (int i = 1; i < n; i++) {
        int next_dp0, next_dp1;
        int cost_to_s = (r[i] == 'u');
        next_dp0 = cost_to_s + min(dp0, dp1);
        if (r[i] == 's') {
            next_dp1 = 1e9;
        } else {
            next_dp1 = dp0;
        }
        dp0 = next_dp0;
        dp1 = next_dp1;
    }
    cout << dp0 << el;
}
int main() {
    fastio;
    int t; 
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}