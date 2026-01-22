#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int &x : a) cin >> x;

        set<int> S(a.begin(), a.end());
        int k = S.size();

        int ans = INT_MAX;
        for(int x : S)
            if(x >= k) ans = min(ans, x);

        cout << ans << "\n";
    }
    return 0;
}
