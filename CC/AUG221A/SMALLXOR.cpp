/**
 *    author:  Taara Sinh Aatrey
 *    created: 14.08.2022 15:36:13
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
        int n, x, y;
        cin >> n >> x >> y;
        set<pair<int, int>> st;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            st.emplace(x, i);
        }
        while (y--) {
            auto [val, idx] = *st.begin();
            st.erase(st.begin());
            val ^= x;
            if (st.empty() || val <= st.begin()->first) {
                y %= 2;
            }
            st.emplace(val, idx);
        }
        for (int i = 0; i < n; i++) {
            cout << st.begin()->first << " \n"[i == n - 1]; 
            st.erase(st.begin());
        }
    }
    return 0;
}