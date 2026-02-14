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
    // cin >> t;
    while (t--) {
        solve();
    }
 
    return 0;
}
/*---------------------☆*: .｡. o(≧▽≦)o .｡.:*☆----------------------*/

void solve() {
    int n;
    cin >> n;

    unsigned ll current_val = 0;
    string res = "";
    
    unsigned ll place_value = 1; 

    for (int i = 0; i < n; ++i) {
        
        unsigned ll try_one = current_val + place_value;
        unsigned ll mod_target = (1ULL << (i + 1)); 

        if (try_one % mod_target == 0) {
            current_val = try_one;
            res += '1';
        } else {
            current_val = current_val + (2 * place_value);
            res += '2';
        }
        
        place_value *= 10;
    }

    reverse(res.begin(), res.end());
    
    cout << res << endl;
}