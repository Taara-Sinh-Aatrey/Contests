/**
 *    author:  Taara Sinh Aatrey
 *    created: 01.09.2022 16:35:26
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
    int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int slope = a[0] < a[1];
        int Xor = 0;
        for (int i = 0, j; i < n - 1; i = j) {
            j = i;
            while (j + 1 < n && (a[j] < a[j + 1]) == slope) {
                j++;
            }
            Xor ^= (j - i - 1);
            slope ^= 1;
        }
        cout << (Xor != 0 ? "Alice" : "Bob") << '\n';
    }
    return 0;
}