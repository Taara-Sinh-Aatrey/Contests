/**
 *    author:  Taara Sinh Aatrey
 *    created: 18.03.2023 20:06:43
**/

#include "bits/stdc++.h"

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// functions: set.insert(val), *(set.find_by_order(order-1)), set.order_of_key(val)
// less_equal for multiset

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
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (auto &x : a) {
            cin >> x;
        }
        oset<pair<int, int>> st;
        const int LOG = 30;
        vector<int> nearest(LOG, n);
        vector<int> suff(n + 1);
        st.insert({suff[n], n});
        for (int i = n - 1; i >= 0; i--) {
            suff[i] = suff[i + 1];
            for (int bit = 0; bit < LOG; bit++) {
                if (a[i] >> bit & 1) {
                    nearest[bit] = i;
                }
                suff[i] += (1 << bit) * (n - nearest[bit]);
            }
            st.insert({suff[i], i});
        }
        dbg(st);
        nearest = vector<int>(LOG, -1);
        st.erase({suff[0], 0});
        int ans = st.order_of_key({k, inf});
        dbg(ans);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            for (int bit = 0; bit < LOG; bit++) {
                if (a[i] >> bit & 1) {
                    nearest[bit] = i;
                }
                sum += (1 << bit) * (nearest[bit] + 1);
            }
            st.erase({suff[i + 1], i + 1});
            ans += st.order_of_key({k - sum, inf});
            dbg(st, k - sum, ans);
        }
        cout << ans << '\n';
    }
    return 0;
}