#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;

        vector<int> cnt(26, 0);
        for (char c : t) cnt[c - 'a']++;
        
        // Check if possible
        vector<int> need(26, 0);
        for (char c : s) need[c - 'a']++;
        
        bool possible = true;
        for (int i = 0; i < 26; i++) {
            if (need[i] > cnt[i]) {
                possible = false;
                break;
            }
        }
        
        if (!possible) {
            cout << "Impossible\n";
            continue;
        }

        vector<int> extra(26, 0);
        for (int i = 0; i < 26; i++) {
            extra[i] = cnt[i] - need[i];
        }

        string result;
        int sIdx = 0;
        

        while (sIdx < (int)s.size() || accumulate(extra.begin(), extra.end(), 0) > 0) {
            bool placed = false;
            

            for (int ch = 0; ch < 26; ch++) {
                if (extra[ch] > 0) {
     
                    if (sIdx >= (int)s.size() || ch < (s[sIdx] - 'a')) {
                        result += char('a' + ch);
                        extra[ch]--;
                        placed = true;
                        break;
                    }
                }
            }
            
            if (!placed && sIdx < (int)s.size()) {
                result += s[sIdx];
                sIdx++;
            }
        }

        cout << result << "\n";
    }
    return 0;
}