#include <bits/stdc++.h>

using namespace std;

#define el "\n"
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(x) x.begin(), x.end();
string yes = "YES", no = "NO";
typedef ll int ll;
/* -----------------------COOKED.------------------------------*/

int main() {
    fastio;

    int t; cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int y , r;
        cin >> y >> r;
        cout << min(n, r + y/2) << el;
    }

    return 0;
}

