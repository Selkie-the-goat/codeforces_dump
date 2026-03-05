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
        cout << endl;
    }
 
    return 0;
}
/*---------------------☆*: .｡. o(≧▽≦)o .｡.:*☆----------------------*/
void solve() {
    ll n;
    cin >> n;

    vector<ll> a(n), b(n);

    for (ll i = 0; i < n; i++) cin >> a[i];
    for (ll i = 0; i < n; i++) cin >> b[i];

    sort(all(a));
    reverse(all(a));

    ll max_score = 0;
    ll sum = 0;
    int h = -1;

    for (int i = 1; i <= n; i++) {
        while (h + 1 < n && sum + b[h + 1] <= i) {
            h++;
            sum += b[h];
        }

        max_score = max(max_score, a[i - 1] * 1LL * (h + 1));
    }

    cout << max_score;
}