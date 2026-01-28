<<<<<<< HEAD
#include <bits/stdc++.h>

using namespace std;

#define nl "\n"
#define all(x) x.begin(), x.end()
string yes = "YES", no = "NO";
typedef long long ll;

const int MOD = 998244353;

struct Pair {
    ll count;
    ll slen;
};

/* -----------------------selkie------------------------------*/
void solve();

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(0); 
    cout.tie(0);
    //input go BRrrr
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

void solve()
{
    int n; cin >> n;
    string s; cin >> s;

    vector<Pair> dp_all(n + 2, {0, 0});
    dp_all[0] = {1, 0};

    for (char c : s) {
        vector<Pair> next = dp_all;
        if (c == '(') {
            for (int j = 0; j <= n; j++) {
                next[j + 1].count = (next[j + 1].count + dp_all[j].count) % MOD;
                next[j + 1].slen = (next[j + 1].slen + dp_all[j].slen + dp_all[j].count) % MOD;
            }
        } else {
            for (int j = 1; j <= n; j++) {
                next[j - 1].count = (next[j - 1].count + dp_all[j].count) % MOD;
                next[j - 1].slen = (next[j - 1].slen + dp_all[j].slen + dp_all[j].count) % MOD;
            }
        }
        dp_all = next;
    }

    ll total_pot = (dp_all[0].slen - 2 * (dp_all[0].count - 1) % MOD + MOD) % MOD;

    
    vector<vector<Pair>> dp_zero(n + 2, vector<Pair>(3, {0, 0}));
    dp_zero[0][0] = {1, 0};

    for (char c : s) {
        vector<vector<Pair>> next = dp_zero;
        if (c == '(') {
            for (int j = 0; j <= n; j++) {
                next[j + 1][0].count = (next[j + 1][0].count + dp_zero[j][0].count) % MOD;
                next[j + 1][0].slen = (next[j + 1][0].slen + dp_zero[j][0].slen + dp_zero[j][0].count) % MOD;
                
                next[j + 1][2].count = (next[j + 1][2].count + dp_zero[j][1].count) % MOD;
                next[j + 1][2].slen = (next[j + 1][2].slen + dp_zero[j][1].slen + dp_zero[j][1].count) % MOD;
                
            }
        } else {
            for (int j = 1; j <= n; j++) {
                next[j - 1][1].count = (next[j - 1][1].count + dp_zero[j][0].count) % MOD;
                next[j - 1][1].slen = (next[j - 1][1].slen + dp_zero[j][0].slen + dp_zero[j][0].count) % MOD;
                
                next[j - 1][1].count = (next[j - 1][1].count + dp_zero[j][1].count) % MOD;
                next[j - 1][1].slen = (next[j - 1][1].slen + dp_zero[j][1].slen + dp_zero[j][1].count) % MOD;
                
                next[j - 1][2].count = (next[j - 1][2].count + dp_zero[j][2].count) % MOD;
                next[j - 1][2].slen = (next[j - 1][2].slen + dp_zero[j][2].slen + dp_zero[j][2].count) % MOD;
            }
        }
        dp_zero = next;
    }

    ll zero_pot = 0;
    for (int st = 1; st <= 2; st++) {
        ll term = (dp_zero[0][st].slen - 2 * dp_zero[0][st].count % MOD + MOD) % MOD;
        zero_pot = (zero_pot + term) % MOD;
    }

    cout << (total_pot - zero_pot + MOD) % MOD << nl;
=======
#include <bits/stdc++.h>

using namespace std;

#define nl "\n"
#define all(x) x.begin(), x.end()
string yes = "YES", no = "NO";
typedef long long ll;

const int MOD = 998244353;

struct Pair {
    ll count;
    ll slen;
};

/* -----------------------selkie------------------------------*/
void solve();

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(0); 
    cout.tie(0);
    //input go BRrrr
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

void solve()
{
    int n; cin >> n;
    string s; cin >> s;

    vector<Pair> dp_all(n + 2, {0, 0});
    dp_all[0] = {1, 0};

    for (char c : s) {
        vector<Pair> next = dp_all;
        if (c == '(') {
            for (int j = 0; j <= n; j++) {
                next[j + 1].count = (next[j + 1].count + dp_all[j].count) % MOD;
                next[j + 1].slen = (next[j + 1].slen + dp_all[j].slen + dp_all[j].count) % MOD;
            }
        } else {
            for (int j = 1; j <= n; j++) {
                next[j - 1].count = (next[j - 1].count + dp_all[j].count) % MOD;
                next[j - 1].slen = (next[j - 1].slen + dp_all[j].slen + dp_all[j].count) % MOD;
            }
        }
        dp_all = next;
    }

    ll total_pot = (dp_all[0].slen - 2 * (dp_all[0].count - 1) % MOD + MOD) % MOD;

    
    vector<vector<Pair>> dp_zero(n + 2, vector<Pair>(3, {0, 0}));
    dp_zero[0][0] = {1, 0};

    for (char c : s) {
        vector<vector<Pair>> next = dp_zero;
        if (c == '(') {
            for (int j = 0; j <= n; j++) {
                next[j + 1][0].count = (next[j + 1][0].count + dp_zero[j][0].count) % MOD;
                next[j + 1][0].slen = (next[j + 1][0].slen + dp_zero[j][0].slen + dp_zero[j][0].count) % MOD;
                
                next[j + 1][2].count = (next[j + 1][2].count + dp_zero[j][1].count) % MOD;
                next[j + 1][2].slen = (next[j + 1][2].slen + dp_zero[j][1].slen + dp_zero[j][1].count) % MOD;
                
            }
        } else {
            for (int j = 1; j <= n; j++) {
                next[j - 1][1].count = (next[j - 1][1].count + dp_zero[j][0].count) % MOD;
                next[j - 1][1].slen = (next[j - 1][1].slen + dp_zero[j][0].slen + dp_zero[j][0].count) % MOD;
                
                next[j - 1][1].count = (next[j - 1][1].count + dp_zero[j][1].count) % MOD;
                next[j - 1][1].slen = (next[j - 1][1].slen + dp_zero[j][1].slen + dp_zero[j][1].count) % MOD;
                
                next[j - 1][2].count = (next[j - 1][2].count + dp_zero[j][2].count) % MOD;
                next[j - 1][2].slen = (next[j - 1][2].slen + dp_zero[j][2].slen + dp_zero[j][2].count) % MOD;
            }
        }
        dp_zero = next;
    }

    ll zero_pot = 0;
    for (int st = 1; st <= 2; st++) {
        ll term = (dp_zero[0][st].slen - 2 * dp_zero[0][st].count % MOD + MOD) % MOD;
        zero_pot = (zero_pot + term) % MOD;
    }

    cout << (total_pot - zero_pot + MOD) % MOD << nl;
>>>>>>> f4a3ee5404bcb997bd906211f57ce621ed833c48
}