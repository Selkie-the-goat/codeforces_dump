<<<<<<< HEAD
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
    
    int k, l, m, n, d;
    cin >> k >> l >> m >> n >> d;

    int damaged = 0;

    for (int i = 1; i <= d; i++) {
        if (i % k == 0 || i % l == 0 || i % m == 0 || i % n == 0) {
            damaged++;
        }
    }

    cout << damaged << endl;
    
    return 0;
}
=======
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
    
    int k, l, m, n, d;
    cin >> k >> l >> m >> n >> d;

    int damaged = 0;

    for (int i = 1; i <= d; i++) {
        if (i % k == 0 || i % l == 0 || i % m == 0 || i % n == 0) {
            damaged++;
        }
    }

    cout << damaged << endl;
    
    return 0;
}
>>>>>>> f4a3ee5404bcb997bd906211f57ce621ed833c48
