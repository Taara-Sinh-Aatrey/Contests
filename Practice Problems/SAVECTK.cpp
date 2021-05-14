#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(int tt) {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int& x: a) {
        cin >> x;
    }

    sort(a.begin(), a.end());

    vector<int> pref(n, 0);
    for(int i = 0; i < n; i++) {
        pref[i] = a[i] + (i > 0 ? pref[i - 1] : 0);
    }

    pair<int, int> ans = {1e18, 1e18};

    for(int i = 0; i < n; i++) {
        // remove ith

        if(i > 0 && i < n - 1)
            continue;

        int median = (n - 1) / 2;

        if(i <= median) {
            median++;
        }
        int left_cnt = median;
        int right_cnt = n - 1 - left_cnt;

        int cost = 0;

        if(left_cnt > 0) {
            int left_sum = pref[median - 1];
            if(i < median) {
                left_sum -= a[i];
                left_cnt--;
            }
            cost += left_cnt * a[median] - left_sum;
        }

        if(right_cnt > 0) {
            int right_sum = pref[n - 1] - pref[median];
            if(i > median) {
                right_sum -= a[i];
                right_cnt--;
            }
            cost += right_sum - right_cnt * a[median];
        }

        assert(left_cnt + right_cnt == n - 2);
        ans = min(ans, make_pair(cost, a[i]));
    }

    cout << ans.second << " " << ans.first << '\n';
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