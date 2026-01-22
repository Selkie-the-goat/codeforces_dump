#include <bits/stdc++.h>

using namespace std;

#define el "\n"
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(x) x.begin(), x.end();
string yes = "YES", no = "NO";
typedef ll int ll;
/* -----------------------COOKED.------------------------------*/
vector<int> divisors(int n) {
    vector<int> d;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            d.push_back(i);
            if (i != n / i) d.push_back(n / i);
        }
    }
    sort(d.begin(), d.end());
    return d;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        if (count(s.begin(), s.end(), '1') == n) {
            cout << 0 << "\n";
            continue;
        }

        vector<int> divs = divisors(n);
        ll best = LLONG_MAX;

        for (int d : divs) {
            int m = n / d;
            bool ok = true;
            int maxNeeded = 0;

            for (int r = 0; r < d; r++) {
                vector<int> cycle(m);
                bool hasOne = false;

                for (int k = 0; k < m; k++) {
                    cycle[k] = (s[r + k * d] == '1');
                    if (cycle[k]) hasOne = true;
                }

                if (!hasOne) { 
                    ok = false;
                    break;
                }

                // find max consecutive zeros in circular cycle
                int bestCycle = 0, cur = 0;

                for (int i = 0; i < 2 * m; i++) {
                    if (cycle[i % m] == 0) {
                        cur++;
                    } else {
                        bestCycle = max(bestCycle, cur);
                        cur = 0;
                    }
                }
                bestCycle = max(bestCycle, cur);
                bestCycle = min(bestCycle, m);

                maxNeeded = max(maxNeeded, bestCycle);
            }

            if (ok) {
                best = min(best, 1LL * d * maxNeeded);
            }
        }

        cout << best << "\n";
    }
}