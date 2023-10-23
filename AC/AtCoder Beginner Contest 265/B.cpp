/**
 *    author:  Taara Sinh Aatrey
 *    created: 21.08.2022 17:33:03
**/

#include "bits/stdc++.h"

using namespace std;

#ifdef AATREY_DEBUG
#include "debug.hpp"
#else
#define dbg(...)
#endif

int main() {
#define int int64_t
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, t;
    cin >> n >> m >> t;
    vector<int> a(n);
    for (int i = 1; i < n; i++) {
        cin >> a[i];
    }
    map<int, int> mp;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        mp[x] += y;
    }
    for (int i = 1; i <= n; i++) {
        t -= a[i - 1];
        if (t <= 0) {
            cout << "No";
            return 0;
        }
        t += mp[i];
    }
    cout << "Yes" << '\n';
    return 0;
#undef int
}