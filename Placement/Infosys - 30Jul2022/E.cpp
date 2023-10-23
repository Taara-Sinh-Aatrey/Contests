#include "bits/stdc++.h"
using namespace std;

template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream &operator<<(ostream &os, const T_container &v) { bool f = false; for (const T &x : v) { if (f) os << " "; os << x; f = true; } return os; }

int solve(int n, int k) {
#define int int64_t
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++) {
        dp[i][i] = 1;
    }
    for (int sum = 0; sum < n; sum++) {
        for (int last = n; last >= 1; last--) {
            for (int cur = last * k; cur <= n && sum + cur <= n; cur++) {
                dp[sum + cur][cur] += dp[sum][last];
            }
        }
    }
    return accumulate(dp[n].begin(), dp[n].end(), 0);
#undef int
}

int main() {
    cout << solve(100, 3) << endl;
    return 0;
}