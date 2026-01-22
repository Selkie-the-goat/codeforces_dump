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
    ll r, g, b, w;
        cin >> r >> g >> b >> w;

        int odd = (r & 1) + (g & 1) + (b & 1) + (w & 1);

        if (odd <= 1) {
            cout << "Yes\n";
        } else if (r > 0 && g > 0 && b > 0 && odd >= 3) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }

}