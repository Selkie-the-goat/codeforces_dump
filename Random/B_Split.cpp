#include <bits/stdc++.h>

using namespace std;

#define el "\n"
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef ll int ll;

int main() {
    fastio;

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

       
        map<int, int> freq;
        for(int i = 0; i < 2 * n; i++){
            int x;
            cin >> x;
            freq[x]++;
        }

        int cnt_odd = 0;
        int cnt_even = 0;

        
        for (auto const& [val, count] : freq) {
            if (count % 2 != 0) {
                cnt_odd++;
            } else {
                cnt_even++;
            }
        }

       
        int ans = cnt_odd + 2 * cnt_even;

        
        if (cnt_odd == 0) {
            if (cnt_even % 2 != n % 2) {
                ans -= 2; 
            }
        }

        cout << ans << el;
    }
    return 0;
}