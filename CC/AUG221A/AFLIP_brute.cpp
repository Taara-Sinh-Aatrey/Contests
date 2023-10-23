/**
 *    author:  Taara Sinh Aatrey
 *    created: 15.08.2022 03:30:25
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
        int n, m;
        cin >> n >> m;
        for (int rep = 0; rep < 2; rep++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    int x;
                    cin >> x;
                }
            }
        }
        cout << "YES" << '\n';
    }
    return 0;
}