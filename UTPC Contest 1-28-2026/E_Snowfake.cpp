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

    set<pair<ll, ll>> points;
    vector<pair<ll, ll>> pts(n);

    for(int i = 0; i < n; i++) {
        ll u, v;
        cin >> u >> v;
        pts[i] = {u, v};
        points.insert({u, v});
    }

    for(auto [u, v] : pts) {
        ll u_rot = -v;
        ll v_rot = u + v;

        if(points.find({u_rot, v_rot}) == points.end()) {
            cout << no << endl;
            return;
        }
    }

    cout << yes <<endl;
}

