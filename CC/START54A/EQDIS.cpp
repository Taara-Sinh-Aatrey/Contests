/**
 *    author:  Taara Sinh Aatrey
 *    created: 01.09.2022 16:09:26
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
        int n;
        cin >> n;
        map<int, int> freq;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            freq[x]++;
        }
        int ones = 0;
        bool greater_than_one = false;
        for (auto &[ele, fr] : freq) {
            if (fr == 1) ones ^= 1;
            else greater_than_one = true;
        }
        cout << (ones == 0 || (ones == 1 && greater_than_one) ? "YES" : "NO") << '\n';
    }
    return 0;
}