/**
 *    author:  Taara Sinh Aatrey
 *    created: 27.08.2022 16:08:08
**/

#include "bits/stdc++.h"

using namespace std;

#ifdef AATREY_DEBUG
#include "debug.hpp"
#else
#define dbg(...)
#endif

int solve(string s, int n) {
#define int int64_t
    const int mod = 1e9 + 7;
    int ans = 1;
    int ones = count(s.begin(), s.end(), '1');
    int mx = 0, cur = 0;
    for (int i = 0; i < n; i++) {
        if (cur < 0) cur = 0;
        cur += s[i] == '0' ? 1 : -1;
        mx = max(mx, cur);
    }
    ones += mx;
    for (int i = 1; i <= ones; i++) {
        ans *= 2;
        ans %= mod;
    }
    ans -= 2;
    return ans;
#undef int
}

int main() {
    cout << solve("1", 1) << endl;
    cout << solve("10", 2) << endl;
    return 0;
}