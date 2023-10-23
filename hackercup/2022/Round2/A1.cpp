/**
 *    author:  Taara Sinh Aatrey
 *    created: 24.09.2022 22:32:11
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
        string s;
        cin >> s;
        int n = s.size();
        s = "?" + s;
        array<int, 26> init;
        for (int i = 0; i < 26; i++) {
            init[i] = 0;
        }
        vector<array<int, 26>> freq(n + 1, init);
        for (int i = 1; i <= n; i++) {
            freq[i] = freq[i - 1];
            freq[i][s[i] - 'a']++;
        }
        auto fun = [&] (int l1, int r1, int l2, int r2) {
            array<int, 26> a, b;
            int cnt = 0, diff = 0;
            for (int i = 0; i < 26; i++) {
                a[i] = freq[r1][i] - freq[l1 - 1][i];
                b[i] = freq[r2][i] - freq[l2 - 1][i];
                if (a[i] != b[i]) {
                    cnt++;
                    diff = a[i] - b[i];
                }
            }
            return cnt == 1 && abs(diff) == 1;
        };
        int q;
        cin >> q;
        int ans = 0;
        while (q--) {
            int l, r;
            cin >> l >> r;
            if (l == r) {                ans++;
                continue;
            } 
            int m = (l + r) / 2;
            int cur = fun(l, m - 1, m, r) || fun(l, m, m + 1, r);
            ans += cur;
        }
        cout << ans << '\n';
    }
    return 0;
}