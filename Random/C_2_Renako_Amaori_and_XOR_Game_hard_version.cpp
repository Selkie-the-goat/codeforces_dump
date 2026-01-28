
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; if(!(cin>>t)) return 0;
    while(t--){
        int n; cin>>n;
        vector<int>a(n), b(n);
        int A0=0, B0=0;
        for(int i=0;i<n;i++){ cin>>a[i]; A0 ^= a[i]; }
        for(int i=0;i<n;i++){ cin>>b[i]; B0 ^= b[i]; }

        if(A0 == B0){
            cout << "Tie\n";
            continue;
        }

        int X = A0 ^ B0;
        int K = 31 - __builtin_clz(X);  

        int r = -1;
        for(int i = n-1; i >= 0; --i){
            if( ((a[i] ^ b[i]) >> K) & 1 ){
                r = i + 1; 
                break;
            }
        }
        if(r % 2 == 1) cout << "Ajisai\n";
        else cout << "Mai\n";
    }
    return 0;
}
