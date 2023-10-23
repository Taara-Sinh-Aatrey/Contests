#include "bits/stdc++.h"

using namespace std;

#ifdef AATREY_DEBUG
#include "debug.hpp"
#else
#define dbg(...)
#endif

#define int int64_t

const int mod = 1e9 + 7;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int testcases;
    cin >> testcases;
    for (int caseno = 1; caseno <= testcases; caseno++) {
        int n;
        cin >> n;
        vector<int> a(n);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            for (int j = 0; j < i; j++) {
                if (gcd(a[i], a[j]) == 1) {
                    ans += a[i] * a[j] % mod;
                    ans %= mod;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}