<<<<<<< HEAD
#include <bits/stdc++.h>

using namespace std;

#define el "\n"
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(x) x.begin(), x.end()
typedef long long ll;
/* -----------------------COOKED.------------------------------*/

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(all(a));

    int option1 = a[0];

    int option2 = a[1] - a[0];

    cout << max(option1, option2) << el;
}

int main() {
    fastio;

    int t; 
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
=======
#include <bits/stdc++.h>

using namespace std;

#define el "\n"
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(x) x.begin(), x.end()
typedef long long ll;
/* -----------------------COOKED.------------------------------*/

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(all(a));

    int option1 = a[0];

    int option2 = a[1] - a[0];

    cout << max(option1, option2) << el;
}

int main() {
    fastio;

    int t; 
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
>>>>>>> f4a3ee5404bcb997bd906211f57ce621ed833c48
}