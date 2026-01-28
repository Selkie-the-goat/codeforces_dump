<<<<<<< HEAD
#include <bits/stdc++.h>

using namespace std;

string yes = "YES", no = "NO";
typedef long long  ll;
// const MOD=

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
        cout <<endl;
    }

    return 0;
}
void solve()
{
    int n;
    string s;
    cin >> n ;
    cin >> s;
    if(s.find("2025")!= std::string::npos && s.find("2026")== std::string::npos)
    cout << 1 ;
    else
    cout << 0; 
=======
#include <bits/stdc++.h>

using namespace std;

string yes = "YES", no = "NO";
typedef long long  ll;
// const MOD=

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
        cout <<endl;
    }

    return 0;
}
void solve()
{
    int n;
    string s;
    cin >> n ;
    cin >> s;
    if(s.find("2025")!= std::string::npos && s.find("2026")== std::string::npos)
    cout << 1 ;
    else
    cout << 0; 
>>>>>>> f4a3ee5404bcb997bd906211f57ce621ed833c48
}