/**
 *    author:  Taara Sinh Aatrey
 *    created: 14.08.2022 15:20:38
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
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n, --n;
        int ans = 0, pref = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            pref += x;
            ans = max(ans, pref);
            ans += x;
        }
        cout << ans << '\n';
    }
    return 0;
}