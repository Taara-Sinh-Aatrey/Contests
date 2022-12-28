/**
 *    author:  Taara Sinh Aatrey
 *    created: 28.12.2022 13:36:23
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
        vector<int> a(n);
        int ans = 1;
        for (auto &x : a) {
            cin >> x;
            ans *= x;
        }
        ans += n - 1;
        ans *= 2022;
        cout << ans << '\n';
    }
    return 0;
}