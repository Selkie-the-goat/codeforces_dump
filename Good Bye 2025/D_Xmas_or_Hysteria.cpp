<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;
struct Elf {
    long long a;
    int id; 
};
bool compareElf(const Elf& a, const Elf& b) {
    return a.a < b.a;
}
void solve() {
    int n;
    long long m;
    cin >> n >> m;
    vector<Elf> elves(n);
    for (int i = 0; i < n; ++i) {
        cin >> elves[i].a;
        elves[i].id = i + 1;
    }
    sort(elves.begin(), elves.end(), compareElf);
    if (m == 1) {
        cout << n - 1 << "\n";
        for (int i = 0; i < n - 1; ++i) {
            cout << elves[i].id << " " << elves[i+1].id << "\n";
        }
        return;
    }
    if (m > 1) {
        if (n < 2 * m) {
            cout << "-1\n";
            return;
        }
        cout << n - m << "\n";
        for (int i = 0; i < n - 2 * m; ++i) {
            cout << elves[i].id << " " << elves[i+1].id << "\n";
        }
        for (int i = 0; i < m; ++i) {
            int victim_idx = n - 2 * m + i;
            int survivor_idx = n - m + i;
            cout << elves[survivor_idx].id << " " << elves[victim_idx].id << "\n";
        }
        return;
    }
    if (m == 0) {
        long long total_attack = 0;
        for(int i=0; i<n-1; ++i) total_attack += elves[i].a;
        if (total_attack < elves[n-1].a) {
            cout << "-1\n";
            return;
        }
        long long current_sum = 0;
        int k = -1;
        for (int i = n - 2; i >= 0; --i) {
            current_sum += elves[i].a;
            if (current_sum >= elves[n-1].a) {
                k = i;
                break;
            }
        }
        if (k == -1) {
            cout << "-1\n";
            return;
        }
        cout << n << "\n"; 
        for (int i = 0; i < k; ++i) {
            cout << elves[i].id << " " << elves[i+1].id << "\n";
        }
        for (int i = k + 1; i < n - 1; ++i) {
            cout << elves[i].id << " " << elves[n-1].id << "\n";
        }
        cout << elves[k].id << " " << elves[n-1].id << "\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
=======
#include <bits/stdc++.h>
using namespace std;
struct Elf {
    long long a;
    int id; 
};
bool compareElf(const Elf& a, const Elf& b) {
    return a.a < b.a;
}
void solve() {
    int n;
    long long m;
    cin >> n >> m;
    vector<Elf> elves(n);
    for (int i = 0; i < n; ++i) {
        cin >> elves[i].a;
        elves[i].id = i + 1;
    }
    sort(elves.begin(), elves.end(), compareElf);
    if (m == 1) {
        cout << n - 1 << "\n";
        for (int i = 0; i < n - 1; ++i) {
            cout << elves[i].id << " " << elves[i+1].id << "\n";
        }
        return;
    }
    if (m > 1) {
        if (n < 2 * m) {
            cout << "-1\n";
            return;
        }
        cout << n - m << "\n";
        for (int i = 0; i < n - 2 * m; ++i) {
            cout << elves[i].id << " " << elves[i+1].id << "\n";
        }
        for (int i = 0; i < m; ++i) {
            int victim_idx = n - 2 * m + i;
            int survivor_idx = n - m + i;
            cout << elves[survivor_idx].id << " " << elves[victim_idx].id << "\n";
        }
        return;
    }
    if (m == 0) {
        long long total_attack = 0;
        for(int i=0; i<n-1; ++i) total_attack += elves[i].a;
        if (total_attack < elves[n-1].a) {
            cout << "-1\n";
            return;
        }
        long long current_sum = 0;
        int k = -1;
        for (int i = n - 2; i >= 0; --i) {
            current_sum += elves[i].a;
            if (current_sum >= elves[n-1].a) {
                k = i;
                break;
            }
        }
        if (k == -1) {
            cout << "-1\n";
            return;
        }
        cout << n << "\n"; 
        for (int i = 0; i < k; ++i) {
            cout << elves[i].id << " " << elves[i+1].id << "\n";
        }
        for (int i = k + 1; i < n - 1; ++i) {
            cout << elves[i].id << " " << elves[n-1].id << "\n";
        }
        cout << elves[k].id << " " << elves[n-1].id << "\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
>>>>>>> f4a3ee5404bcb997bd906211f57ce621ed833c48
}