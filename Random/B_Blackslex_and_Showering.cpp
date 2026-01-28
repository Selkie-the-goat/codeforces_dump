#include <bits/stdc++.h>

using namespace std;

#define el "\n"
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(x) x.begin(), x.end()
string yes = "YES", no = "NO";
typedef long long  ll;
/* -----------------------COOKED.------------------------------*/

int main() {
    fastio;

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<ll> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];

        ll total_dist = 0;
        for(int i = 0; i < n - 1; i++) {
            total_dist += abs(a[i] - a[i+1]);
        }

        
        ll max_reduction = max(abs(a[0] - a[1]), abs(a[n-2] - a[n-1]));

        for(int k = 1; k < n - 1; k++) {
            ll current_segments = abs(a[k-1] - a[k]) + abs(a[k] - a[k+1]);
            ll new_segment = abs(a[k-1] - a[k+1]);
            ll reduction = current_segments - new_segment;
            
            max_reduction = max(max_reduction, reduction);
        }

        cout << total_dist - max_reduction << el;
    }

    return 0;
}