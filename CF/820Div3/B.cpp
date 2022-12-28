/**
 *    author:  Taara Sinh Aatrey
 *    created: 12.09.2022 24:02:26
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
    int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        int n;
        cin >> n;
        string t;
        cin >> t;
        string s;
        int i = n - 1;
        while (i >= 0) {
            int len = 1;
            if (t[i] == '0') {
                i--;
                len = 2;
            }
            s += char('a' + stoi(t.substr(i - len + 1, len)) - 1);
            i -= len;
        }
        reverse(s.begin(), s.end());
        cout << s << '\n';
    }
    return 0;
}