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
    }
 
    return 0;
}
/*---------------------☆*: .｡. o(≧▽≦)o .｡.:*☆----------------------*/

void solve() {
    int n;
    cin >> n;
    vector<int> p(n+1);
    for(int i=1;i<=n;i++){
        cin >> p[i];
    }
    int start = 1;
        while (start <= n && p[start] == n - start + 1) {
            start++;
        }

        int target = n - start + 1;
        int pos = -1;
        for (int i = start; i <= n; i++) {
            if (p[i] == target) {
                pos = i;
                break;
            }
        }

        for (int i = 1; i < start; i++) {
            cout << p[i] << " ";
        }

        if (pos != -1) {
            for (int i = pos; i >= start; i--) {
                cout << p[i] << " ";
            }
            for (int i = pos + 1; i <= n; i++) {
                cout << p[i] << " ";
            }
        }

        cout << endl;
}