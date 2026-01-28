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

void solve() {
    int n;
    // Read input from user
    if (!(std::cin >> n)) return;

    // Check if n is a power of 2 using bitwise AND
    // (n & (n - 1)) == 0 is true for powers of 2 (e.g., 2, 4, 8)
    if (n > 0 && (n & (n - 1)) == 0) {
        std::cout << "-1" << std::endl;
        return;
    }

    // Initialize a vector of size n + 1 with zeros
    std::vector<int> p(n + 1, 0);
    p[n] = n;

    for (int i = 1; i < n; ++i) {
        int val = i ^ n; // Bitwise XOR
        if (val <= n) {
            p[i] = val;
        } else {
            p[i] = i;
        }
    }

    // Output the permutation starting from index 1
    for (int i = 1; i <= n; ++i) {
        std::cout << p[i] << (i == n ? "" : " ");
    }
    std::cout << std::endl;
}