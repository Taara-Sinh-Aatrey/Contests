/**
 *    author:  Taara Sinh Aatrey
 *    created: 21.08.2022 09:04:22
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
        cout << "Case #" << tt << ": ";
        int n;
        cin >> n;
        cout << 1 + (n - 1) / 5 << '\n';
    }
    return 0;
}