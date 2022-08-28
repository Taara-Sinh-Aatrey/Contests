/**
 *    author:  Taara Sinh Aatrey
 *    created: 21.08.2022 23:52:34
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
    int Xor = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        Xor ^= x;
    }
    cout << (!!Xor);
    return 0;
}