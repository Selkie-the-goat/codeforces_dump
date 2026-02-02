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
    ll n , k;
    cin >> n >> k;
    vector<ll> a(n);
    for(ll i=0;i<n;i++){
        cin >> a[i];
    }
    sort(all(a));
    vector<ll> prefix(n);
    ll c=0;
    
    for(ll i=0;i<n;i++){
        c+=a[i];
        prefix[i]=c;
    }
    ll ans = LLONG_MAX;
    for(ll i = 0; i < n; i++) {
    ll t = a[i]; 
    
    ll killed = i + 1;      
    ll survived = n - killed; 
    
    ll damage_killed = killed * t - prefix[i]; 
    ll damage_survived = survived * k - (prefix[n-1] - prefix[i]); 
    
    ll total_damage = damage_killed + damage_survived;
    
    ans = min(ans, total_damage);
}
    cout << ans << endl;
}


