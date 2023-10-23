#include "bits/stdc++.h"
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
    int n, t;
    cin >> n >> t;
    vector<int> d(n), v(n);
    for (auto &x : d)
        cin >> x;
    for (auto &x : v)
        cin >> x;
    vector<int> D(n);
    for (int i = 0; i < n; i++) {
        D[i] = d[i] + v[i] * t;
    }
    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&] (auto &x, auto &y) {
        return D[x] < D[y];
    });
    int ans = 0;
    oset<pair<int, int>> st;
    vector<pair<int, int>> pending;
    int dist;
    for (int it = 0; it < n; it++) {
        int i = ord[it];
        if (dist < D[i]) {
            for (auto &p : pending) {
                st.insert(p);
            }
            pending.clear();
        }
        ans += st.size() - st.order_of_key({d[i], INT_MAX});
        dist = D[i];
        pending.emplace_back(d[i], i);
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}