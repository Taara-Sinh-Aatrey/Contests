/**
 *    author:  Taara Sinh Aatrey
 *    created: 04.01.2023 23:16:07
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
    int testcases;
    cin >> testcases;
    for (int caseno = 1; caseno <= testcases; caseno++) {
        int n;
        string s;
        cin >> n >> s;
        int ans = -1;
        for (int i = 0; i + 1 < n; i++) {
            if (s[i] != s[i + 1]) {
                ans = s[i] == 'R' ? 0 : i + 1;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}