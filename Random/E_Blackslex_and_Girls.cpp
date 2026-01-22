#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    int n;
    ll x, y;
    if (!(cin >> n >> x >> y)) return;
    string s;
    cin >> s;
    vector<ll> p(n);
    
    ll min_x = 0;
    ll min_y = 0;
    ll total_p = 0;
    int count0 = 0, count1 = 0;

    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        total_p += p[i];
        if (s[i] == '0') {
            count0++;
            min_x += (p[i] / 2) + 1;
        } else {
            count1++;
            min_y += (p[i] / 2) + 1;
        }
    }

    bool possible = true;
    
    if (x < min_x || y < min_y) possible = false;
    
    if (x + y < total_p) possible = false;
    
    if (count1 == 0 && x < y + n) possible = false;
    if (count0 == 0 && y < x + n) possible = false;

    if (possible) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}