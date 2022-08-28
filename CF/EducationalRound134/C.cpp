/**
 *    author:  Taara Sinh Aatrey
 *    created: 27.08.2022 20:32:39
**/

#include "bits/stdc++.h"

using namespace std;

#ifdef AATREY_DEBUG
#include "debug.hpp"
#else
#define dbg(...)
#endif

#define int int64_t

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        multiset<int> st(b.begin(), b.end());
        for (int i = 0; i < n; i++) {
            cout << *st.lower_bound(a[i]) - a[i] << " \n"[i == n - 1];
        }
        vector<int> ord(n);
        iota(ord.begin(), ord.end(), 0);
        sort(ord.begin(), ord.end(), [&] (auto &x, auto &y) {
            return a[x] > a[y];
        });
        vector<int> ans(n);
        for (auto &i : ord) {
            ans[i] = *st.rbegin() - a[i];
            st.erase(st.lower_bound(a[i]));
        }
        for (int i = 0; i < n; i++) {
            cout << ans[i] << " \n"[i == n - 1];
        }
    }
    return 0;
}