/**
 *    author:  Taara Sinh Aatrey
 *    created: 11.09.2022 15:44:31
**/

#include "bits/stdc++.h"

using namespace std;

#ifdef AATREY_DEBUG
#include "debug.hpp"
#else
#define dbg(...)
#endif

#define int int64_t

template <typename T>
vector<int> kmp_table(const T &s) {
    int n = s.size(), len = 0;
    vector<int> lps(n, 0);
    for (int i = 1; i < n; i++) {
        while (len > 0 && s[i] != s[len])
            len = lps[len - 1];
        if (s[i] == s[len]) 
            len++;
        lps[i] = len;
    }
    return lps;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        cout << "Case #" << tt << ": ";
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<int> b(n);
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        if (k == 0) {
            cout << (a == b ? "YES" : "NO") << '\n';
            continue;
        }
        if (n == 2) {
            cout << (a[0] == a[1] || (a == b) == (k % 2 == 0) ? "YES" : "NO") << '\n';
            continue;
        }
        if (a == b && k != 1) {
            cout << "YES" << '\n';
            continue;
        }
        vector<int> c(2 * n);
        for (int i = 0; i < 2 * n; i++) {
            c[i] = i < n ? a[i] : b[i - n];
        }
        auto lps = kmp_table(c);
        int l = lps[2 * n - 1];
        map<int, bool> ma;
        while (l > 0) {
            ma[l] = true;
            l = lps[l - 1];
        }
        vector<int> d(2 * n);
        for (int i = 0; i < 2 * n; i++) {
            d[i] = (i < n ? b[i] : a[i - n]);
        }
        lps = kmp_table(d);
        l = lps[2 * n - 1];
        bool ok = false;
        while (l > 0) {
            if (ma[n - l]) {
                ok = true;
                break;
            }
            l = lps[l - 1];
        }
        cout << (ok ? "YES" : "NO") << '\n';
    }
    return 0;
}
// 5 1 2 2 3
// 2 2 3 5 1
// 5 1 2 2 3  $  2 2 3 5 1
// 2 2 3 5 1  $  5 1 2 2 3
// 1 2 1 2 1 2
