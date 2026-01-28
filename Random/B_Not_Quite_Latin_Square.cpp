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
    string a,b,c,str="ABC";
    cin >> a >> b >> c;
    
    for(int i=0;i<3;i++){
        if(a[i]=='?'){
        str.erase(std::remove(str.begin(), str.end(), b[i]), str.end());
        str.erase(std::remove(str.begin(), str.end(), c[i]), str.end());
        break;
        }
        if(b[i]=='?'){
        str.erase(std::remove(str.begin(), str.end(), a[i]), str.end());
        str.erase(std::remove(str.begin(), str.end(), c[i]), str.end());
        break;
        }
        if(c[i]=='?'){
        str.erase(std::remove(str.begin(), str.end(), b[i]), str.end());
        str.erase(std::remove(str.begin(), str.end(), a[i]), str.end());
        break;
        }
    }
    cout << str << endl;
}