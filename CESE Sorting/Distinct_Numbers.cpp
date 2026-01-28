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
    int n;
    cin >> n;
    set<int> a;
    for (int i=0 ;i<n;i++){
        int temp;
        cin >> temp;
        a.insert(temp);
    }
    cout << a.size() << endl;
    return 0;
}