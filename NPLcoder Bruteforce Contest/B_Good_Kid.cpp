#include <bits/stdc++.h>

using namespace std;

#define nl "\n"
#define all(x) x.begin(), x.end();
string yes = "YES", no = "NO";
typedef long long  ll;

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
    int n;
    cin >> n;

    vector<int> a(n);
    int min_val = 1e9;
    int min_idx = -1;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] < min_val) {
            min_val = a[i];
            min_idx = i;
        }
    }

    a[min_idx]++;

    ll ans = 1;
    for (int x : a) {
        ans *= x;
    }

    cout << ans << '\n';
}