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
    cin >> t;
    while (t--) {
        solve();
        cout << endl;
    }
 
    return 0;
}
/*---------------------☆*: .｡. o(≧▽≦)o .｡.:*☆----------------------*/

void solve() {
    ll n;
    cin >> n;
    ll digit= n;
    ll length= 1;
    ll count = 9;
    ll start = 1;
    while (digit > length * count) {
        digit -= length * count;
        length++;
        count *= 10;
        start *= 10;
    }
    ll number = start + (digit - 1) / length;
    ll pos = (digit - 1) % length;
    ll divisor = pow(10, length - pos - 1);
    int result = (number / divisor) % 10;
    cout << result;
}