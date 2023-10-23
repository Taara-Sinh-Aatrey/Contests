/**
 *    author:  Taara Sinh Aatrey
 *    created: 27.08.2022 17:31:05
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
    string s;
    cin >> s;
    cout << s[(s.size() - 1) / 2];
    return 0;
}