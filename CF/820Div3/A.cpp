/**
 *    author:  Taara Sinh Aatrey
 *    created: 12.09.2022 23:39:29
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
        int a, b, c;
        cin >> a >> b >> c;
        int t1 = a - 1;
        int t2 = c < b ? b - 1 : c - b + c - 1;
        cout << (t1 < t2 ? 1 : (t1 > t2 ? 2 : 3)) << '\n';
    }
    return 0;
}