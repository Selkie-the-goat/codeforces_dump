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
void solve()
{
    string s;
    cin >> s;
    int n = s.length();
    int sum = 0;
    int zeros = 0;
    int evens = 0;

    for (char c : s) {
        int digit = c - '0';
        sum += digit;
        if (digit == 0) zeros++;
        if (digit % 2 == 0) evens++;
    }
    if (zeros > 0 && evens >= 2 && sum % 3 == 0) {
        cout << "red" << endl; 
    } else {
        cout << "cyan" << endl; 
    }
    
}