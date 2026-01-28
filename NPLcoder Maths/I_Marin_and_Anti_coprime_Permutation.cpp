#include <bits/stdc++.h>

using namespace std;

string yes = "YES", no = "NO";
#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size()) //haha probably won't even use(┬┬﹏┬┬)
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const ll MOD = 998244353;
const ll INF = 1e9;
const ld EPS = 1e-9;

/* -----------------------selkie------------------------------*/
void solve();

ll dp[1005];

void precompute() {
    for (int n = 2; n <= 1000; n += 2) {
        ll fact = 1;
        for (int i = 1; i <= n/2; i++) {
            fact = (fact * i) % MOD;
        }
        dp[n] = (fact * fact) % MOD;
    }
}

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(0); 
    cout.tie(0);
    //Input/Output go bRRRRRRRRR!!!!
    
    precompute();
    
    int t=1; 
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

void solve(){
    int n;
    cin >> n;
    
    if(n&1){
        cout << 0 <<endl;
    }
    else{
        cout << dp[n] << endl;
    }
}