#include<bits/stdc++.h>
using namespace std;

long long solve (int N, int M, vector<array<int, 3>> A) {
    vector<vector<pair<int64_t, int64_t>>> events(N);
    for (auto& [l, r, w] : A) {
        --l, --r;
        events[l].emplace_back(w, r);
        events[r].emplace_back(-w, l);
    }
    const int64_t inf = 1e18L + 5;
    vector<int64_t> dp(N, inf);
    dp[0] = 0;
    multiset<pair<int64_t, int64_t>> ms;
    for (int i = 0; i < N; i++) {
        if (!ms.empty()) dp[i] = ms.begin()->first;
        for (auto& [w, j] : events[i]) {
            if (w > 0) ms.insert({dp[i] + w, j});
            else ms.erase(ms.find({dp[j] - w, i}));
        }
    }
    return dp[N - 1] >= inf ? -1 : dp[N - 1];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<array<int, 3>> a(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }
    cout << solve(n, m, a) << '\n';
    
    // cout << solve(4, 3, {{1, 4, 10}, {1, 2, 5}, {2, 4, 3}}) << endl; // 8
    // cout << solve(4, 1, {{1, 3, 10}}) << endl; // -1
    return 0;
}