#include <bits/stdc++.h>

using namespace std;

string yes = "YES", no = "NO";
#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size()) //haha probably won't even use(┬┬﹏┬┬)
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

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
    int n, h, l;
    cin >> n >> h >> l;
    
    int countH = 0; 
    int countL = 0; 
    int totalValid = 0; 
    
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        bool canH = (a <= h);
        bool canL = (a <= l);
        
        if (canH) countH++;
        if (canL) countL++;
        if (canH || canL) totalValid++;
    }

    int ans = min({countH, countL, totalValid / 2});
    cout << ans << "\n";
}