#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;


ll get_max_subarray_sum(int n, const vector<ll>& a) {
    ll max_so_far = LLONG_MIN;
    ll current_max = 0;
    
  
    ll max_element = LLONG_MIN;
    
    for (ll x : a) {
        max_element = max(max_element, x);
        current_max = current_max + x;
        if (max_so_far < current_max)
            max_so_far = current_max;
        if (current_max < 0)
            current_max = 0;
    }
    
    

    current_max = a[0];
    max_so_far = a[0];
    for(int i = 1; i < n; i++) {
        current_max = max(a[i], current_max + a[i]);
        max_so_far = max(max_so_far, current_max);
    }
    
    return max_so_far;
}

void solve() {
    int n;
    ll k;
    cin >> n >> k;
    
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    vector<ll> b(n);
    for (int i = 0; i < n; i++) cin >> b[i];
    
 
    ll original_mss = get_max_subarray_sum(n, a);
    

    if (k % 2 == 0) {
        cout << original_mss << "\n";
        return;
    }
  
    vector<ll> pref(n);
    pref[0] = a[0];
    for(int i = 1; i < n; i++) {
        pref[i] = max(a[i], pref[i-1] + a[i]);
    }

    vector<ll> suff(n);
    suff[n-1] = a[n-1];
    for(int i = n - 2; i >= 0; i--) {
        suff[i] = max(a[i], suff[i+1] + a[i]);
    }
    
    ll max_odd_mss = original_mss;
    
    for(int i = 0; i < n; i++) {
        
        ll current_boosted = pref[i] + suff[i] - a[i] + b[i];
        max_odd_mss = max(max_odd_mss, current_boosted);
    }
    
    cout << max_odd_mss << "\n";
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
}