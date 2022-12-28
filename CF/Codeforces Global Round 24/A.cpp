/**
 *    author:  Taara Sinh Aatrey
 *    created: 01.12.2022 00:41:13
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
        for (auto &x : a) {
            cin >> x;
        }
        cout << 1 << " " << n << '\n';
    }
    return 0;
}