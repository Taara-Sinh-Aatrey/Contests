/**
 *    author:  Taara Sinh Aatrey
 *    created: 10.12.2022 20:48:13
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
    int n, t;
    cin >> n >> t;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int sum = accumulate(a.begin(), a.end(), 0LL);
    t %= sum;
    int i = 0;
    while (t > a[i]) {
        t -= a[i++];
    }
    if (t == 0) {
        cout << n << " " << a.back() << '\n';
    }
    else {
        cout << i + 1 << " " << t << '\n';
    }
    return 0;
}