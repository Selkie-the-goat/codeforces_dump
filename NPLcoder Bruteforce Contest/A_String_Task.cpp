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
    string s;
    cin >> s;
    strlwr(s);
    for(char aa:s){
        if(aa!='u'&& aa!='o'&& aa!='i'&& aa!='e'&& aa!='a'){
            cout<< "." << tolower(aa);
        }
    }
    cout << endl;
    return 0;
}
