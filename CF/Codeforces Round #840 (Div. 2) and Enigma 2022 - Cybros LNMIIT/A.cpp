/**
 *    author:  Taara Sinh Aatrey
 *    created: 27.12.2022 16:04:02
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
        int OR = a[0], AND = a[0];
        for (int i = 1; i < n; i++) {
            OR |= a[i];
            AND &= a[i];
        }
        cout << OR - AND << '\n';
    }
    return 0;
}