/**
 *    author:  Taara Sinh Aatrey
 *    created: 21.08.2022 17:45:45
**/

#include "bits/stdc++.h"

using namespace std;

#ifdef AATREY_DEBUG
#include "debug.hpp"
#else
#define dbg(...)
#endif

int main() {
#define int int64_t
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, p, q, r;
    cin >> n >> p >> q >> r;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    set<int> st;
    st.emplace(0);
    int pref = 0;
    for (int i = 0; i < n; i++) {
        pref += a[i];
        st.emplace(pref);
        if (st.count(pref - r) && st.count(pref - r - q) && st.count(pref - r - q - p)) {
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
    return 0;
#undef int
}