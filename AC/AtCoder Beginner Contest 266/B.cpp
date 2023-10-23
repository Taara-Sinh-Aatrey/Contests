/**
 *    author:  Taara Sinh Aatrey
 *    created: 27.08.2022 17:32:40
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
    int n;
    cin >> n;
    const int mod = 998244353;
    n %= mod;
    if (n < 0) n += mod;
    cout << n;
    return 0;
}