/**
 *    author:  Taara Sinh Aatrey
 *    created: 21.08.2022 23:29:48
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
        int n;
        cin >> n;
        if ((n % 100 == 0 && n % 400 == 0) || (n % 100 && n % 4 == 0)) {
            cout << "February 29" << '\n';
        }
        else {
            cout << "March 1" << '\n';
        }
    }
    return 0;
}