#include <bits/stdc++.h>

using namespace std;

string yes = "YES", no = "NO";
#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size()) 
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
    
    // Input/Output go bRRRRRRRRR!!!!
    int t = 1; 
    // cin >> t; 
    while (t--) {
        solve();
    }

    return 0;
}

void solve()
{
    int n, a, x, b, y;
    cin >> n >> a >> x >> b >> y;

    while (true) {
        a++;
        if (a > n) a = 1;

        b--;
        if (b < 1) b = n;


        if (a == b) {
            cout << yes << "\n";
            return;
        }

        
        if (a == x || b == y) {
            break;
        }
    }

    cout << no << "\n";
}