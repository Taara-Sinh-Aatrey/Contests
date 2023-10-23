/**
 *    author:  Taara Sinh Aatrey
 *    created: 20.10.2022 20:33:19
**/

#include "bits/stdc++.h"

using namespace std;

#ifdef AATREY_DEBUG
#include "debug.hpp"
#else
#define dbg(...)
#endif

signed main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int64_t mx = -1e18L;
    bool ok = true;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        if (mx > x) {
            if (x + mx > m) {
                ok = false;
            }
        }
        else {
            mx = x;
        }
    }
    cout << ok << '\n';
    return 0;
}