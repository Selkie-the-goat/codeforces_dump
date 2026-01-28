<<<<<<< HEAD
#include <bits/stdc++.h>

using namespace std;

#define nl "\n"
#define all(x) x.begin(), x.end();
string yes = "YES", no = "NO";
typedef long long  ll;

/* -----------------------selkie------------------------------*/
void solve();
int main() {
    ios::sync_with_stdio(false); 
    cin.tie(0); 
    cout.tie(0);
    //Input/Output go bRRRRRRRRR!!!!
    int t; cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

void solve() {
    int n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        sort(a.begin(), a.end());

        ll ans = LLONG_MIN;

        for (int x = 0; x <= 5; x++) {
            if (x > n || 5 - x > n) continue;

            ll prod = 1;
            bool valid = true;

            for (int i = 0; i < x; i++) {
                prod *= a[i];
            }

            for (int i = 0; i < 5 - x; i++) {
                int idx = n - 1 - i;
                if (idx < x) {
                    valid = false;
                    break;
                }
                prod *= a[idx];
            }

            if (valid) {
                ans = max(ans, prod);
            }
        }

        cout << ans << "\n";

=======
#include <bits/stdc++.h>

using namespace std;

#define nl "\n"
#define all(x) x.begin(), x.end();
string yes = "YES", no = "NO";
typedef long long  ll;

/* -----------------------selkie------------------------------*/
void solve();
int main() {
    ios::sync_with_stdio(false); 
    cin.tie(0); 
    cout.tie(0);
    //Input/Output go bRRRRRRRRR!!!!
    int t; cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

void solve() {
    int n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        sort(a.begin(), a.end());

        ll ans = LLONG_MIN;

        for (int x = 0; x <= 5; x++) {
            if (x > n || 5 - x > n) continue;

            ll prod = 1;
            bool valid = true;

            for (int i = 0; i < x; i++) {
                prod *= a[i];
            }

            for (int i = 0; i < 5 - x; i++) {
                int idx = n - 1 - i;
                if (idx < x) {
                    valid = false;
                    break;
                }
                prod *= a[idx];
            }

            if (valid) {
                ans = max(ans, prod);
            }
        }

        cout << ans << "\n";

>>>>>>> f4a3ee5404bcb997bd906211f57ce621ed833c48
}