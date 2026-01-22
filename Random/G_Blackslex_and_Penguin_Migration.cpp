#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// Interactive query wrapper
int ask(int u, int v) {
    if (u == v) return 0;
    cout << "? " << u << " " << v << endl;
    int dist;
    cin >> dist;
    return dist;
}

void solve() {
    int n;
    if (!(cin >> n)) return;
    
    int total_penguins = n * n;
    
    // Vectors sized N^2 + 1 to use 1-based indexing safely
    // 1. Find Corner A (The penguin furthest from penguin 1)
    vector<int> d1(total_penguins + 1);
    int cornerA = 1;
    int max_d1 = -1;
    
    for (int i = 1; i <= total_penguins; ++i) {
        if (i == 1) d1[i] = 0;
        else d1[i] = ask(1, i);
        
        if (d1[i] > max_d1) {
            max_d1 = d1[i];
            cornerA = i;
        }
    }
    
    // 2. Get distances from A (dA)
    // If penguin 1 was already the corner, reuse d1. Otherwise query A.
    vector<int> dA(total_penguins + 1);
    if (cornerA == 1) {
        dA = d1;
    } else {
        for (int i = 1; i <= total_penguins; ++i) {
            if (i == cornerA) dA[i] = 0;
            else if (i == 1) dA[i] = d1[cornerA]; // We know dist(1, A) from step 1
            else dA[i] = ask(cornerA, i);
        }
    }
    
    // 3. Identify Candidates for Corner B
    // Corner B is at distance (n-1) from Corner A (conceptually (1,1) to (1,n))
    vector<int> candidates;
    for (int i = 1; i <= total_penguins; ++i) {
        if (dA[i] == n - 1) {
            candidates.push_back(i);
        }
    }
    
    // 4. Find Corner B among candidates
    // Pick the first candidate as a probe. The candidate furthest from it is B.
    int cornerB = -1;
    int probe = -1;
    int dist_probe_B = -1;

    if (!candidates.empty()) {
        probe = candidates[0];
        int max_d_cand = -1;
        int best_cand = probe;
        
        // We only query other candidates against the probe
        for (size_t k = 0; k < candidates.size(); ++k) {
            int u = candidates[k];
            if (u == probe) continue; 
            
            int d = ask(probe, u);
            if (d > max_d_cand) {
                max_d_cand = d;
                best_cand = u;
            }
        }
        cornerB = best_cand;
        dist_probe_B = max_d_cand;
        if (cornerB == probe) dist_probe_B = 0;
    } else {
        // Fallback (should theoretically not happen for n >= 2)
        cornerB = (cornerA == 1 ? 2 : 1); 
    }
    
    // 5. Get distances from B (dB)
    vector<int> dB(total_penguins + 1);
    for (int i = 1; i <= total_penguins; ++i) {
        if (i == cornerB) dB[i] = 0;
        else if (i == cornerA) dB[i] = n - 1; // Known distance between corners
        else if (i == probe && dist_probe_B != -1) dB[i] = dist_probe_B; // Reuse dist found in step 4
        else dB[i] = ask(cornerB, i);
    }
    
    // 6. Reconstruct Grid
    // Eq 1: r + c = dA + 2
    // Eq 2: r - c = dB - n + 1
    vector<vector<int>> grid(n + 1, vector<int>(n + 1));
    
    for (int i = 1; i <= total_penguins; ++i) {
        int sum_rc = dA[i] + 2;
        int diff_rc = dB[i] - n + 1;
        
        int r = (sum_rc + diff_rc) / 2;
        int c = (sum_rc - diff_rc) / 2;
        
        // Bounds check to prevent any OOB access
        if (r >= 1 && r <= n && c >= 1 && c <= n) {
            grid[r][c] = i;
        }
    }
    
    cout << "!" << endl;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout << grid[i][j] << (j == n ? "" : " ");
        }
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while(t--) {
            solve();
        }
    }
    return 0;
}