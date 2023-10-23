/**
 *    author:  Taara Sinh Aatrey
 *    created: 14.08.2022 15:15:00
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
        int a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);
        while (a < b) a <<= 1;
        cout << (a == b ? "YES" : "NO") << '\n';
    }
    return 0;
}