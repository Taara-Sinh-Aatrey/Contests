#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(int tt) {
    int n, m, cnt;
    cin >> n >> m >> cnt;

    vector<vector<int>> all(n + 1, vector<int>(n + 1, 0));

    vector<int> a(n);
    for(int& x: a) {
        cin >> x;
    }
    a.insert(a.begin(), 0);

    for(int i = 0; i < m; i++) {
        int u, v, d;
        cin >> u >> v >> d;
        for(int x = 1; x <= u; x++) {
            all[x][v] += d;
        }
    }

    vector<vector<int>> dp(1);

    dp[0].emplace_back(0);

    for(int i = 1; i <= n; i++) {
        vector<vector<int>> ndp(i + 1);

        for(int last = 0; last < i; last++) {
            for(int j = 0; j < cnt && j < (int) dp[last].size(); j++) {
                // take 0
                ndp[0].emplace_back(dp[last][j]);

                // take 1
                int nlast = (last == 0 ? i : last);
                ndp[nlast].emplace_back(dp[last][j] + a[i] + all[nlast][i]);
            }
        }

        for(int last = 0; last <= i; last++) {
            sort(ndp[last].rbegin(), ndp[last].rend());
            while((int) ndp[last].size() > cnt) {
                ndp[last].pop_back();
            }
        }

        dp = ndp;
    }

    vector<int> ans;
    for(int last = 0; last <= n; last++) {
        for(int val: dp[last]) {
            ans.emplace_back(val);
        }
    }

    sort(ans.rbegin(), ans.rend());
    for(int i = 0; i < cnt; i++) {
        cout << ans[i] << " ";
    }
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    for(int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
    

    return 0;
}