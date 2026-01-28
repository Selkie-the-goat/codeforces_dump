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
    int t=1; 
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

void solve(){
    int n, k;
    cin >> n >> k;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    // Build prefix sum array
    vector<ll> prefix(n + 1, 0);
    for (int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + a[i];
    }
    
    double maxAvg = 0.0;
    
    for (int len = k; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            ll sum = prefix[i + len] - prefix[i];
            double avg = (double)sum / len;
            maxAvg = max(maxAvg, avg);
        }
    }
    
    cout << fixed << setprecision(15) << maxAvg << endl;
}
