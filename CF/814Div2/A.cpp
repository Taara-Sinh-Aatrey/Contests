/**
 *    author:  Taara Sinh Aatrey
 *    created: 16.08.2022 22:42:02
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
        dbg(n, m);
        cout << (n % 2 == m % 2 ? "Tonya" : "Burenka") << '\n';
    }
    return 0;
}