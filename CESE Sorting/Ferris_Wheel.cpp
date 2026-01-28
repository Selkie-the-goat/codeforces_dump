#include <bits/stdc++.h>

using namespace std;

string yes = "YES", no = "NO";
typedef long long  ll;

/* -----------------------selkie------------------------------*/
void solve();
int main() {
    ios::sync_with_stdio(false); 
    cin.tie(0); 
    cout.tie(0);
    //Input/Output go bRRRRRRRRR!!!!
    ll n,x;
    cin >> n>> x;
    vector<ll> weight(n);
    for(ll i=0;i<n;i++) cin >> weight[i];
    sort(weight.begin(),weight.end());
    ll i=0,j=n-1,ct=0;
    while(j>=i){
        int su=weight[i]+weight[j];
        if(su<=x){
            ct++;
            i++;
            j--;
        }
        else if(su>x){
            ct++;
            j--;
        }

    }


    cout << ct << endl;
    return 0;
}