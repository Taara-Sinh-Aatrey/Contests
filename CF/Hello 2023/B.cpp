/**
 *    author:  Taara Sinh Aatrey
 *    created: 04.01.2023 23:20:30
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
        if (n == 3) {
            cout << "NO" << '\n';
            continue;            
        }
        cout << "YES" << '\n';
        int first = 1, sum = 0;
        if (n % 2 == 1) {
            sum = 1;
            first = 1 - n / 2;
        }
        int second = sum - first;
        for (int i = 0; i < n; i++) {
            cout << (i % 2 == 0 ? first : second) << ' ';
        }
        cout << '\n';
    }
    return 0;
}