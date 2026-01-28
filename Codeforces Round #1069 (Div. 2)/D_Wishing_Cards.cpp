<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;

typedef ll ll;

const ll INF_SCORE = -1;
const int INF_IDX = 1e9;

int nxt[100005][365];
ll dp[365][365];
int min_idx[365][365];

void solve() {
    int n, k;
    if (!(cin >> n >> k)) return;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int v = 0; v <= k; v++) {
        nxt[n][v] = INF_IDX;
    }

    for (int i = n - 1; i >= 0; i--) {
        for (int v = 0; v <= k; v++) {
            if (a[i] >= v) {
                nxt[i][v] = i;
            } else {
                nxt[i][v] = nxt[i + 1][v];
            }
        }
    }

    for (int c = 0; c <= k; c++) {
        for (int v = 0; v <= k; v++) {
            dp[c][v] = INF_SCORE;
            min_idx[c][v] = INF_IDX;
        }
    }

    dp[0][0] = 0;
    min_idx[0][0] = -1;

    ll ans = 0;

    for (int c = 0; c <= k; c++) {
        for (int v = 0; v <= c; v++) {
            if (dp[c][v] == INF_SCORE) continue;

            int current_idx = min_idx[c][v];
            ll current_score = dp[c][v];
            
            ans = max(ans, current_score);

            int limit = k - c;
            
            for (int nv = v + 1; nv <= limit; nv++) {
                int next_i = nxt[current_idx + 1][nv];
                
                if (next_i >= n) continue;

                ll gain = (ll)(nv - v) * (n - next_i);
                ll new_score = current_score + gain;
                int new_c = c + nv;
                
                if (new_score > dp[new_c][nv]) {
                    dp[new_c][nv] = new_score;
                    min_idx[new_c][nv] = next_i;
                } else if (new_score == dp[new_c][nv]) {
                    if (next_i < min_idx[new_c][nv]) {
                        min_idx[new_c][nv] = next_i;
                    }
                }
            }
        }
    }

    for(int c=0; c<=k; ++c) {
        for(int v=0; v<=c; ++v) {
            ans = max(ans, dp[c][v]);
        }
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    
    return 0;
=======
#include <bits/stdc++.h>
using namespace std;

typedef ll ll;

const ll INF_SCORE = -1;
const int INF_IDX = 1e9;

int nxt[100005][365];
ll dp[365][365];
int min_idx[365][365];

void solve() {
    int n, k;
    if (!(cin >> n >> k)) return;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int v = 0; v <= k; v++) {
        nxt[n][v] = INF_IDX;
    }

    for (int i = n - 1; i >= 0; i--) {
        for (int v = 0; v <= k; v++) {
            if (a[i] >= v) {
                nxt[i][v] = i;
            } else {
                nxt[i][v] = nxt[i + 1][v];
            }
        }
    }

    for (int c = 0; c <= k; c++) {
        for (int v = 0; v <= k; v++) {
            dp[c][v] = INF_SCORE;
            min_idx[c][v] = INF_IDX;
        }
    }

    dp[0][0] = 0;
    min_idx[0][0] = -1;

    ll ans = 0;

    for (int c = 0; c <= k; c++) {
        for (int v = 0; v <= c; v++) {
            if (dp[c][v] == INF_SCORE) continue;

            int current_idx = min_idx[c][v];
            ll current_score = dp[c][v];
            
            ans = max(ans, current_score);

            int limit = k - c;
            
            for (int nv = v + 1; nv <= limit; nv++) {
                int next_i = nxt[current_idx + 1][nv];
                
                if (next_i >= n) continue;

                ll gain = (ll)(nv - v) * (n - next_i);
                ll new_score = current_score + gain;
                int new_c = c + nv;
                
                if (new_score > dp[new_c][nv]) {
                    dp[new_c][nv] = new_score;
                    min_idx[new_c][nv] = next_i;
                } else if (new_score == dp[new_c][nv]) {
                    if (next_i < min_idx[new_c][nv]) {
                        min_idx[new_c][nv] = next_i;
                    }
                }
            }
        }
    }

    for(int c=0; c<=k; ++c) {
        for(int v=0; v<=c; ++v) {
            ans = max(ans, dp[c][v]);
        }
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    
    return 0;
>>>>>>> f4a3ee5404bcb997bd906211f57ce621ed833c48
}