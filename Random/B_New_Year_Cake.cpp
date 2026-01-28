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
    }

    return 0;
}
void solve()
{
    int a,b;
    cin >> a >> b;
    if(b>a){
        swap(a,b);
    }
    int ctr=1;
    int x=0,y=0,ans=0;
    while(true){
        int temp=x;
        x=y+ctr;
        y=temp;
        if( x<=a && y<=b){
            ans++;
            ctr *=2;
        }
        else break;
    }
    cout << ans << endl;
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
    }

    return 0;
}
void solve()
{
    int a,b;
    cin >> a >> b;
    if(b>a){
        swap(a,b);
    }
    int ctr=1;
    int x=0,y=0,ans=0;
    while(true){
        int temp=x;
        x=y+ctr;
        y=temp;
        if( x<=a && y<=b){
            ans++;
            ctr *=2;
        }
        else break;
    }
    cout << ans << endl;
>>>>>>> f4a3ee5404bcb997bd906211f57ce621ed833c48
}