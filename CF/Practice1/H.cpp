/**
 *    author:  Taara Sinh Aatrey
 *    created: 17.08.2022 23:12:23
**/

#include "bits/stdc++.h"

using namespace std;

#ifdef AATREY_DEBUG
#include "debug.hpp"
#else
#define dbg(...)
#endif

const int N = 1e7;
int dp[N + 1] = {};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    int64_t X;
    cin >> n >> X;
    vector<int> nums, costs;
    {
        map<int, vector<int>> mp;
        vector<int> a(n), b(n);
        for (auto &x : a) cin >> x;
        for (auto &x : b) cin >> x;
        for (int i = 0; i < n; i++) {
            mp[a[i]].emplace_back(b[i]);
        }
        for (auto &[x, vec] : mp) {
            sort(vec.begin(), vec.end());
            int m = vec.size();
            for (int i = 0; i + 2 <= m; i += 2) {
                nums.emplace_back(x);
                costs.emplace_back(vec[i] + vec[i + 1]);
            }
        }
    }
    n = costs.size();
    dp[0] = 1;
    const int MAX = 1e9 + 5;
    for (int i = 0; i < n; i++) {
        for (int j = N - costs[i]; j >= 0; j--) {
            dp[j + costs[i]] = max<int64_t>(dp[j + costs[i]], min<int64_t>(MAX, dp[j] * int64_t(nums[i])));
        }
    }
    int64_t x = sqrt(X);
    while (x * x < X) {
        x++;
    }
    while ((x - 1) * (x - 1) >= X) {
        x--;
    }
    for (int i = 1; i <= N; i++) {
        if (dp[i] >= x) {
            cout << i;
            return 0;
        }
    }
    cout << -1;
    return 0;
}