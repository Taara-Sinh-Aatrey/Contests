/**
 *    author:  Taara Sinh Aatrey
 *    created: 25.12.2022 16:11:45
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
    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
    }
    int q;
    cin >> q;
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int k, x;
            cin >> k >> x, --k;
            a[k] = x;
        }
        else {
            int k;
            cin >> k, --k;
            cout << a[k] << '\n';
        }
    }
    return 0;
}