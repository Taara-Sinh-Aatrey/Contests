#include "bits/stdc++.h"
using namespace std;

int maximizeNutrition(vector<int> cost, vector<int> nutrients, vector<int> min_quantity, vector<int> max_quantity, int m) {
    int n = cost.size();
    vector<int> a, b;
    vector<int> dp(m + 1, 0);
    for(int i = 0; i < n; i++) {
        m -= min_quantity[i] * cost[i];
        dp[0] += min_quantity[i] * nutrients[i];
        int rm = max_quantity[i] - min_quantity[i];
        while(rm > 0) {
            a.emplace_back(nutrients[i]);
            b.emplace_back(cost[i]);
            rm--;
        }
    }
    for(int i = 0; i < a.size(); i++) {
        for(int j = m; j >= b[i]; j--) {
            dp[j] = max(dp[j], dp[j - b[i]] + a[i]);
        }
    }
    int ans = 0;
    for(int j = 0; j <= m; j++) {
        ans = max(ans, dp[j]);
    }
    return ans;
}

signed main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cout << maximizeNutrition({2, 4, 3}, {2, 1, 3}, {2, 1, 1}, {4, 3, 1}, 30) << endl;

    return 0;
}