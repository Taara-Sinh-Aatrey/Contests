/**
 *    author:  Taara Sinh Aatrey
 *    created: 17.09.2022 16:09:21
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
    int testcases;
    cin >> testcases;
    for (int caseno = 1; caseno <= testcases; caseno++) {
        int n;
        cin >> n;
        vector<int> a(n);
        iota(a.begin(), a.end(), 1);
        for (int i = n % 2; i < n - 2; i += 2) {
            swap(a[i], a[i + 1]);
        }
        for (int i = 0; i < n; i++) {
            cout << a[i] << " \n"[i == n - 1];
        }
    }
    return 0;
}