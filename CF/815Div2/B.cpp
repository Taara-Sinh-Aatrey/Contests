/**
 *    author:  Taara Sinh Aatrey
 *    created: 21.08.2022 22:13:39
**/

#include "bits/stdc++.h"

using namespace std;

#ifdef AATREY_DEBUG
#include "debug.hpp"
#else
#define dbg(...)
#endif

int get_nth_element(vector<int> &a, int n) {
    assert(0 <= n && n < a.size());
    nth_element(a.begin(), a.begin() + n, a.end());
    return a[n];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &x : a)
            cin >> x;
        cout << (get_nth_element(a, n - 1) + get_nth_element(a, n - 2) - get_nth_element(a, 0) - get_nth_element(a, 1)) << '\n';
    }
    return 0;
}