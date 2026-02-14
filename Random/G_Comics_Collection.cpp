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

/*---------------------Logic----------------------*/

ll pref[31];
bool precomputed = false;

int get_cost(int x) {
    if (x % 5 == 0) return 5;
    if (x % 3 == 0) return 3;
    if (x % 2 == 0) return 2;
    return 1;
}

void precompute() {
    pref[0] = 0;
    for (int i = 1; i <= 30; i++) {
        pref[i] = pref[i-1] + get_cost(i);
    }
    precomputed = true;
}

void solve() {
    int n;
    cin >> n;

    ll cnt = n / 30;
    int rem = n % 30;

    ll ans = (cnt * pref[30]) + pref[rem];
    
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(0); 
    cout.tie(0);

    precompute();

    int t = 1; 
    cin >> t;
    while (t--) {
        solve();
    }
 
    return 0;
}