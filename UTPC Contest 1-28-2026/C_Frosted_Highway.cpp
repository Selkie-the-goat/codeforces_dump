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

    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
/*---------------------☆*: .｡. o(≧▽≦)o .｡.:*☆----------------------*/

    void solve() {
    ll n, q;
    cin >> n >> q;

    vector<ll> road(n + 1);
    for (ll i = 1; i <= n; i++) {
        cin >> road[i];
    }

    vector<ll> pref(n + 1, 0);
    for (ll i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + (gcd(road[i], i) == 1);
    }

    while (q--) {
        ll a, b;
        cin >> a >> b;
        cout << pref[b] - pref[a - 1] << '\n';
    }
}


