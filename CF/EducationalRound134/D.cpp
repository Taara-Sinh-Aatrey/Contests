/**
 *    author:  Taara Sinh Aatrey
 *    created: 27.08.2022 20:45:28
**/

#include "bits/stdc++.h"

using namespace std;

#ifdef AATREY_DEBUG
#include "debug.hpp"
#else
#define dbg(...)
#endif

// #define int int64_t

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        const int log = 30;
        vector<int> end(n);
        end[0] = n - 1;
        for (int bit = log - 1; bit >= 0; bit--) {
            bool ok = true;
            for (int i = 0; i < n; i = end[i] + 1) {
                int j = end[i];
                int c1 = 0, c2 = 0;
                for (int x = i; x <= j; x++) {
                    c1 += a[x] >> bit & 1;
                    c2 += ~b[x] >> bit & 1;
                }
                if (c1 != c2) {
                    ok = false;
                    break;
                }
            }
            if (!ok) continue;
            for (int i = 0; i < n; ) {
                // cout << i << " " << end[i] << endl;
                int low = i, high = end[i];
                while (low < high) {
                    if (a[low] >> bit & 1) low++;
                    else if (~a[high] >> bit & 1) high--;
                    else {
                        swap(a[low++], a[high--]);
                    }
                }
                low = i, high = end[i];
                while (low < high) {
                    if (~b[low] >> bit & 1) low++;
                    else if (b[high] >> bit & 1) high--;
                    else {
                        swap(b[low++], b[high--]);
                    }
                }
                low = i, high = end[i];
                int c = 0;
                for (int x = low; x <= high; x++) {
                    c += a[x] >> bit & 1;
                }
                end[low] = low + c - 1;
                if (low + c <= high)
                    end[low + c] = high;
                i = high + 1;
            }
        }
        int ans = a[0] ^ b[0];
        for (int i = 0; i < n; i++) {
            ans &= a[i] ^ b[i];
        }
        cout << ans << endl;
    }
    return 0;
}