/**
 *    author:  Taara Sinh Aatrey
 *    created: 25.12.2022 16:13:56
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
    int ans = n;
    for (int i = 0, j; i < n; i = j) {
        j = i;
        while (j < n && s[j] == s[i]) {
            j++;
        }
        if (s[i] == '0') {
            ans -= (j - i) / 2;
        }
    }
    cout << ans;
    return 0;
}