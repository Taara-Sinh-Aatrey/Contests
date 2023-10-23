#include "bits/stdc++.h"
#include <numeric>
#include <string>
using namespace std;

template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream &operator<<(ostream &os, const T_container &v) { bool f = false; for (const T &x : v) { if (f) os << " "; os << x; f = true; } return os; }

const int mod = 1e9 + 7;

int solve(int N) {
#define int int64_t
    vector<int> a;
    for (int i = 9; i <= N; i++) {
        if (to_string(i).find('9') != string::npos) {
            a.emplace_back(i);
        }
    }
    int n = a.size();
    vector<vector<int>> dp(N + 1, vector<int>(n, 0));
    for (int j = 0; j < n; j++) {
        dp[a[j]][j] = 1;
    }
    for (int sum = 0; sum < N; sum++) {
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n && sum + a[j] <= N; j++) {
                dp[sum + a[j]][j] += dp[sum][i];
            } 
        }
    }
    return accumulate(dp[N].begin(), dp[N].end(), 0LL);
#undef int
}

int main() {
    cout << solve(67) << endl;
    cout << solve(77) << endl;
    cout << solve(107) << endl;
    return 0;
}