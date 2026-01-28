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
    int n , s , x;
    cin >> n >> s >> x;
    int sum_a=0;
    set<int> elements;
    for(int i = 0 ;i < n ;i++){
        int temp;
        cin >> temp;
        sum_a += temp;
    }
    if (s - sum_a >= 0 && (s - sum_a) % x == 0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }

}