#include "bits/stdc++.h"
#include <string>
using namespace std;

template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream &operator<<(ostream &os, const T_container &v) { bool f = false; for (const T &x : v) { if (f) os << " "; os << x; f = true; } return os; }

const int M = 1e9 + 7, N = 2e5 + 5;

int solve(string L, string R) {
    #define int int64_t
    int l = stoll(L), r = stoll(R);
    const int MAX = 9 * R.size();
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
                    ndp[sum + d] %= M; //
                }
            }
            for (int d = 0; d < D; d++) {
                ndp[eqsum + d]++; 
                ndp[eqsum + d] %= M; //
            }
            eqsum += D;
            swap(dp, ndp);
        }
        dp[eqsum]++;
        return dp;
    };
    auto dpH = fun(r);
    auto dpL = fun(l - 1);
    int cnt = r - l + 1;
    cnt %= M; //
    int ans = cnt * (cnt + 1) / 2;
    ans %= M; //
    for (int i = 1; i <= MAX; i++) {
        int cur = dpH[i] - (l == 1 ? 0 : dpL[i]);
        cur = (cur % M + M) % M; //
        ans -= cur * (cur + 1) / 2 % M; //
        ans = (ans % M + M) % M; //
    }
    return ans;
    #undef int
}

int main() {
    cout << solve("10", "18") << endl;
    return 0;
}