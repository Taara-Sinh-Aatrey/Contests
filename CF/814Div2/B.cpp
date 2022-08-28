/**
 *    author:  Taara Sinh Aatrey
 *    created: 16.08.2022 22:42:32
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
    for (int tt = 1; tt <= t; tt++) {
        int n, k;
        cin >> n >> k;
        if (k % 4 == 0) {
            cout << "NO" << '\n';
            continue;
        }
        cout << "YES" << '\n';
        if (k % 2 == 1) {
            for (int i = 1; i <= n; i += 2) {
                cout << i << " " << i + 1 << '\n';
            }
        }
        else {
            for (int i = 1; i + 3 <= n; i += 4) {
                cout << i << " " << i + 3 << '\n';
                cout << i + 1 << " " << i + 2 << '\n';
            }
            if (n % 4 == 2) {
                cout << n << " " << n - 1 << '\n';
            } 
        }
    }
    return 0;
}