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
void solve()
{
    int n;
    if (!(cin >> n)) return;
    
    vector<int> a(n);
    int cnt0 = 0;
    int cnt1 = 0;
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] == 0) cnt0++;
        if (a[i] == 1) cnt1++;
    }

    if (cnt0 == 0) {
        cout << "NO" << endl;
        return;
    }

    if (cnt1 == 0 && cnt0 > 1) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;    
    
    
}