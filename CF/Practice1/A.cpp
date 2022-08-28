/**
 *    author:  Taara Sinh Aatrey
 *    created: 17.08.2022 21:11:55
**/

#include "bits/stdc++.h"

using namespace std;

#ifdef AATREY_DEBUG
#include "debug.hpp"
#else
#define dbg(...)
#endif

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int64_t n;
    cin >> n;
    string s;
    while (n > 0) {
        s = char('0' + (n % 9)) + s;
        n /= 9;
    }
    int eqsum = 0, small = 0, smallsum = 0;
    int ans = 0;
    n = s.size();
    for (int i = 0; i < n; i++) {
        int d = s[i] - '0';
        smallsum = smallsum * 9 + small * 36 + eqsum * d + (d - 1) * d / 2;
        smallsum %= 4;
        eqsum += d;
        eqsum %= 4;
        small = small * 9 + 1 * d;
        small %= 4;
    }
    ans = smallsum + eqsum;
    ans %= 4;
    cout << ans << '\n';
    return 0;
}