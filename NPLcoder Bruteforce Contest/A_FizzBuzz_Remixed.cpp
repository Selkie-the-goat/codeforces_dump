<<<<<<< HEAD
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
    ll n;
    cin >> n;
    
    ll full_cycles = n / 15;
    ll ans = full_cycles * 3;
    
    ll rem = n % 15;
    
   
    ans += min(rem + 1, (ll)3);
    
    cout << ans << endl;
=======
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
    ll n;
    cin >> n;
    
    ll full_cycles = n / 15;
    ll ans = full_cycles * 3;
    
    ll rem = n % 15;
    
   
    ans += min(rem + 1, (ll)3);
    
    cout << ans << endl;
>>>>>>> f4a3ee5404bcb997bd906211f57ce621ed833c48
}