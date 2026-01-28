<<<<<<< HEAD
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int p1 = -1, pn = -1;
    vector<bool> present(n + 1, false);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] != 0) present[a[i]] = true;
        if (a[i] == 1) p1 = i;
        if (a[i] == n) pn = i;
    }

    int L = min(p1, pn);
    int R = max(p1, pn);
    
    // Values that are NOT 1 or N and NOT fixed in the array 'a'
    // These are the "free" values we can use to fill 0s.
    int free_vals = 0;
    for (int v = 2; v < n; v++) {
        if (!present[v]) free_vals++;
    }

    long long ans = 1;
    const int MOD = 998244353;

    // We process values from the "outside" in: 2 and n-1, then 3 and n-2...
    // Or more simply: Expand the range [L, R] until it covers [0, n-1]
    int current_val_low = 2;
    int current_val_high = n - 1;

    while (L > 0 || R < n - 1) {
        int choices = 0;
        if (L > 0) choices++;
        if (R < n - 1) choices++;

        // If both sides are 0, we have 'choices' positions to place 
        // a value, but we must account for the available free values.
        if (L > 0 && R < n - 1 && a[L - 1] == 0 && a[R + 1] == 0) {
            // We have 2 slots, and we can pick any 2 of the remaining free_vals
            // to fill them. One will be the median.
            // The formula for this specific expansion step:
            ans = ans * (free_vals * 2 - 1) % MOD;
            free_vals -= 2;
            L--; R++;
        } else {
            // One or both sides are fixed, or we are at an edge.
            if (L > 0) {
                if (a[L - 1] != 0) {
                    // Fixed value: no choice, just reduce range
                } else {
                    // It's a 0, but the other side is either fixed or blocked
                    ans = ans * 1 % MOD; // Only one way to maintain distinct medians
                    free_vals--;
                }
                L--;
            } else if (R < n - 1) {
                if (a[R + 1] != 0) {
                    // Fixed
                } else {
                    ans = ans * 1 % MOD;
                    free_vals--;
                }
                R++;
            }
        }
    }

    // If we used more values than available or logic failed
    if (free_vals < 0) return 0;
    
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) cout << solve() << "\n";
    return 0;
=======
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int p1 = -1, pn = -1;
    vector<bool> present(n + 1, false);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] != 0) present[a[i]] = true;
        if (a[i] == 1) p1 = i;
        if (a[i] == n) pn = i;
    }

    int L = min(p1, pn);
    int R = max(p1, pn);
    
    // Values that are NOT 1 or N and NOT fixed in the array 'a'
    // These are the "free" values we can use to fill 0s.
    int free_vals = 0;
    for (int v = 2; v < n; v++) {
        if (!present[v]) free_vals++;
    }

    long long ans = 1;
    const int MOD = 998244353;

    // We process values from the "outside" in: 2 and n-1, then 3 and n-2...
    // Or more simply: Expand the range [L, R] until it covers [0, n-1]
    int current_val_low = 2;
    int current_val_high = n - 1;

    while (L > 0 || R < n - 1) {
        int choices = 0;
        if (L > 0) choices++;
        if (R < n - 1) choices++;

        // If both sides are 0, we have 'choices' positions to place 
        // a value, but we must account for the available free values.
        if (L > 0 && R < n - 1 && a[L - 1] == 0 && a[R + 1] == 0) {
            // We have 2 slots, and we can pick any 2 of the remaining free_vals
            // to fill them. One will be the median.
            // The formula for this specific expansion step:
            ans = ans * (free_vals * 2 - 1) % MOD;
            free_vals -= 2;
            L--; R++;
        } else {
            // One or both sides are fixed, or we are at an edge.
            if (L > 0) {
                if (a[L - 1] != 0) {
                    // Fixed value: no choice, just reduce range
                } else {
                    // It's a 0, but the other side is either fixed or blocked
                    ans = ans * 1 % MOD; // Only one way to maintain distinct medians
                    free_vals--;
                }
                L--;
            } else if (R < n - 1) {
                if (a[R + 1] != 0) {
                    // Fixed
                } else {
                    ans = ans * 1 % MOD;
                    free_vals--;
                }
                R++;
            }
        }
    }

    // If we used more values than available or logic failed
    if (free_vals < 0) return 0;
    
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) cout << solve() << "\n";
    return 0;
>>>>>>> f4a3ee5404bcb997bd906211f57ce621ed833c48
}