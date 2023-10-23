/**
 *    author:  Taara Sinh Aatrey
 *    created: 18.03.2023 14:00:50
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
        int a, b;
        cin >> a >> b;
        cout << (a == b ? "YES" : "NO") << '\n';
    }
    return 0;
}