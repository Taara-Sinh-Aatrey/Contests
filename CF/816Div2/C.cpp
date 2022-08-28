/**
 *    author:  Taara Sinh Aatrey
 *    created: 20.08.2022 20:34:20
**/

#include "bits/stdc++.h"

using namespace std;

#ifdef AATREY_DEBUG
#include "debug.hpp"
#else
#define dbg(...)
#endif

int main() {
#define int int64_t
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    int cur = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0 || a[i] != a[i - 1]) {
            cur += i;
        }
        cur++;
        ans += cur;
    }
    for (int i = 0; i < m; i++) {
        int idx, val;
        cin >> idx >> val, --idx;
        if (a[idx] != val) {
            int right = n - 1 - idx;
            int left = idx;
            if (idx + 1 < n) {
                if (a[idx + 1] == val) {
                    ans -= right * (left + 1);
                }
                if (a[idx + 1] == a[idx]) {
                    ans += right * (left + 1);
                }
            }
            if (idx - 1 >= 0) {
                if (a[idx - 1] == val) {
                    ans -= (right + 1) * left;
                }
                if (a[idx - 1] == a[idx]) {
                    ans += (right + 1) * left;
                }
            }
           a[idx] = val;
        }
        cout << ans << '\n';
    }
    return 0;
#undef int
}