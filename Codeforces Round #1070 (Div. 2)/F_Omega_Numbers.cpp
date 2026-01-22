#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;
const int MAXN = 200005;

int omega[MAXN];
int cnt[MAXN];
int dp[MAXN][28]; 

long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

void precompute() {
    for (int i = 2; i < MAXN; ++i) {
        if (omega[i] == 0) { 
            for (int j = i; j < MAXN; j += i) {
                omega[j]++;
            }
        }
    }
}

vector<pair<int, int>> pair_map;
void init_pairs() {
    for(int i = 0; i <= 6; ++i) {
        for(int j = i; j <= 6; ++j) {
            pair_map.push_back({i, j});
        }
    }
}

void solve() {
    int n;
    long long k;
    if (!(cin >> n >> k)) return;

    for (int i = 1; i <= n; ++i) cnt[i] = 0;
    
    for (int i = 0; i < n; ++i) {
        int x; 
        cin >> x;
        cnt[x]++;
    }

    vector<long long> pow_k(15);
    for(int i = 0; i < 15; ++i) pow_k[i] = binpow(i, k);

    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j < 28; ++j) dp[i][j] = 0;
    }

    long long ans = 0;

    for (int g = n; g >= 1; --g) {
        int total_mult = 0;
        int freq[7] = {0};
        
        for (int j = g; j <= n; j += g) {
            if (cnt[j]) {
                freq[omega[j]] += cnt[j];
                total_mult += cnt[j];
            }
        }

        if (total_mult < 2) continue;

        long long subs[28] = {0};
        for (int j = 2 * g; j <= n; j += g) {
            for(int p = 0; p < 28; ++p) {
                subs[p] += dp[j][p];
            }
        }

        for (int p_idx = 0; p_idx < 28; ++p_idx) {
            int c1 = pair_map[p_idx].first;
            int c2 = pair_map[p_idx].second;
            
            long long ways = 0;
            if (c1 == c2) {
                long long c = freq[c1];
                ways = c * (c - 1) / 2;
            } else {
                ways = (long long)freq[c1] * freq[c2];
            }
            ways %= MOD;

            long long exact = (ways - (subs[p_idx] % MOD) + MOD) % MOD;
            
            dp[g][p_idx] = exact;

            if (exact > 0) {
                int val = c1 + c2 - omega[g];
                ans = (ans + exact * pow_k[val]) % MOD;
            }
        }
    }
    
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    precompute();
    init_pairs();
    
    int t; 
    if (cin >> t) {
        while(t--) {
            solve();
        }
    }
    return 0;
}