#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, W;
    cin >> n >> W;
    vector<int> wt(n), val(n);
    for(int i = 0; i < n; i++) {
        cin >> wt[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> val[i];
    }
    vector<int> dp(W + 1, 0);
    for (int i = 1; i <= n; i++) {
        for (int w = W; w >= wt[i - 1]; w--) {
            dp[w] = max(dp[w], dp[w - wt[i - 1]] + val[i - 1]);
        }
    }
    cout << dp[W] << '\n';
}