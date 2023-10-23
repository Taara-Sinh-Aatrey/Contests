/**
 *    author:  Taara Sinh Aatrey
 *    created: 29.12.2022 03:20:58
**/

#include "bits/stdc++.h"

using namespace std;

#ifdef AATREY_DEBUG
#include "debug.hpp"
#else
#define dbg(...)
#endif

#define int int64_t

const int inf = 1e18L + 5;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int testcases;
    cin >> testcases;
    for (int caseno = 1; caseno <= testcases; caseno++) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n * m);
        for (auto &x : a) {
            cin >> x;
        }
        sort(a.begin(), a.end());
        bool swapped = false;
        if (m < n) {
            swapped = true;
            swap(n, m);
        }
        int steps = n + m - 1;
        int best_i = -1, best_diff = inf;
        int big_count = (n - 1 + 1) / 2, small_count = (n - 1) / 2;
        for (int i = big_count; i + steps + small_count <= n * m; i++) {
            int diff = a[i + steps - 1] - a[i];
            if (diff < best_diff) {
                best_diff = diff;
                best_i = i;
            }
        }
        vector<vector<int>> ans(n, vector<int>(m));
        int L = best_i, R = best_i + steps - 1;
        int l = 0, r = n * m - 1;
        for (int i = 1; i < n; i++) {
            if (i % 2 == 1) {
                // a[i][0] > a[i - 1][1]
                ans[i][0] = a[R--];
                ans[i - 1][1] = a[l++];
            }
            else {
                // a[i][0] < a[i - 1][1]
                ans[i][0] = a[L++];
                ans[i - 1][1] = a[r--];
            }
        }
        ans[0][0] = a[L++];
        for (int c = 1; c < m; c++) {
            ans[n - 1][c] = a[L++];
        }
        assert(L >= R);
        for (int i = 0; i < n - 1; i++) {
            for (int j = 2; j < m; j++) {
                if (l < best_i) {
                    ans[i][j] = a[l++];
                }
                else {
                    assert(r > best_i + steps - 1);
                    ans[i][j] = a[r--];
                }
            }
        }
        int rows = swapped ? m : n;
        int cols = swapped ? n : m;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << (swapped ? ans[j][i] : ans[i][j]) << " \n"[j == cols - 1];
            }
        }
    }
    return 0;
}