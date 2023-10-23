/**
 *    author:  Taara Sinh Aatrey
 *    created: 21.08.2022 09:15:34
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
        cout << "Case #" << tt << ": ";
        int n;
        cin >> n;
        vector<int> a(n);
        multiset<int> s;
        for (auto &x : a) {
            cin >> x;
            s.emplace(x);
        }
        for (auto &x : a) {
            s.erase(s.find(x));
            cout << (s.empty() || *s.begin() > 2 * x ? -1 : *prev(s.upper_bound(2 * x))) << ' ';
            s.emplace(x);
        }
        cout << '\n';
    }
    return 0;
}