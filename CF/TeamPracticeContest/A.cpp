/**
 *    author:  Taara Sinh Aatrey
 *    created: 27.08.2022 23:06:49
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
        int a, b;
        cin >> a >> b;
        string s;
        cin >> s;
        int n = s.size();
        vector<int> gaps;
        int last = -1;
        int ans = 0;
        for (int i = 0, j; i < n; i = j) {
            if (s[i] == '0') {
                j = i + 1;
                continue;
            }
            j = i + 1;
            while (j < n && s[j] == '1') j++;
            if (last != -1) {
                gaps.emplace_back((i - last - 1) * b);
            }
            ans += a;
            last = j - 1;
        }
        sort(gaps.rbegin(), gaps.rend());
        while (!gaps.empty() && gaps.back() < a) {
            ans -= a;
            ans += gaps.back();
            gaps.pop_back();
        }
        cout << ans << '\n';
    }
    return 0;
}