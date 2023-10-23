#include "bits/stdc++.h"

using namespace std;

#ifdef AATREY_DEBUG
#include "debug.hpp"
#else
#define dbg(...)
#endif

#define int int64_t

int largestSubgrid(vector<vector<int>> grid, int maxSum) {
#define int int64_t
    int n = grid.size();
    vector<vector<int>> pref(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + grid[i - 1][j - 1];
        }
    }
    int low = 1, high = n;
    while (low <= high) {
        int mid = (low + high) / 2;
        const int inf = 1e18L + 5;
        int mx = -inf;
        for (int i = 1; i + mid - 1 <= n; i++) {
            for (int j = 1; j + mid - 1 <= n; j++) {
                int a = i, b = j;
                int c = i + mid - 1, d = j + mid - 1;
                int sum = pref[c][d] - pref[a - 1][d] - pref[c][b - 1] + pref[a - 1][b - 1]; 
                mx = max(mx, sum);
            }
        }
        if (mx <= maxSum) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return int32_t(high);
#undef int
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << largestSubgrid({{1, 2, 3}, {1, 2, 3}, {1, 2, 3}}, 18) << '\n';
    return 0;
}