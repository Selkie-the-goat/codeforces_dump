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
        cout << endl;
    }
 
    return 0;
}
/*---------------------☆*: .｡. o(≧▽≦)o .｡.:*☆----------------------*/

void solve() {
    int n, m;
    cin >> n >> m;

    multiset<int> h;

    for(int i = 0; i < n; i++){
        int x; cin >> x;
        h.insert(x);
    }

    while(m--){
        int x;
        cin >> x;

        auto it = h.upper_bound(x);

        if(it == h.begin()){
            cout << -1 << "\n";
        } else {
            --it;
            cout << *it << "\n";
            h.erase(it);
        }
    }
}
