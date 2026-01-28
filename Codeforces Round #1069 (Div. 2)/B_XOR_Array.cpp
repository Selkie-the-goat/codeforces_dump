#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, l, r;
        cin >> n >> l >> r;

        vector<int> px(n + 1), a(n);

        px[0] = 0;
        for (int i = 1; i <= n; i++) {
            if (i == r) px[i] = l - 1;
            else px[i] = i;
        }

    
        for (int i = 1; i <= n; i++) {
            a[i - 1] = px[i] ^ px[i - 1];
            if (a[i - 1] == 0) a[i - 1] = 1; 
        }

        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << "\n";
    }
    return 0;
}
