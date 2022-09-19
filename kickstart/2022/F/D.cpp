/**
 *    author:  Taara Sinh Aatrey
 *    created: 19.09.2022 00:10:21
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
    int testcases;
    cin >> testcases;
    for (int caseno = 1; caseno <= testcases; caseno++) {
        cout << "Case #" << caseno << ": ";
        int n, k, x, d;
        cin >> n >> k >> x >> d;
        vector<vector<int>> L(d + 1), R(d + 1);
        int m;
        cin >> m;
        while (m--) {
            int p, l, r;
            cin >> p >> l >> r, --p;
            L[l].emplace_back(p);
            R[r].emplace_back(p);
        }
        vector<int> cnt(n);
        int l = 0, r = x;
        set<pair<int, int>> st, nxt;
        for (int i = l; i < r; i++) {
            for (auto &p : L[i]) {
                cnt[p]++;
            }
        }
        vector<pair<int, int>> a;
        for (int i = 0; i < n; i++) {
            a.emplace_back(cnt[i], i);
        }
        sort(a.begin(), a.end());
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (i < k) {
                st.emplace(a[i]);
                sum += a[i].first;
            }
            else {
                nxt.emplace(a[i]);
            }
        }
        const int inf = 1e18L + 5;
        int ans = inf;
        while (l + x <= d) {
            ans = min(ans, sum);
            for (auto &p : R[l + 1]) {
                if (st.count({cnt[p], p})) {
                    st.erase({cnt[p], p});
                    sum -= cnt[p];
                }
                else {
                    nxt.erase({cnt[p], p});
                }
                cnt[p]--;
                nxt.emplace(cnt[p], p);
            }
            for (auto &p : L[r]) {
                if (st.count({cnt[p], p})) {
                    st.erase({cnt[p], p});
                    sum -= cnt[p];
                }
                else {
                    nxt.erase({cnt[p], p});
                }
                cnt[p]++;
                nxt.emplace(cnt[p], p);
            }
            while (st.size() < k) {
                st.insert(*nxt.begin());
                sum += nxt.begin()->first;
                nxt.erase(nxt.begin());
            }
            while (!nxt.empty() && !st.empty() && st.rbegin()->first > nxt.begin()->first) {
                sum += nxt.begin()->first - st.rbegin()->first;
                nxt.emplace(*st.rbegin());
                st.erase(prev(st.end()));
                st.emplace(*nxt.begin());
                nxt.erase(nxt.begin());
            }
            l++, r++;
        }
        cout << ans << '\n';
    }
    return 0;
}