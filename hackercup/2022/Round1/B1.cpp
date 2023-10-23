/**
 *    author:  Taara Sinh Aatrey
 *    created: 11.09.2022 16:10:20
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
        cout << "Case #" << tt << ": ";
        int n;
        cin >> n;
        vector<int> X(n), Y(n);
        for (int i = 0; i < n; i++) {
            cin >> X[i] >> Y[i];
        }
        const int inf = 1e18L + 5;
        const int N = 3e3;
        const int mod = 1e9 + 7;
        auto fun = [&] (vector<int> &a, vector<int> &b) {
            for (int x = 0; x <= N; x++) {
                int d = 0;
                for (int i = 0; i < n; i++) {
                    d += (a[i] - x) * (a[i] - x) % mod;
                    d %= mod;
                }
                b[x] = d;
            }
        };
        vector<int> XD(N + 1), YD(N + 1);
        fun(X, XD);
        fun(Y, YD);
        int q;
        cin >> q;
        int ans = 0;
        while (q--) {
            int x, y;
            cin >> x >> y;
            ans += XD[x] + YD[y];
            ans %= mod;
        }
        cout << ans << '\n';
    }
    return 0;
}