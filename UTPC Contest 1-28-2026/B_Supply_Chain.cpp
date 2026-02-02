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
    ll n, t;
    cin >> n >> t;

    vector<ll> a(n);
    ll first_sum = 0;
    ll great = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        first_sum += a[i];
        great = max(great, a[i]);
    }

    if (t < first_sum) {
        cout << 0 << '\n';
        return;
    }

    cout << 1 + (t - first_sum) / great << '\n';
}
