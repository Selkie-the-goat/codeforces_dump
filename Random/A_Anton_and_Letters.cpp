#include <bits/stdc++.h>
 
using namespace std;
 
#define nl "\n"
#define all(x) x.begin(), x.end();
string yes = "YES", no = "NO";
typedef long long  ll;
 
/* -----------------------selkie------------------------------*/
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    getline(cin, s);

    set<char> st;
    for (char c : s) {
        if (c >= 'a' && c <= 'z') {
            st.insert(c);
        }
    }

    cout << st.size() << "\n";
    return 0;
}