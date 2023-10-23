/**
 *    author:  Taara Sinh Aatrey
 *    created: 26.12.2022 19:15:27
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
    int x, y;
    cin >> x >> y;
    char big = y >= x ? 'B' : 'A';
    char small = y >= x ? 'A' : 'B';
    int small_value = min(x, y), big_value = max(x, y), c = 0;
    int bit = 0;
    vector<array<char, 3>> ops;
    while (c != x * y) {
        if (small_value >> bit & 1) {
            ops.push_back({big, 'C', 'C'});
            c += big_value;
        }
        bit++;
        big_value += big_value;
        ops.push_back({big, big, big});
    }
    cout << ops.size() << '\n';
    for (auto &v : ops) {
        for (auto &e : v) {
            cout << e << " ";
        }
        cout << '\n';
    }
    cout << "C\n";
    return 0;
}