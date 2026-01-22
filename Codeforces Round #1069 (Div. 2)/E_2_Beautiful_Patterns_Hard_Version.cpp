#include <bits/stdc++.h>

using namespace std;

ll power(ll base, ll exp, ll mod) {
    ll res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

ll modInverse(ll n, ll mod) {
    return power(n, mod - 2, mod);
}

void solve() {
    int n;
    ll m, p;
    cin >> n >> m >> p;

    if (m == 1) {
        ll v = (ll)n * (n + 1) / 2;
        v %= p;
        cout << (v * v) % p << "\n";
        return;
    }

    ll inv_m = modInverse(m, p);
    
    vector<ll> q_pow(n + 2); 
    q_pow[0] = 1;
    for (int i = 1; i <= n + 1; ++i) {
        q_pow[i] = (q_pow[i - 1] * inv_m) % p;
    }

    ll inv_1_minus_q = modInverse((1 - inv_m + p) % p, p);

    ll S1 = 0; 
    ll S2 = 0; 
    ll S3 = 0; 

    vector<ll> vp_odd(n + 1);
    for (int k = 0; k <= n; ++k) {
        ll term = (2LL * k + 1);
        term %= p; 
        term = (term * q_pow[k]) % p;
        if (k > 0) vp_odd[k] = (vp_odd[k - 1] + term) % p;
        else vp_odd[k] = term;
    }

    for (int i = 1; i <= n; ++i) {
        int k = min(i - 1, n - i); 
        
        ll num = (1 - q_pow[k + 1] + p) % p;
        ll E = (num * inv_1_minus_q) % p;

        S1 = (S1 + E) % p;
        S2 = (S2 + (E * E) % p) % p;
        S3 = (S3 + vp_odd[k]) % p;
    }

    vector<ll> vp_even(n + 1);
    for (int k = 1; k <= n; ++k) {
        ll term = (2LL * k - 1);
        term %= p;
        term = (term * q_pow[k]) % p;
        vp_even[k] = (vp_even[k - 1] + term) % p;
    }

    for (int i = 1; i < n; ++i) {
        int k = min(i, n - i); 
        if (k == 0) continue; 

        ll num = (1 - q_pow[k] + p) % p;
        ll E = (num * inv_1_minus_q) % p;
        E = (E * inv_m) % p;

        S1 = (S1 + E) % p;
        S2 = (S2 + (E * E) % p) % p;
        S3 = (S3 + vp_even[k]) % p;
    }

    ll ans = (S1 * S1) % p;
    ans = (ans - S2 + p) % p;
    ans = (ans + S3) % p;

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}