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
    int t; cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

ll power(ll base, ll exp) {
    ll res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

ll modInverse(ll n) { return power(n, MOD - 2); }

ll nCr_mod(ll n, ll r, const vector<ll>& fact, const vector<ll>& invFact) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
}

ll get_vp(ll n, ll p) {
    ll res = 0;
    while (n >= p) { res += n / p; n /= p; }
    return res;
}

void solve() {
    int n; ll c;
    cin >> n >> c;
    string s;
    cin >> s;
    s = " " + s;

    if (s[1] == '0' || s[n] == '0' || c == 1) {
        cout << -1 << "\n";
        return;
    }

    vector<int> K;
    for (int i = 1; i < n; ++i) if (s[i] == '1') K.push_back(i);
    
    vector<int> next_one(n + 1);
    int last = n;
    for (int i = n; i >= 1; --i) {
        next_one[i] = last;
        if (s[i] == '1') last = i;
    }

    vector<ll> fact(n + 1, 1), invFact(n + 1, 1);
    for (int i = 1; i <= n; i++) fact[i] = (fact[i - 1] * i) % MOD;
    invFact[n] = modInverse(fact[n]);
    for (int i = n - 1; i >= 1; i--) invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;

    ll res_mod = power(2, K.size());
    map<ll, ll> vp_total;
    auto add_val = [&](ll val, int sign) {
        if (val <= 0) return;
        ll temp = c;
        for (ll i = 2; i * i <= temp; i++) {
            if (temp % i == 0) {
                ll count = 0, v = val;
                while (v % i == 0) { count++; v /= i; }
                vp_total[i] += sign * count;
                while (temp % i == 0) temp /= i;
            }
        }
        if (temp > 1) {
            ll count = 0, v = val;
            while (v % temp == 0) { count++; v /= temp; }
            vp_total[temp] += sign * count;
        }
    };

    auto add_fact = [&](ll val, int sign) {
        ll temp = c;
        for (ll i = 2; i * i <= temp; i++) {
            if (temp % i == 0) {
                vp_total[i] += sign * get_vp(val, i);
                while (temp % i == 0) temp /= i;
            }
        }
        if (temp > 1) vp_total[temp] += sign * get_vp(val, temp);
    };

    add_val(power(2, K.size()) == 0 ? 0 : 2, K.size()); // Simplification for power of 2
    if(K.size() > 0) {
        ll p2 = K.size();
        ll temp_c = c;
        if(temp_c % 2 == 0) {
            ll cnt = 0; while(temp_c % 2 == 0) { temp_c /= 2; cnt++; }
            vp_total[2] += p2;
        }
    }

    for (int i = 1; i < n; i++) {
        if (s[i] == '0') {
            res_mod = res_mod * (next_one[i] - i) % MOD;
            add_val(next_one[i] - i, 1);
        }
    }

    vector<pair<int, int>> fixed;
    fixed.push_back({0, 1});
    for (int i = 0; i < K.size(); i++) {
        if (K[i] + 1 < next_one[K[i]]) fixed.push_back({i + 1, next_one[K[i]]});
    }
    fixed.push_back({(int)K.size(), n});

    for (int i = 0; i < (int)fixed.size() - 1; i++) {
        int idx_diff = fixed[i + 1].first - fixed[i].first;
        int span_diff = fixed[i + 1].second - fixed[i].second;
        if (idx_diff > 1) {
            res_mod = res_mod * nCr_mod(span_diff - 1, idx_diff - 1, fact, invFact) % MOD;
            add_fact(span_diff - 1, 1);
            add_fact(idx_diff - 1, -1);
            add_fact(span_diff - idx_diff, -1);
        }
    }

    bool div = true;
    ll temp_c = c;
    for (ll i = 2; i * i <= temp_c; i++) {
        if (temp_c % i == 0) {
            ll req = 0; while (temp_c % i == 0) { req++; temp_c /= i; }
            if (vp_total[i] < req) div = false;
        }
    }
    if (temp_c > 1 && vp_total[temp_c] < 1) div = false;

    if (div) cout << -1 << "\n";
    else cout << res_mod << "\n";
}