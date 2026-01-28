#include <iostream>
#include <vector>
#include <algorithm>

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

    ll inv_m = modInverse(m, p);
    vector<ll> inv_m_pow(n + 1);
    inv_m_pow[0] = 1;
    for (int i = 1; i <= n; ++i) {
        inv_m_pow[i] = (inv_m_pow[i - 1] * inv_m) % p;
    }

    ll S_total = 0;
    ll correction_sum = 0;

    
    for (int c = 2; c <= 2 * n; ++c) {
        vector<ll> P;
        
        if (c % 2 == 0) {
            
            int center_idx = c / 2;
            int max_radius = min(center_idx - 1, n - center_idx); 
            
            for (int r = 0; r <= max_radius; ++r) {
                P.push_back(inv_m_pow[r]);
            }
        } else {
            
            int left_idx = c / 2;
            int right_idx = left_idx + 1;
            int max_radius = min(left_idx - 1, n - right_idx);
            
            for (int r = 0; r <= max_radius; ++r) {
                P.push_back(inv_m_pow[r + 1]);
            }
        }

        ll S_c = 0;
        ll V_c = 0;
        
        
        for (int i = 0; i < P.size(); ++i) {
            S_c = (S_c + P[i]) % p;
            ll coeff = (2 * i + 1); 
            V_c = (V_c + coeff * P[i]) % p;
        }


        S_total = (S_total + S_c) % p;
        
       
        ll term = (V_c - (S_c * S_c) % p + p) % p;
        correction_sum = (correction_sum + term) % p;
    }

    ll ans = (S_total * S_total) % p;
    ans = (ans + correction_sum) % p;

    cout << ans << endl;
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