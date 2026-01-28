#include <bits/stdc++.h>

using namespace std;

#define nl "\n"
#define all(x) x.begin(), x.end();
string yes = "YES", no = "NO";
typedef long long  ll;

/* -----------------------selkie------------------------------*/
void solve();
int main() {
    ios::sync_with_stdio(false); 
    cin.tie(0); 
    cout.tie(0);
    //Input/Output go bRRRRRRRRR!!!!
    int t; cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
void solve()
{
    int n;
    if (!(cin >> n)) return;
    string s;
    cin >> s;

    vector<int> bal(n + 1, 0);
    vector<int> pref_open(n + 1, 0);
    vector<int> pref_closed(n + 1, 0);

    for (int i = 0; i < n; ++i) {
        bal[i + 1] = bal[i] + (s[i] == '(' ? 1 : -1);
        pref_open[i + 1] = pref_open[i] + (s[i] == '(' ? 1 : 0);
        pref_closed[i + 1] = pref_closed[i] + (s[i] == ')' ? 1 : 0);
    }

    vector<int> next_open(n + 1, -1);
    int last = -1;
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] == '(') last = i;
        next_open[i] = last;
    }

    ll max_len = -1;

    for (int k = 0; k < n; ++k) {
        if (s[k] == ')') {
            int j = next_open[k + 1];
            if (j != -1) {
                int B = bal[k] + 1; 
                
                int O = pref_open[n] - pref_open[j + 1];
                int C = pref_closed[n] - pref_closed[j + 1];

                if (C >= B) {
                    ll current_len = (k + 1) + B + 2LL * min(O, C - B);
                    max_len = max(max_len, current_len);
                }
            }
        }
    }

    cout << max_len << "\n";

}