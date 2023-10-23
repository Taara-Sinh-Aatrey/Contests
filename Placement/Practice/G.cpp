#include "bits/stdc++.h"
using namespace std;

#define int int64_t

vector<int> solve(vector<int> pos, int n) {
    int m = pos.size();
    const int inf = 1e18L + 5;
    vector<int> v(n, -inf), l(n, -inf), r(n, -inf);
    for (int i = 0; i < m; i++) {
        int x = pos[i];
        v[x] = max(v[x], 0LL);
    }
    for (int i = 1; i < n; i++) {
        r[i] = max({r[i], r[i - 1] + 1, v[i - 1] + 1});
    }
    for (int i = n - 2; i >= 0; i--) {
        l[i] = max({l[i], l[i + 1] + 1, v[i + 1] + 1});
    }
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        ans[i] = max({l[i], v[i], r[i]});
    }
    return ans;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> pos(m);
    for (int i = 0; i < m; i++) {
        cin >> pos[i];
    }
    vector<int> ans = solve(pos, n);
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << '\n';
    return 0;
}