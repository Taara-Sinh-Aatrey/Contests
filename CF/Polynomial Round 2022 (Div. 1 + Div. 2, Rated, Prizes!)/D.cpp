/**
 *    author:  Taara Sinh Aatrey
 *    created: 18.12.2022 03:06:52
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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));
        vector<int> cnt(n);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
                cnt[i] += a[i][j];
                sum += a[i][j];
            }
        }
        if (sum % n) {
            cout << -1 << '\n';
            continue;
        }
        int each = sum / n;
        vector<array<int, 3>> ops;
        for (int j = 0; j < m; j++) {
            queue<int> more, less;
            for (int i = 0; i < n; i++) {
                if (cnt[i] > each && a[i][j] == 1) {
                    more.push(i);
                }
                else if (cnt[i] < each && a[i][j] == 0) {
                    less.push(i);
                }
            }
            int sz = min(more.size(), less.size());
            while (sz--) {
                int x = more.front(); more.pop();
                int y = less.front(); less.pop();
                cnt[x]--;
                cnt[y]++;
                ops.push_back({x + 1, y + 1, j + 1});
            }
        }
        for (int i = 0; i < n; i++) {
            assert(cnt[i] == each);
        }
        cout << ops.size() << '\n';
        for (auto &x : ops) {
            cout << x[0] << " " << x[1] << " " << x[2] << '\n'; 
        }
    }
    return 0;
}