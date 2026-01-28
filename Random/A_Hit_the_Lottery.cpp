#include <bits/stdc++.h>

using namespace std;

string yes = "YES", no = "NO";
typedef long long  ll;

/* -----------------------selkie------------------------------*/
int solve(int);
int main() {
    ios::sync_with_stdio(false); 
    cin.tie(0); 
    cout.tie(0);
    //Input/Output go bRRRRRRRRR!!!!
    int t; cin >> t;
    cout << solve(t) << endl;

    return 0;
}
int solve(int n)
{
    if(n>=100){
        return n / 100 + solve(n%100); 
    }else if(n<100 && n>=20){
        return n / 20 + solve(n%20); 
    }else if(n<20 && n>=10){
        return n / 10 + solve(n%10); 
    }else if(n<10 && n>=5){
        return n / 5 + solve(n%5); 
    }else if(n<5 && n>=1){
        return n; 
    }else{
        return 0;
    }
}