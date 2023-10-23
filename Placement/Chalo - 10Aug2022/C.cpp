#include "bits/stdc++.h"
using namespace std;

int solve() {
#define int int64_t
    const int mod = 1e9 + 7;
    int n, k, x;
    cin >> n >> k >> x;
    vector<vector<int>> dp(n, vector<int>(k, -1));
    dp[0] = vector<int>(k, 1);
    function<int(int, int)> recurse = [&] (int idx, int i) -> int {
        auto &cur = dp[idx][i];
        if (cur != -1) return cur;
        cur = 0;
        for (int j = 0; j < k; j++) {
            if (j != i) {
                cur += recurse(idx - 1, j);
            }
            else if (i == x - 1) {
                cur += recurse(idx - 1, j);
            }
            if (cur >= mod) cur -= mod;
        }
        return cur;
    };
    int ans = 0;
    for (int i = 0; i < k; i++) {
        ans += recurse(n - 1, i);
        if (ans >= mod) ans -= mod;
    }
    cout << ans << '\n';
#undef int
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}