/**
 *    author:  Taara Sinh Aatrey
 *    created: 25.12.2022 16:10:23
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
    int a, b;
    cin >> a >> b;
    int p = 1;
    while (b--) {
        p *= a;
    }
    cout << p;
    return 0;
}