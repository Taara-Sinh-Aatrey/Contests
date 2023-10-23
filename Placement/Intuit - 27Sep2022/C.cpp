#include "bits/stdc++.h"
using namespace std;

signed main() {
#define int int64_t
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    n++;
    auto read_mask = [&] () {
        int sz;
        cin >> sz;
        int mask = 0;
        for (int i = 0; i < sz; i++) {
            int x;
            cin >> x;
            mask |= 1 << x;
        }
        return mask;
    };
    int required = read_mask();
    int have = read_mask();
    const int inf = 1e18L + 5;
    vector<int> dp(1 << n, inf);
    for (int submask = have; submask > 0; submask = (submask - 1) & have) {
        dp[submask] = 0;
    }
    vector<int> costs(m);
    for (int i = 0; i < m; i++) {
        cin >> costs[i];
    }
    vector<int> learnings(m);
    for (int i = 0; i < m; i++) {
        learnings[i] = read_mask();
    }
    int ans = inf;
    for (int mask = 0; mask < 1 << n; mask++) {
        for (int i = 0; i < m; i++) {
            int new_mask = mask | learnings[i];
            dp[new_mask] = min(dp[new_mask], dp[mask] + costs[i]);
        }
        if ((mask & required) == required) {
            ans = min(ans, dp[mask]);
        }
    }
    cout << ans << '\n';
    return 0;
#undef int
}