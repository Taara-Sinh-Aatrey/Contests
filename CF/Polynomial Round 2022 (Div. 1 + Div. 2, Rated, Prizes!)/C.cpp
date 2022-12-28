/**
 *    author:  Taara Sinh Aatrey
 *    created: 18.12.2022 02:49:49
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
        cin >> n;
        string s;
        cin >> s;
        vector<int> c(2);
        for (int p = 2; p <= n; p++) {
            c[s[p - 2] - '0'] = max(c[s[p - 2] - '0'], p - 1);
            cout << c[1 - (s[p - 2] - '0')] + 1 << " \n"[p == n];
        }
    }
    return 0;
}