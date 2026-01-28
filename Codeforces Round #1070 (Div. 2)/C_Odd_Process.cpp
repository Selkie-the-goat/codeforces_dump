<<<<<<< HEAD
#include <bits/stdc++.h>

using namespace std;

#define el "\n"
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(x) x.begin(), x.end();
string yes = "YES", no = "NO";
typedef ll int ll;
/* -----------------------COOKED.------------------------------*/



using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    vector<ll> evens;
    vector<ll> odds;
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] % 2 == 0) {
            evens.push_back(a[i]);
        } else {
            odds.push_back(a[i]);
        }
    }
    
    if (odds.empty()) {
        for (int k = 1; k <= n; ++k) {
            cout << 0 << (k == n ? "" : " ");
        }
        cout << "\n";
        return;
    }
    
    sort(evens.rbegin(), evens.rend());
    sort(odds.rbegin(), odds.rend());
    
    int cnt_even = evens.size();
    vector<ll> pref_even(cnt_even + 1, 0);
    for (int i = 0; i < cnt_even; ++i) {
        pref_even[i + 1] = pref_even[i] + evens[i];
    }
    
    ll max_odd = odds[0];
    int avail_odds = (int)odds.size() - 1; 
    
    for (int k = 1; k <= n; ++k) {
        int moves_needed = k - 1;
        
        
        int L = max(0, moves_needed - cnt_even);
        
        ll current_ans = 0;
        
        if (L % 2 == 0) {
           
            if (L <= avail_odds) {
               
                int evens_in_bag = moves_needed - L;
                current_ans = max_odd + pref_even[evens_in_bag];
            } else {
                current_ans = 0;
            }
        } else {
            
            int L_adjusted = L + 1;
            
            if (L_adjusted <= avail_odds) {
            
                int evens_in_bag = moves_needed - L_adjusted;
                
                if (evens_in_bag >= 0) {
                    current_ans = max_odd + pref_even[evens_in_bag];
                } else {
                    current_ans = 0;
                }
            } else {
                current_ans = 0;
            }
        }
        
        cout << current_ans << (k == n ? "" : " ");
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
=======
#include <bits/stdc++.h>

using namespace std;

#define el "\n"
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(x) x.begin(), x.end();
string yes = "YES", no = "NO";
typedef ll int ll;
/* -----------------------COOKED.------------------------------*/



using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    vector<ll> evens;
    vector<ll> odds;
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] % 2 == 0) {
            evens.push_back(a[i]);
        } else {
            odds.push_back(a[i]);
        }
    }
    
    if (odds.empty()) {
        for (int k = 1; k <= n; ++k) {
            cout << 0 << (k == n ? "" : " ");
        }
        cout << "\n";
        return;
    }
    
    sort(evens.rbegin(), evens.rend());
    sort(odds.rbegin(), odds.rend());
    
    int cnt_even = evens.size();
    vector<ll> pref_even(cnt_even + 1, 0);
    for (int i = 0; i < cnt_even; ++i) {
        pref_even[i + 1] = pref_even[i] + evens[i];
    }
    
    ll max_odd = odds[0];
    int avail_odds = (int)odds.size() - 1; 
    
    for (int k = 1; k <= n; ++k) {
        int moves_needed = k - 1;
        
        
        int L = max(0, moves_needed - cnt_even);
        
        ll current_ans = 0;
        
        if (L % 2 == 0) {
           
            if (L <= avail_odds) {
               
                int evens_in_bag = moves_needed - L;
                current_ans = max_odd + pref_even[evens_in_bag];
            } else {
                current_ans = 0;
            }
        } else {
            
            int L_adjusted = L + 1;
            
            if (L_adjusted <= avail_odds) {
            
                int evens_in_bag = moves_needed - L_adjusted;
                
                if (evens_in_bag >= 0) {
                    current_ans = max_odd + pref_even[evens_in_bag];
                } else {
                    current_ans = 0;
                }
            } else {
                current_ans = 0;
            }
        }
        
        cout << current_ans << (k == n ? "" : " ");
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
>>>>>>> f4a3ee5404bcb997bd906211f57ce621ed833c48
}