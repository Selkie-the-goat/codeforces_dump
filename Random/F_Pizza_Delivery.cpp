#include <bits/stdc++.h>

using namespace std;

string yes = "YES", no = "NO";
#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size()) //haha probably won't even use(┬┬﹏┬┬)
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

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
void solve()
{
    int n;
    ll Ax, Ay, Bx, By;
    cin >> n >> Ax >> Ay >> Bx >> By;

    vector<ll> x(n), y(n);
    for (int i = 0; i < n; i++) cin >> x[i];
    for (int i = 0; i < n; i++) cin >> y[i];

    vector<pair<ll,ll>> pts(n);
    for (int i = 0; i < n; i++) pts[i] = {x[i], y[i]};
    sort(pts.begin(), pts.end()); 

    ll dp_low = 0, dp_high = 0;
    ll cur_low = Ay, cur_high = Ay;

    for (int i = 0; i < n; ) {
        int j = i;
        ll lo = pts[i].second, hi = pts[i].second;

        while (j < n && pts[j].first == pts[i].first) {
            lo = min(lo, pts[j].second);
            hi = max(hi, pts[j].second);
            j++;
        }

        ll span = hi - lo;

        ll new_low = min(
            dp_low  + llabs(cur_low  - hi),
            dp_high + llabs(cur_high - hi)
        ) + span;

        ll new_high = min(
            dp_low  + llabs(cur_low  - lo),
            dp_high + llabs(cur_high - lo)
        ) + span;

        dp_low = new_low;
        dp_high = new_high;
        cur_low = lo;
        cur_high = hi;

        i = j;
    }

    ll vertical = min(
        dp_low  + llabs(cur_low  - By),
        dp_high + llabs(cur_high - By)
    );

    ll ans = (Bx - Ax + vertical) % MOD;
    cout << ans << '\n';
}
