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
    int t=1; 
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
void solve()
{
    int al, ar, bl, br;

    cin >> al >> ar;
    cin >> bl >> br;

   
    bool case1 = (br >= al - 1) && (br <= 2 * al + 2);

    bool case2 = (bl >= ar - 1) && (bl <= 2 * ar + 2);

    if (case1 || case2) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

}