#include "bits/stdc++.h"
using namespace std;

#define int int64_t
const int inf = 1e18L + 5, mod = 1e9 + 7, N = 2e5 + 5;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int ans = 0;
        while (a.size() > 1) {
            n = a.size();
            int i = min_element(a.begin(), a.end()) - a.begin();
            if (i == n - 1) {
                a[i - 1] += a[i];
            }
            else if (i == 0) {
                a[i + 1] += a[i];
            }
            else if (a[i - 1] < a[i + 1]) {
                a[i - 1] += a[i];
            }
            else {
                a[i + 1] += a[i];
            }
            ans += 2 * a[i];
            a.erase(a.begin() + i);
        }
        cout << ans << '\n';
    }
    return 0;
}