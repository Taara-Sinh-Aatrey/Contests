/**
 *    author:  Taara Sinh Aatrey
 *    created: 20.12.2022 08:46:44
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
        int first = 0, second = 0, both = 0;
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            if (x != i && x != n + 1 - i) {
                both++;
            }
            else if (x != i) {
                first++;
            }
            else if (x != n + 1 - i) {
                second++;
            }
        }
        if (first + both <= second) {
            cout << "First" << '\n';
        }
        else if (second + both < first) {
            cout << "Second" << '\n';
        }
        else {
            cout << "Tie" << '\n';
        }
    }
    return 0;
}