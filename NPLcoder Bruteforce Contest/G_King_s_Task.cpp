<<<<<<< HEAD
#include <bits/stdc++.h>

using namespace std;

#define nl "\n"
#define all(x) x.begin(), x.end()
string yes = "YES", no = "NO";
typedef long long ll;

/* -----------------------selkie------------------------------*/

void op1(vector<int>& p, int n) {
    for (int i = 0; i < 2 * n; i += 2) {
        swap(p[i], p[i + 1]);
    }
}

void op2(vector<int>& p, int n) {
    for (int i = 0; i < n; ++i) {
        swap(p[i], p[i + n]);
    }
}

bool is_sorted(const vector<int>& p) {
    for (int i = 0; i < (int)p.size(); ++i) {
        if (p[i] != i + 1) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(0); 
    cout.tie(0);
    //input go BRrrr
    int n;
    if (!(cin >> n)) return 0;
    
    vector<int> p(2 * n);
    for (int i = 0; i < 2 * n; ++i) cin >> p[i];

    int min_ops = 2e9;

    for (int st = 0; st < 2; ++st) {
        vector<int> curr = p;
        if (is_sorted(curr)) {
            min_ops = 0;
            break;
        }

        for (int i = 1; i <= 2 * n; ++i) {
            if ((i % 2 == 1 && st == 0) || (i % 2 == 0 && st == 1)) {
                op1(curr, n);
            } else {
                op2(curr, n);
            }

            if (is_sorted(curr)) {
                min_ops = min(min_ops, i);
                break;
            }
        }
    }

    if (min_ops > 2 * n) {
        cout << -1 << nl;
    } else {
        cout << min_ops << nl;
    }

    return 0;
=======
#include <bits/stdc++.h>

using namespace std;

#define nl "\n"
#define all(x) x.begin(), x.end()
string yes = "YES", no = "NO";
typedef long long ll;

/* -----------------------selkie------------------------------*/

void op1(vector<int>& p, int n) {
    for (int i = 0; i < 2 * n; i += 2) {
        swap(p[i], p[i + 1]);
    }
}

void op2(vector<int>& p, int n) {
    for (int i = 0; i < n; ++i) {
        swap(p[i], p[i + n]);
    }
}

bool is_sorted(const vector<int>& p) {
    for (int i = 0; i < (int)p.size(); ++i) {
        if (p[i] != i + 1) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(0); 
    cout.tie(0);
    //input go BRrrr
    int n;
    if (!(cin >> n)) return 0;
    
    vector<int> p(2 * n);
    for (int i = 0; i < 2 * n; ++i) cin >> p[i];

    int min_ops = 2e9;

    for (int st = 0; st < 2; ++st) {
        vector<int> curr = p;
        if (is_sorted(curr)) {
            min_ops = 0;
            break;
        }

        for (int i = 1; i <= 2 * n; ++i) {
            if ((i % 2 == 1 && st == 0) || (i % 2 == 0 && st == 1)) {
                op1(curr, n);
            } else {
                op2(curr, n);
            }

            if (is_sorted(curr)) {
                min_ops = min(min_ops, i);
                break;
            }
        }
    }

    if (min_ops > 2 * n) {
        cout << -1 << nl;
    } else {
        cout << min_ops << nl;
    }

    return 0;
>>>>>>> f4a3ee5404bcb997bd906211f57ce621ed833c48
}