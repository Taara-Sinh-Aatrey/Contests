/**
 *    author:  Taara Sinh Aatrey
 *    created: 27.08.2022 21:30:21
**/

#include "bits/stdc++.h"

using namespace std;

#ifdef AATREY_DEBUG
#include "debug.hpp"
#else
#define dbg(...)
#endif

#define int int64_t

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    int len = 0;
    vector<int> lps(n + 10, 0);
    for (int i = 1; i < n; i++) {
        while (len > 0 && s[i] != s[len])
            len = lps[len - 1];
        if (s[i] == s[len]) 
            len++;
        lps[i] = len;
    }
    int save = len;
    int q;
    cin >> q;
    map<string, int> mp;
    while (q--) {
        string t;
        cin >> t;
        int m = t.size();
        len = save;
        string temp;
        for (int i = n; i < n + m; i++) {
            temp += t[i - n];
            if (mp.count(temp)) {
                len = mp[temp];
            }
            else {
                while (len > 0 && t[i - n] != (len < n ? s[len] : t[len - n]))
                    len = lps[len - 1];
                if (t[i - n] == (len < n ? s[len] : t[len - n])) 
                    len++;
                mp[temp] = len;
            }
            lps[i] = len;
            cout << lps[i] << " ";
        }
        cout << '\n';
    }
    return 0;
}