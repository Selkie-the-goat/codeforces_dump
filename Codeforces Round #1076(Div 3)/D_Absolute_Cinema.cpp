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
    ll n;
    if (!(cin >> n)) return;
    vector<ll> f(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> f[i];
    }

    ll S = (f[1] + f[n]) / (n - 1);

    vector<ll> a(n + 1);

    a[1] = (f[2] - f[1] + S) / 2;

    a[n] = (S - (f[n] - f[n-1])) / 2;

    for (int i = 2; i < n; ++i) {
        a[i] = (f[i + 1] - 2 * f[i] + f[i - 1]) / 2;
    }

    for (int i = 1; i <= n; ++i) {
        cout << a[i] << (i == n ? "" : " ");
    }
    cout << endl;
}