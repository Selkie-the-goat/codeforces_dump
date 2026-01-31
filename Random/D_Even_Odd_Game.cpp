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

        vector<long long> even, odd;
        for (int i = 0; i < n; i++) {
            long long x;
            cin >> x;
            if (x % 2 == 0) even.push_back(x);
            else odd.push_back(x);
        }

        sort(even.rbegin(), even.rend());
        sort(odd.rbegin(), odd.rend());

        long long alice = 0, bob = 0;
        int i = 0, j = 0; 

        for (int turn = 0; turn < n; turn++) {
            if (turn % 2 == 0) {
                if (i < even.size() && (j >= odd.size() || even[i] >= odd[j])) {
                    alice += even[i++];
                } else {
                    j++; 
                }
            } else {
                if (j < odd.size() && (i >= even.size() || odd[j] >= even[i])) {
                    bob += odd[j++];
                } else {
                    i++; 
                }
            }
        }

        if (alice > bob) cout << "Alice\n";
        else if (bob > alice) cout << "Bob\n";
        else cout << "Tie\n";
    }