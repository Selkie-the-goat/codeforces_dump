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
    ll n, x;
    if (!(cin >> n >> x)) return;

    ll total_S = 0;
    ll max_V = -2e18; 

    for (int i = 0; i < n; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        
        ll free_dist = (b - 1) * a;
        
        if (x - total_S > free_dist) {
            total_S += free_dist;
        } else {
            total_S = x;
        }
        
        ll current_V = b * a - c;
        if (current_V > max_V) {
            max_V = current_V;
        }
    }

    if (total_S >= x) {
        cout << "0\n";
    } else if (max_V <= 0) {
        cout << "-1\n";
    } else {
        ll needed = x - total_S;
        ll ans = (needed + max_V - 1) / max_V;
        cout << ans << "\n";
    }
}