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
    int n;
    cin >> n;
    
    vector<int> c(n), d(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i] >> d[i];
    }
    
    ll minRating = -1e9;
    ll maxRating = 1e9;
    
    
    for (int i = 0; i < n; i++) {
        
        if (d[i] == 1) {
            
            minRating = max(minRating, 1900LL);
        } else {
            
            maxRating = min(maxRating, 1899LL);
        }
        
        if (minRating > maxRating) {
            cout << "Impossible" << endl;
            return ;
        }
        
        minRating += c[i];
        maxRating += c[i];
    }
    
    
    ll testRating = 1e9;
    bool canBeInfinity = true;
    
    for (int i = 0; i < n; i++) {
        if (d[i] == 1) {
            if (testRating < 1900) {
                canBeInfinity = false;
                break;
            }
        } else {
            if (testRating > 1899) {
                canBeInfinity = false;
                break;
            }
        }
        testRating += c[i];
    }
    
    if (canBeInfinity) {
        cout << "Infinity" << endl;
    } else {
        cout << maxRating << endl;
    }
}
