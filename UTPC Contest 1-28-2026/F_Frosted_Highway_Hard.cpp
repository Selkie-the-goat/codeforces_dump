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
    int n, q;
    cin >> n >> q;

    vector<int> h(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }

    vector<tuple<int,int,int>> queries(q);
    set<int> unique_k;

    for (int i = 0; i < q; i++) {
        int l, r, k;
        cin >> l >> r >> k;
        queries[i] = {l, r, k};
        unique_k.insert(k);
    }

    unordered_map<int, vector<int>> pos;

    for (int k : unique_k) {
        vector<int> indices;
        for (int i = 1; i <= n; i++) {
            if (gcd(h[i], i) % k == 0) {
                indices.push_back(i);
            }
        }
        pos[k] = move(indices); 
    }

    for (auto [l, r, k] : queries) {
        auto &v = pos[k];
        int left = lower_bound(v.begin(), v.end(), l) - v.begin();
        int right = upper_bound(v.begin(), v.end(), r) - v.begin();
        cout << right - left << "\n";
    }
}