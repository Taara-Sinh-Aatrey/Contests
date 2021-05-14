#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(int tt) {

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0));

    int ans = 0, x;
    
    for(int i = 1; i <= n; i++) {

        for(int j = 1; j <= m; j++) {

            cin >> x;

            pref[i][j] = x + pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];

            int low = 1, high = min(i, j);

            while(low <= high) {
                int mid = (low + high) >> 1;

                if(pref[i][j] - pref[i - mid][j] - pref[i][j - mid] + pref[i - mid][j - mid] >= k * mid * mid) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            
            ans += high;

        }
    }

    cout << ans << '\n';
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