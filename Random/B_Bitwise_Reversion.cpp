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
    }
 
    return 0;
}
/*---------------------☆*: .｡. o(≧▽≦)o .｡.:*☆----------------------*/

void solve() {
    unsigned int x, y, z;
    cin >> x >> y >> z;
        
        bool cond1 = ((x & y) | z) == z;

        bool cond2 = ((x & z) | y) == y;

        bool cond3 = ((y & z) | x) == x;

        if (cond1 && cond2 && cond3) {
           cout << yes << "\n";
        } else {
           cout << no << "\n";
        }
}