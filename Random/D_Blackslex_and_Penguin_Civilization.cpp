#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;

    int size = 1 << n;
    vector<bool> used(size, false);
    vector<int> p;

    int cur_mask = size - 1;
    p.push_back(cur_mask);
    used[cur_mask] = true;

    for (int b = n - 1; b >= 0; --b) {
        int target_mask = cur_mask ^ (1 << b);
        for (int x = 0; x < size; ++x) {
            if (!used[x] && (x & target_mask) == target_mask) {
                p.push_back(x);
                used[x] = true;
            }
        }
        cur_mask = target_mask;
    }

    for (int i = 0; i < size; ++i) {
        cout << p[i] << (i == size - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}