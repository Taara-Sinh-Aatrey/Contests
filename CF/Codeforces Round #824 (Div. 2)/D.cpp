/**
 *    author:  Taara Sinh Aatrey
 *    created: 02.10.2022 20:08:25
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
    int n, k;
    cin >> n >> k;
    map<vector<vector<int>>, int> dp;
    dp[vector<vector<int>>(k)] = 1;
    for (int i = 0; i < n; i++) {
        map<vector<vector<int>>, int> ndp = dp;
        vector<int> a(k);
        for (int j = 0; j < k; j++) {
            cin >> a[j];
        }
        for (auto &[v, cnt] : dp) {
            if (v[0].size() >= 5) {
                continue;
            }
            auto nv = v;
            for (int j = 0; j < k; j++) {
                nv[j].emplace_back(a[j]);
            }
            // dbg(nv, cnt);
            ndp[nv] += cnt;
        }
        swap(dp, ndp);
    }
    int ans = 0;
    for (auto &[v, cnt] : dp) {
        if (v[0].size() != 5) {
            continue;
        }
        bool ok = true;
        vector<bool> MX(6);
        set<set<int>> st;
        for (int j = 0; j < k && ok; j++) {
            vector<int> freq(3);
            for (int i = 0; i < 5; i++) {
                freq[v[j][i]]++;
            }
            int mx = max_element(freq.begin(), freq.end()) - freq.begin();
            int mn = min_element(freq.begin(), freq.end()) - freq.begin();
            MX[freq[mx]] = true;
            if (!(freq[mx] >= 4 || (freq[mx] == 3 && freq[mn] == 1))) {
                ok = false;
                break;
            }
            if (freq[mx] == 5) {
                continue;
            }
            set<int> s;
            for (int i = 0; i < 5; i++) {
                if (v[j][i] != mx) {
                    s.emplace(i);
                }
            }
            st.emplace(s);
        }
        dbg(v);
        if (!ok || (MX[3] && MX[4]) || (MX[3] && st.size() > 2) || (MX[4] && st.size() > 1)) {
            continue;
        }
        dbg(true);
        ans += cnt;
    }   
    cout << ans << '\n'; 
    return 0;
}