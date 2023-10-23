/**
 *    author:  Taara Sinh Aatrey
 *    created: 23.01.2023 00:53:08
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
        for (auto &x : a) {
            cin >> x;
        }
        int ans = 0;
        for (int i = 0, j; i < n; i = j) {
            j = i;
            while (j < n && a[i] % 2 == a[j] % 2) {
                j++;
            }
            ans += j - i - 1;
        }
        cout << ans << '\n';
    }
    return 0;
}