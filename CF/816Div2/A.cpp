/**
 *    author:  Taara Sinh Aatrey
 *    created: 20.08.2022 20:10:20
**/

#include "bits/stdc++.h"

using namespace std;

#ifdef AATREY_DEBUG
#include "debug.hpp"
#else
#define dbg(...)
#endif

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        int n, m;
        cin >> n >> m;
        cout << (n + m - 2) * 2 - max<int>(0, (max(n, m) - 2)) << '\n';
    }
    return 0;
}