/**
 *    author:  Taara Sinh Aatrey
 *    created: 14.08.2022 15:25:13
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
        int x;
        cin >> x;
        bool ok = false;
        for (int a = 1; a * a <= x; a++) {
            int b_low = 1, b_high = (x + a - 1) / a;
            while (b_low <= b_high) {
                int b = (b_low + b_high) / 2;
                int64_t sum = 2 * a + 2 * b + a * int64_t(b);
                if (sum == x) {
                    ok = true;
                    break;
                }
                if (sum > x) {
                    b_high = b - 1;
                }
                else {
                    b_low = b + 1;
                }
            }
            if (ok) break;
        }
        cout << (ok ? "YES" : "NO") << '\n';
    }
    return 0;
}