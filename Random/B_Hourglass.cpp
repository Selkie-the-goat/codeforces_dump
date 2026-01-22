#include <bits/stdc++.h>

using namespace std;

string yes = "YES", no = "NO";
typedef long long  ll;
// const MOD=

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
void solve()
{
    int s, k, m;
        cin >> s >> k >> m;
        
        if (s <= k) cout << max(0, s - m % k) << '\n';
	else cout << (((m % (2 * k)) < k) ? s - m % k : k - m % k) << '\n';
}