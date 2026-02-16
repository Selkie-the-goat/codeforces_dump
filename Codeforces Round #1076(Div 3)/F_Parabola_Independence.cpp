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
struct Func {
    long long a, b, c;
    int id;
};

void solve() {
    int n;
    cin >> n;
    vector<Func> f(n);
    for (int i = 0; i < n; ++i) {
        cin >> f[i].a >> f[i].b >> f[i].c;
        f[i].id = i;
    }

    sort(f.begin(), f.end(), [](const Func& x, const Func& y) {
        if (x.a != y.a) return x.a < y.a;
        if (x.b != y.b) return x.b < y.b;
        return x.c < y.c;
    });

    auto is_less = [](const Func& i, const Func& j) {
        if (i.a == j.a) {
            return i.b == j.b && i.c < j.c;
        }
        if (i.a > j.a) return false;
        ll da = j.a - i.a;
        ll db = j.b - i.b;
        ll dc = j.c - i.c;
        return (db * db < 4 * da * dc);
    };

    vector<int> dp_up(n, 1);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (is_less(f[j], f[i])) {
                dp_up[i] = max(dp_up[i], dp_up[j] + 1);
            }
        }
    }

    vector<int> dp_down(n, 1);
    for (int i = n - 1; i >= 0; --i) {
        for (int j = n - 1; j > i; --j) {
            if (is_less(f[i], f[j])) {
                dp_down[i] = max(dp_down[i], dp_down[j] + 1);
            }
        }
    }

    vector<int> results(n);
    for (int i = 0; i < n; ++i) {
        results[f[i].id] = dp_up[i] + dp_down[i] - 1;
    }

    for (int i = 0; i < n; ++i) {
        cout << results[i] << (i == n - 1 ? "" : " ");
    }
    cout << endl;
}