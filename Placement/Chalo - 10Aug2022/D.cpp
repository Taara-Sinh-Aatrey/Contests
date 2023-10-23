#include "bits/stdc++.h"
using namespace std;

int solve(int n, vector<int> a, int penalty) {
#define int int64_t
    vector<vector<int>> dp(n, vector<int>(2, -1));
    function<int(int, int)> recurse = [&] (int i, int parity) -> int {
        if (i == 0) return dp[i][parity] = a[i];
        if (dp[i][parity] != -1) return dp[i][parity];
        for (int p = 0; p < 2; p++) {
            dp[i][parity] += recurse(i - 1, p) - (p == parity ? 0 : penalty);
        }
        return dp[i][parity];
    };
    return max(recurse(n - 1, 0), recurse(n - 1, 1));
#undef int
}

int main() {
    cout << solve(4, {7, 2, 1, 10}, 5);
    return 0;
}