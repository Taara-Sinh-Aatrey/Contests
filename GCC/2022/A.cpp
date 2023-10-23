/**
 *    author:  Taara Sinh Aatrey
 *    created: 20.10.2022 19:48:07
**/

#include "bits/stdc++.h"

using namespace std;

#ifdef AATREY_DEBUG
#include "debug.hpp"
#else
#define dbg(...)
#endif

signed main() {
    int64_t num;
    scanf("%lld", &num);
    cout << (num & 1 ? "SELL" : (num & 2 ? "PASS" : "BUY"));
    return 0;
}


