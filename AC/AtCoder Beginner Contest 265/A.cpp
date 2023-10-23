/**
 *    author:  Taara Sinh Aatrey
 *    created: 21.08.2022 17:30:43
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
    int x, y, n;
    cin >> x >> y >> n;
    int ans = 1e9 + 5;
    for (int a = 0; a <= n; a++) {
        if ((n - a) % 3) continue;
        int b = (n - a) / 3;
        ans = min(ans, a * x + b * y);
    }
    cout << ans;
    return 0;
}