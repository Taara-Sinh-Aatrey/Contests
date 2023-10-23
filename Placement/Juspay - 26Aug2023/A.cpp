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
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &x : a) {
            cin >> x;
        }
        vector<int> sum(n);
        for (int i = 0; i < n; i++) {
            if (a[i] != -1) {
                sum[a[i]] += i;
            }
        }
        int ans = 0;
        for (int i = 1; i < n; i++) {
            if (sum[i] > sum[ans]) {
                ans = i;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}