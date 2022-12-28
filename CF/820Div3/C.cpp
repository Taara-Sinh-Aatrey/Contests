/**
 *    author:  Taara Sinh Aatrey
 *    created: 13.09.2022 00:33:25
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
        string s;
        cin >> s;
        int n = s.size();
        vector<int> ord(n - 2);
        iota(ord.begin(), ord.end(), 1);
        sort(ord.begin(), ord.end(), [&] (auto &i, auto &j) {
            if (s.front() == s.back())
                return s[i] < s[j];
            return s[i] > s[j];
        });
        vector<int> ans{0};
        for (auto &i : ord) {
            if (min(s.front(), s.back()) <= s[i] && s[i] <= max(s.front(), s.back())) {
                ans.emplace_back(i);
            }
        }
        ans.emplace_back(n - 1);
        cout << abs(s.front() - s.back()) << " " << ans.size() << '\n';
        for (auto &i : ans) {
            cout << i + 1 << " ";
        }
        cout << '\n';
    }
    return 0;
}