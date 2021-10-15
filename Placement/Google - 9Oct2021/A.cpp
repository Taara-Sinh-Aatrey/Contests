#include "bits/stdc++.h"
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> s(n);
        for (int i = 0; i < n; i++) {
            cin >> s[i];
        }
        auto Sum = [&] (int num) {
            int sum = 0;
            while (num > 0) {
                sum += num % 10;
                num /= 10;
            }
            return sum;
        };
        const int mod = 1e9 + 7;
        const int MAX = 1000;
        vector<int> dp(MAX + 1);
        for (int num = 1; num <= MAX; num++) {
            if (Sum(num) != s[0]) continue;
            dp[num]++;
        }
        for (int i = 1; i < n; i++) {
            for (int num = 1; num <= MAX; num++) {
                dp[num] += dp[num - 1];
                if (dp[num] >= mod) dp[num] -= mod;
            }
            vector<int> ndp(MAX + 1, 0);
            for (int num = 1; num <= MAX; num++) {
                if (Sum(num) != s[i]) continue;
                ndp[num] = dp[num - 1];
            }
            swap(dp, ndp);
        }
        int ans = 0;
        for (auto& x : dp) {
            ans += x;
            if (ans >= mod) ans -= mod;
        }
        cout << ans << '\n';
    }
    return 0;
}