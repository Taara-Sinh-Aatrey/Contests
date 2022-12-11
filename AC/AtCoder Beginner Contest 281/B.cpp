/**
 *    author:  Taara Sinh Aatrey
 *    created: 10.12.2022 20:42:21
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
    bool ok = s.size() == 8 && isupper(s.front()) && isupper(s.back());
    for (int i = 1; i + 1 < s.size(); i++) {
        ok = ok & isdigit(s[i]);
        if (i == 1) {
            ok = ok & (s[i] != '0');
        }
    }
    cout << (ok ? "Yes" : "No") << '\n';
    return 0;
}