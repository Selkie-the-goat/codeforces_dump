#include <bits/stdc++.h>

using namespace std;

#define el "\n"
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(x) x.begin(), x.end();
string yes = "YES", no = "NO";
typedef ll int ll;
/* -----------------------COOKED.------------------------------*/
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        int ans = 0;
        if (n > 0) {
            int pref_max = a[0];
            for (int j = 1; j < n; ++j) {
                if (a[j] < pref_max) ++ans;
                else pref_max = max(pref_max, a[j]);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}