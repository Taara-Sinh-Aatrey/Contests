#include "bits/stdc++.h"
using namespace std;

#define int int64_t
const int inf = 1e18L + 5, mod = 1e9 + 7, N = 2e5 + 5;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
    }
    vector<int> sum(1 << n);
    for (int mask = 0; mask < 1 << n; mask++) {
        int msk = mask;
        while (msk > 0) {
            int j = __builtin_ctzll(msk);
            sum[mask] += a[j];
            msk ^= 1 << j;
        }
    }
    int ans = 0;
    for (int mask1 = 1; mask1 < (1 << n) - 1; mask1++) {
        int remaining_mask = ((1 << n) - 1) ^ mask1;
        for (int mask2 = remaining_mask; mask2 > 0; mask2 = remaining_mask & (mask2 - 1)) {
            ans += sum[mask1] == sum[mask2];
        }
    }
    cout << ans / 2 << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
