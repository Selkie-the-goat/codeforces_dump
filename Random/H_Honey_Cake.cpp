#include <bits/stdc++.h>
using namespace std;
/*---------------------Boring-stuff----------------------*/
string yes = "YES", no = "NO";
#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size()) 
#define all(a) (a).begin(), (a).end()
const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
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
/*---------------------☆*: .｡. o(≧▽≦)o .｡.:*☆----------------------*/

void solve() {
    long long w, h, d, n;
    cin >> w >> h >> d >> n;

    long long wp = gcd(n, w);
    n /= wp;

    long long hp = gcd(n, h);
    n /= hp;

    long long dp = gcd(n, d);
    n /= dp;

    if (n != 1) {
        cout << "-1" << endl;   
        return;
    }

    cout << (wp - 1) << " " << (hp - 1) << " " << (dp - 1) << endl;
}
