#include "bits/stdc++.h"
using namespace std;

template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream &operator<<(ostream &os, const T_container &v) { bool f = false; for (const T &x : v) { if (f) os << " "; os << x; f = true; } return os; }

const int mod = 1e9 + 7, N = 2e5 + 5;

vector<long> solve(long lowLimit, long highLimit) {
    #define int long
    const int MAX = 9 * to_string(highLimit).size();
    auto fun = [&] (int number) {
        string s = to_string(number);
        vector<int> dp(MAX + 1);
        int n = s.size();
        int eqsum = 0;
        for (int i = 0; i < n; i++) {
            vector<int> ndp(MAX + 1);
            int D = s[i] - '0';
            for (int d = 0; d <= 9; d++) {
                for (int sum = 0; sum + d <= MAX; sum++) {
                    ndp[sum + d] += dp[sum];  
                }
            }
            for (int d = 0; d < D; d++) {
                ndp[eqsum + d]++; 
            }
            eqsum += D;
            swap(dp, ndp);
        }
        dp[eqsum]++;
        return dp;
    };
    auto dpH = fun(highLimit);
    auto dpL = fun(lowLimit - 1);
    vector<int> ans{0, 0};
    for (int i = 1; i <= MAX; i++) {
        int cur = dpH[i] - (lowLimit == 1 ? 0 : dpL[i]);
        if (cur > ans[1]) {
            ans = {1, cur};
        }
        else if (cur == ans[1]) {
            ans[0]++;
        }
    }
    #undef int
    return ans;
}

int main() {
    cout << solve(3, 12) << endl;
    cout << solve(1, 5) << endl;
    cout << solve(1, 9) << endl;
    cout << solve(1, 10) << endl;
    return 0;
}