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
    int a, b, c;
    cin >> a >> b >> c;

    int ans = INT_MAX;

    for (int da = -1; da <= 1; da++) {
        for (int db = -1; db <= 1; db++) {
            for (int dc = -1; dc <= 1; dc++) {
                int A = a + da;
                int B = b + db;
                int C = c + dc;

                int tpd = abs(A - B) + abs(A - C) + abs(B - C);
                ans = min(ans, tpd);
            }
        }
    }

    cout << ans << nl;
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
    int a, b, c;
    cin >> a >> b >> c;

    int ans = INT_MAX;

    for (int da = -1; da <= 1; da++) {
        for (int db = -1; db <= 1; db++) {
            for (int dc = -1; dc <= 1; dc++) {
                int A = a + da;
                int B = b + db;
                int C = c + dc;

                int tpd = abs(A - B) + abs(A - C) + abs(B - C);
                ans = min(ans, tpd);
            }
        }
    }

    cout << ans << nl;
>>>>>>> f4a3ee5404bcb997bd906211f57ce621ed833c48
}