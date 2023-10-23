/**
 *    author:  Taara Sinh Aatrey
 *    created: 04.09.2022 17:32:34
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
    int n;
    cin >> n;
    multiset<int> st;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        st.emplace(x);
    }
    int ans = 0;
    while (st.size() > 1) {
        ans++;
        auto it = prev(st.end());
        int mx = *it;
        st.erase(it);
        mx %= *st.begin();
        if (mx != 0)
            st.emplace(mx);
    }
    cout << ans;
    return 0;
}