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
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }

    for (int i = 0; i < n; ++i) {
        if (p[i] == i + 1) {
            continue;
        } 
        else if (p[i] == i + 2) {
            if (i + 1 < n && p[i+1] == i + 1) {
                i++;
            } else {
                cout << "NO" << endl;
                return;
            }
        } 
        else {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
}