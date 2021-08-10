#include "bits/stdc++.h"
using namespace std;

vector<int> dp;
vector<int> fib;

signed main() {
    int n;
    cin >> n;

    dp.resize(n + 1);
    fib.push_back(1);
    fib.push_back(1);
    int size = 1;
    while (fib[size] + fib[size - 1] <= n) {
        fib.push_back(fib[size] + fib[size - 1]);
        size += 1;
    }
    fib.erase(fib.begin());

    dp[0] = 1;
    for (int fib : fib) {
        for (int i = n; i >= 0; i--) {
            if (i - fib >= 0) {
                dp[i] += dp[i - fib];
            }
        }
    }

    cout << dp[n];
    return 0;
}