#include <bits/stdc++.h>
using namespace std;
#define el "\n"
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(x) x.begin(), x.end()
string yes = "YES", no = "NO";
typedef long long ll;
/* -----------------------COOKED.------------------------------*/
void solve() {
    int n; 
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<ll> suf(n + 1, 0);
    for (int i = n - 1; i >= 0; i--) {
        suf[i] = suf[i+1] + a[i];
    }
    vector<ll> prefAbs(n + 1, 0);
    for (int i = 0; i < n; i++) {
        prefAbs[i+1] = prefAbs[i] + abs(a[i]);
    }
    ll max_x = -9e18; 
    for (int k = 0; k < n; k++) {
        ll current_x = 0;
        if (k == 0) {
            current_x = -suf[1];
        } else {
            current_x += a[0];
            if (k > 1) {
                current_x += (prefAbs[k] - prefAbs[1]);
            }
            current_x -= suf[k+1];
        }
        max_x = max(max_x, current_x);
    }
    cout << max_x << el;
}
int main() {
    fastio;
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}