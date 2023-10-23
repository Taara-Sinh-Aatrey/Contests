/**
 *    author:  Taara Sinh Aatrey
 *    created: 25.08.2022 14:28:00
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
        int r, c;
        cin >> r >> c;
        vector<vector<int>> a(9, vector<int>(9));
        a[r][c] = 1;
        int dr = min(r, 9 - r), dc = min(c, 9 - c);
        if (dr == 1 && dc == 1) {
            a[r + 1 <= 8 ? r + 1 : r - 1][c + 2 <= 8 ? c + 2 : c - 2] = 2;
        }
        else if (dc == 1) {
            if (r + 1 <= 8 && c + 3 <= 8) {
                a[r + 1][c + 2] = 2;
                a[r + 1][c + 3] = 2;
            }
            else if (r + 1 <= 8 && c - 3 >= 1) {
                a[r + 1][c - 2] = 2;
                a[r + 1][c - 3] = 2;
            }
            else if (r - 1 >= 1 && c + 3 <= 8) {
                a[r - 1][c + 2] = 2;
                a[r - 1][c + 3] = 2;
            }
            else if (r - 1 >= 1 && c - 3 >= 1) {
                a[r - 1][c - 2] = 2;
                a[r - 1][c - 3] = 2;
            }
        }
        else if (dr == 1) {
            if (c + 1 <= 8 && r + 3 <= 8) {
                a[r + 2][c + 1] = 2;
                a[r + 3][c + 1] = 2;
            }
            else if (c + 1 <= 8 && r - 3 >= 1) {
                a[r - 2][c + 1] = 2;
                a[r - 3][c + 1] = 2;
            }
            else if (c - 1 >= 1 && r + 3 <= 8) {
                a[r + 2][c - 1] = 2;
                a[r + 3][c - 1] = 2;
            }
            else if (c - 1 >= 1 && r - 3 >= 1) {
                a[r - 2][c - 1] = 2;
                a[r - 3][c - 1] = 2;
            }
        }
        else {
            if (r + 2 <= 8 && c + 3 <= 8) {
                a[r + 2][c - 1] = 2;
                a[r - 1][c + 3] = 2;
            }
            else if (r + 2 <= 8 && c - 3 >= 1) {
                a[r + 2][c + 1] = 2;
                a[r - 1][c - 3] = 2;
            }
            else if (r - 2 >= 1 && c + 3 <= 8) {
                a[r - 2][c - 1] = 2;
                a[r + 1][c + 3] = 2;
            }
            else if (r - 2 >= 1 && c - 3 >= 1) {
                a[r - 2][c + 1] = 2;
                a[r + 1][c - 3] = 2;
            }
        }
        for (int i = 1; i <= 8; i++) {
            for (int j = 1; j <= 8; j++) {
                cout << a[i][j] << " \n"[j == 8];
            }
        }
    }
    return 0;
}

