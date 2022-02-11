#include "bits/stdc++.h"
using namespace std;

#define int int64_t

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int m;
    cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; i++)
        cin >> b[i];
    sort(a.begin(), a.end());
    map<int, pair<int, int>> min_moves;
    min_moves[0] = {0, 0};
    for (int i = 0; i < n; i++) {
        if (i > 0)
            min_moves[a[i]].first = min_moves[a[i - 1]].first + (a[i] - a[i - 1]) * i;
        else
            min_moves[a[i]].first = 0;
        min_moves[a[i]].second = i + 1;
    }
    sort(b.rbegin(), b.rend());
    map<int, pair<int, int>> max_moves;
    max_moves[1e9] = {0, 0};
    for (int i = 0; i < n; i++) {
        if (i > 0)
            max_moves[b[i]].first = max_moves[b[i - 1]].first + (b[i - 1] - b[i]) * i;
        else
            max_moves[b[i]].first = 0;
        max_moves[b[i]].second = i + 1;
    }
    int ans = LLONG_MAX;
    for (int x = 0; x <= 1e7; x++) {
        auto it = prev(min_moves.upper_bound(x));
        int cur = it->second.first + (x - it->first) * it->second.second;
        it = max_moves.lower_bound(x);
        cur += it->second.first + (it->first - x) * it->second.second;
        ans = min(ans, cur);
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
    return 0;
}