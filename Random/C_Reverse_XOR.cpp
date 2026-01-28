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
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

void solve() {
    int n;
    cin >> n;

    if (n == 0) {
        cout << "YES\n";
        return;
    }

    string s;
    while (n > 0) {
        s.push_back((n & 1) + '0');
        n >>= 1;
    }
    reverse(s.begin(), s.end());

    string s_trim = s;
    while (s_trim.size() > 1 && s_trim.back() == '0')
        s_trim.pop_back();

    string rev = s;
    reverse(rev.begin(), rev.end());
    while (rev.size() > 1 && rev.front() == '0')
        rev.erase(rev.begin());

    if (s_trim != rev) {
        cout << "NO\n";
        return;
    }

    int len = s_trim.size();
    if (len % 2 == 1 && s_trim[len / 2] == '1') {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
}
