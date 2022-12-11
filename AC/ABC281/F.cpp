/**
 *    author:  Taara Sinh Aatrey
 *    created: 10.12.2022 21:42:10
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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    function<int(int, vector<int> &v)> rec = [&] (int bit, vector<int> &v) -> int {
        if (bit < 0) {
            return 0;
        } 
        vector<int> withOne, withZero;
        for (auto &x : v) {
            if (x >> bit & 1) {
                withOne.emplace_back(x);
            }
            else {
                withZero.emplace_back(x);
            }
        }
        if (withOne.empty()) {
            return rec(bit - 1, withZero);
        }
        if (withZero.empty()) {
            return rec(bit - 1, withOne);
        }
        return (1 << bit) + min(rec(bit - 1, withOne), rec(bit - 1, withZero));
    };
    cout << rec(29, a);
    return 0;
}