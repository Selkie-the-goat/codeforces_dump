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
    int t; cin >> t;
    int count=0;
    for(int i=0;i<t;i++){
        string temp;
        cin >> temp;
        if(temp=="Tetrahedron")
        count+=4;
        else if(temp=="Cube")
        count += 6;
        else if(temp=="Octahedron")
        count += 8;
        else if(temp=="Dodecahedron")
        count += 12;
        else if(temp=="Icosahedron")
        count += 20;

    }
    cout << count <<endl;
    return 0;
}
