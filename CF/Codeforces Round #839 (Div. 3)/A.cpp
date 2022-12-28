/**
 *    author:  Taara Sinh Aatrey
 *    created: 20.12.2022 08:01:36
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
        char a, b;
        cin >> a >> b >> b;
        cout << a - '0' + b - '0' << '\n';
    }
    return 0;
}