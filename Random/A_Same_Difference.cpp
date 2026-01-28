<<<<<<< HEAD
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
        string s;
        int n;
        cin >> n >> s;
        int maxm = 0;
        for (char p : s) {
            if (s[n-1]!=p) {
                maxm ++;
            }
        }
        cout << maxm << el;
    }

    return 0;
}

=======
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
        string s;
        int n;
        cin >> n >> s;
        int maxm = 0;
        for (char p : s) {
            if (s[n-1]!=p) {
                maxm ++;
            }
        }
        cout << maxm << el;
    }

    return 0;
}

>>>>>>> f4a3ee5404bcb997bd906211f57ce621ed833c48
