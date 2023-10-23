/**
 *    author:  Taara Sinh Aatrey
 *    created: 20.10.2022 20:04:35
**/

#include "bits/stdc++.h"

using namespace std;

#ifdef AATREY_DEBUG
#include "debug.hpp"
#else
#define dbg(...)
#endif

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int mp[128] = {};
    for (auto &ch : s) {
        mp[ch]++;
    }
    bool odd = false;
    int ans = 0;
    for (int start : {'a', 'A'}) {
        int end = start + 25;
        for (int ch = start; ch <= end; ch++) {
            odd |= mp[ch] & 1;
            ans += mp[ch] - (mp[ch] & 1);
        }    
    }
    cout << (ans + odd) << '\n';
    return 0;
}