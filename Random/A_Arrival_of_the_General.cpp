<<<<<<< HEAD
#include <bits/stdc++.h>

using namespace std;

string yes = "YES", no = "NO";
typedef long long  ll;
// const MOD=

/* -----------------------selkie------------------------------*/
int main() {
    ios::sync_with_stdio(false); 
    cin.tie(0); 
    cout.tie(0);
    //Input/Output go bRRRRRRRRR!!!!
    
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int mx = *max_element(a.begin(), a.end());
    int mn = *min_element(a.begin(), a.end());

    int posMax = -1;
    int posMin = -1;

    for (int i = 0; i < n; i++) {
        if (a[i] == mx) {
            posMax = i;
            break;
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        if (a[i] == mn) {
            posMin = i;
            break;
        }
    }

    int ans = posMax + (n - 1 - posMin);
    if (posMax > posMin) ans--;

    cout << ans << '\n';
    return 0;
=======
#include <bits/stdc++.h>

using namespace std;

string yes = "YES", no = "NO";
typedef long long  ll;
// const MOD=

/* -----------------------selkie------------------------------*/
int main() {
    ios::sync_with_stdio(false); 
    cin.tie(0); 
    cout.tie(0);
    //Input/Output go bRRRRRRRRR!!!!
    
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int mx = *max_element(a.begin(), a.end());
    int mn = *min_element(a.begin(), a.end());

    int posMax = -1;
    int posMin = -1;

    for (int i = 0; i < n; i++) {
        if (a[i] == mx) {
            posMax = i;
            break;
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        if (a[i] == mn) {
            posMin = i;
            break;
        }
    }

    int ans = posMax + (n - 1 - posMin);
    if (posMax > posMin) ans--;

    cout << ans << '\n';
    return 0;
>>>>>>> f4a3ee5404bcb997bd906211f57ce621ed833c48
}