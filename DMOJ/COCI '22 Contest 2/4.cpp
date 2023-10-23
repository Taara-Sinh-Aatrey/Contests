/**
 *    author:  Taara Sinh Aatrey
 *    created: 26.12.2022 20:38:17
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
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (auto &s : a) {
        cin >> s;
    }
    vector<string> b(m);
    for (auto &s : b) {
        cin >> s;
    }
    return 0;
}