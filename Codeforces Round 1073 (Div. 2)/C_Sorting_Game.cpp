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
void solve()
{
   int n;
    cin >> n;
    string s;
    cin >> s;

    if (is_sorted(s.begin(), s.end())) {
        cout << "Bob" << endl;
        return;
    }

    int total_zeros = 0;
    for (char c : s) {
        if (c == '0') total_zeros++;
    }

    vector<int> indices;
    for (int i = 0; i < total_zeros; ++i) {
        if (s[i] == '1') {
            indices.push_back(i + 1); 
        }
    }
    for (int i = total_zeros; i < n; ++i) {
        if (s[i] == '0') {
            indices.push_back(i + 1);
        }
    }

    cout << "Alice" << endl;
    cout << indices.size()<<endl;
    for (int idx : indices) {
        cout << " " << idx;
    }
    cout << endl; 
}