#include "bits/stdc++.h"
using namespace std;

template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream &operator<<(ostream &os, const T_container &v) { bool f = false; for (const T &x : v) { if (f) os << " "; os << x; f = true; } return os; }

int solve(int n, vector<int> a, int m, vector<int> b) {
#define int int64_t
    int pref = 0, mxa = 0, mxb = 0;
    const int mod = 1e9 + 7;
    for (int i = 0; i < n; i++) {
        pref += a[i];
        mxa = max(mxa, pref);
    }
    pref = 0;
    for (int i = 0; i < m; i++) {
        pref += b[i];
        mxb = max(mxb, pref);
    }
    return (mxa + mxb) % mod;
#undef int
}

int main() {
    cout << solve(2, {10, -5}, 1, {1}) << endl;
    cout << solve(2, {10, -5}, 2, {1, 5}) << endl;
    cout << solve(4, {6, -5, 7, -3}, 3, {2, 3, -4}) << endl;
    return 0;
}

// int lo = 0, hi = 1e14, ans = 0;
//     while (lo <= hi) {
//         int mid = (lo + hi) / 2;
//         int i = 0, j = 0, pref = 0;
//         bool ok = true;
//         while (i < n || j < m) {
//             if (i < n && pref + a[i] >= mid) {
//                 pref += a[i++];
//             }
//             else if (j < m && pref + b[j] >= mid) {
//                 pref += b[j++];
//             }
//             else {
//                 ok = false;
//                 break;
//             }
//         }
//         if (mid <= 15) {
//             dbg(mid, ok);
//         }
//         if (ok) {
//             ans = mid;
//             lo = mid + 1;
//         }
//         else {
//             hi = mid - 1;
//         }
//     }