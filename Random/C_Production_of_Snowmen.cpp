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
    //Input/Output go bRRRRRRRRR!!!!
    int t=1; 
    cin >> t;
    while (t--) {
        solve();
        cout << endl;
    }
 
    return 0;
}
/*---------------------☆*: .｡. o(≧▽≦)o .｡.:*☆----------------------*/

void solve() {
    int n;
    cin >> n;
    vector<int>a(n), b(n), c(n);
    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;
    for (int &x : c) cin >> x;


    int goodAB = 0, goodBC = 0;

    for (int d = 0; d < n; d++) {
        bool ok = true;
        for (int i = 0; i < n; i++) {
            if (!(a[i] < b[(i+d)%n])) {
                ok = false;
                break;
            }
        }
        if (ok) goodAB++;
    }

    for (int d = 0; d < n; d++) {
        bool ok = true;
        for (int i = 0; i < n; i++) {
            if (!(b[i] < c[(i+d)%n])) {
                ok = false;
                break;
            }
        }
        if (ok) goodBC++;
    }
    cout << 1LL * n * goodAB * goodBC;
}