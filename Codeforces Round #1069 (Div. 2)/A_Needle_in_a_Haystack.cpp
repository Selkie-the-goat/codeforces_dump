<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        string s, tt;
        cin >> s >> tt;

        vector<int> cnt(26, 0);
        for (char c : tt) cnt[c - 'a']++;
        for (char c : s) cnt[c - 'a']--;

        bool ok = true;
        for (int i = 0; i < 26; i++)
            if (cnt[i] < 0)
                ok = false;

        if (!ok) {
            cout << "Impossible\n";
            continue;
        }


        string res = "";


        char first = s[0];

        for (int i = 0; i < first - 'a'; i++)
            while (cnt[i]--) res += char('a' + i);


        bool place_s_first = false;
        {
            string block(cnt[first - 'a'], first);
            string s2 = s;


            if (s < block) place_s_first = true;
        }

        if (place_s_first) {
            res += s;
            
            while (cnt[first - 'a']--) res += first;
        } else {
            
            while (cnt[first - 'a']--) res += first;
            
            res += s;
        }

      
        for (int i = first - 'a' + 1; i < 26; i++)
            while (cnt[i]--) res += char('a' + i);

        cout << res << "\n";
    }

    return 0;
}
=======
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        string s, tt;
        cin >> s >> tt;

        vector<int> cnt(26, 0);
        for (char c : tt) cnt[c - 'a']++;
        for (char c : s) cnt[c - 'a']--;

        bool ok = true;
        for (int i = 0; i < 26; i++)
            if (cnt[i] < 0)
                ok = false;

        if (!ok) {
            cout << "Impossible\n";
            continue;
        }


        string res = "";


        char first = s[0];

        for (int i = 0; i < first - 'a'; i++)
            while (cnt[i]--) res += char('a' + i);


        bool place_s_first = false;
        {
            string block(cnt[first - 'a'], first);
            string s2 = s;


            if (s < block) place_s_first = true;
        }

        if (place_s_first) {
            res += s;
            
            while (cnt[first - 'a']--) res += first;
        } else {
            
            while (cnt[first - 'a']--) res += first;
            
            res += s;
        }

      
        for (int i = first - 'a' + 1; i < 26; i++)
            while (cnt[i]--) res += char('a' + i);

        cout << res << "\n";
    }

    return 0;
}
>>>>>>> f4a3ee5404bcb997bd906211f57ce621ed833c48
