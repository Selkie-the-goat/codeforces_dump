#include <bits/stdc++.h>

using namespace std;

#define el "\n"
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(x) x.begin(), x.end()
string yes = "YES", no = "NO";
typedef long long   ll;
/* -----------------------COOKED.------------------------------*/

int main() {
    fastio;

    int t; cin >> t;
    while (t--) {
        string s;
        cin >> s;
        
        int y_count = 0;
        for (char c : s) {
            if (c == 'Y') {
                y_count++;
            }
        }
        
        if (y_count <= 1) {
            cout << yes << el;
        } else {
            cout << no << el;
        }
    }

    return 0;
}