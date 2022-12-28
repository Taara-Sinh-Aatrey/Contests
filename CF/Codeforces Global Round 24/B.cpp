/**
 *    author:  Taara Sinh Aatrey
 *    created: 01.12.2022 00:44:24
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
        int g = 0, mx = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            g = gcd(g, x);
            mx = max(mx, x);
        }
        cout << mx / g << '\n';
    }
    return 0;
}