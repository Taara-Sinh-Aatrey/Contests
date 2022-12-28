/**
 *    author:  Taara Sinh Aatrey
 *    created: 17.09.2022 16:01:39
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
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        cout << max_element(a.begin(), a.end()) - a.begin() + 1 << '\n';
    }
    return 0;
}