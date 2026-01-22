#include <bits/stdc++.h>
using namespace std;

// flip bits from index l to r (1-based)
void flip(string &s, int l, int r) {
    for (int i = l - 1; i <= r - 1; ++i)
        s[i] = (s[i] == '0' ? '1' : '0');
}

// check if substring s[l..r] is palindrome (0-based)
bool is_palindrome(const string &s, int l, int r) {
    while (l < r) {
        if (s[l] != s[r]) return false;
        ++l; --r;
    }
    return true;
}

void solve() {
    int n; cin >> n;
    string s, t; cin >> s >> t;
    vector<pair<int,int>> ops;

    for (int i = n - 1; i >= 0; --i) {
        if (s[i] == t[i]) continue;

        // find a palindrome substring ending at i with length >= 2
        int l = 0; // start of the substring
        while (l < i && s[l] != s[i]) ++l;

        if (l == i) {
            cout << -1 << "\n"; // no palindrome found
            return;
        }

        // flip substring [l+1, i+1]
        ops.emplace_back(l+1, i+1);
        flip(s, l+1, i+1);
    }

    cout << ops.size() << "\n";
    for (auto &p : ops)
        cout << p.first << " " << p.second << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; cin >> T;
    while (T--) solve();
}
