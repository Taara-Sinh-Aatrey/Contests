/**
 *    author:  Taara Sinh Aatrey
 *    created: 04.01.2023 23:33:55
**/

#include "bits/stdc++.h"

using namespace std;

#ifdef AATREY_DEBUG
#include "debug.hpp"
#else
#define dbg(...)
#endif

#define int int64_t

const int inf = 1e18L + 5;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int testcases;
    cin >> testcases;
    for (int caseno = 1; caseno <= testcases; caseno++) {
        int n, m;
        cin >> n >> m, --m;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int ans = 0;
        {
            int i = m - 1, cur = 0;
            multiset<int> st;
            while (i >= 0) {
                cur -= a[i + 1];
                st.emplace(a[i + 1]);
                while (cur < 0) {
                    assert(!st.empty() && *st.rbegin() > 0);
                    auto it = prev(st.end());
                    cur += 2 * *it;
                    st.erase(it);
                    ans++;
                }
                i--;
            }
        }
        {
            int i = m + 1, cur = 0;
            multiset<int> st;
            while (i < n) {
                cur += a[i];
                st.emplace(a[i]);
                while (cur < 0) {
                    assert(!st.empty() && *st.begin() < 0);
                    auto it = st.begin();
                    cur -= 2 * *it;
                    st.erase(it);
                    ans++;
                }
                i++;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}