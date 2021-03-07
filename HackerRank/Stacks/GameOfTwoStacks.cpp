#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n, m, x;
        cin >> n >> m >> x;

        vector<int> a(n), b(m);

        for(auto& ele: a) {
            cin >> ele;
        }

        for(auto& ele: b) {
            cin >> ele;
        }

        int sum = 0, idx_a = 0;

        while(idx_a < n && sum + a[idx_a] <= x) {
            sum += a[idx_a++];
        }

        int ans = idx_a, idx_b = 0;

        while(idx_b < m) {
            sum += b[idx_b++];
            while(idx_a > 0 && sum > x) {
                sum -= a[--idx_a];
            }
            if(sum <= x) {
                ans = max(ans, idx_a + idx_b);
            }
        }

        cout << ans << '\n';
    }

    return 0;
}