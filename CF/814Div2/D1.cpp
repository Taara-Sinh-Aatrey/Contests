/**
 *    author:  Taara Sinh Aatrey
 *    created: 16.08.2022 22:42:23
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
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        const int inf = 1e9 + 5;
        vector<int> dp(n, inf);
        for (int i = 0; i < n; i++) {
            int Xor = 0;
            for (int j = i; j >= 0; j--) {
                Xor ^= a[j];
                dp[i] = min(dp[i], (i - j + 1) + (Xor == 0 ? -1 : 0) + (j - 1 >= 0 ? dp[j - 1] : 0));
            }
        }
        cout << dp.back() << '\n';
    }
    return 0;
}