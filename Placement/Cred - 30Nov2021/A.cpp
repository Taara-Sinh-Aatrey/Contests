#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) 
        cin >> a[i];
    vector<int> dp(n + 1, n);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        int mn = n;
        for (int j = max<int>(0, i - a[i] - 1); j < i; j++) {
            mn = min(mn, dp[j]);
        }
        for (int j = i; j <= min(n, i + a[i]); j++) {
            dp[j] = min(dp[j], mn + 1);
        }
    }
    cout << dp[n] << '\n';
    return 0;
}