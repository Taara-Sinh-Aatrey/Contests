#include "bits/stdc++.h"
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// functions: set.insert(val), *(set.find_by_order(order-1)), set.order_of_key(val)
// less_equal for multiset

template <typename T, typename U> istream& operator>>(istream &is, pair<T, U> &p) { return is >> p.first >> p.second; }
template <typename T, typename U> ostream& operator<<(ostream &os, const pair<T, U> &p) { return os << p.first << " " << p.second; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> istream &operator>>(istream &is, T_container &v) { for (T &x : v) is >> x; return is; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream &operator<<(ostream &os, const T_container &v) { bool f = false; for (const T &x : v) { if (f) os << " "; os << x; f = true; } return os; }
void scan() {} template <typename Head, typename ...Tail> void scan(Head &H, Tail &...T) { cin >> H; scan(T...); }
void print() { cout << "\n"; } template <typename Head> void print(const Head &H) { cout << H << "\n"; } template <typename Head, typename ...Tail> void print(const Head &H, const Tail &...T) { cout << H << " "; print(T...); }
template <typename T, typename T1, typename... Tail> T amin(T& a, T1 b, Tail... c) { if(b < a) a = b; if constexpr (sizeof...(c) != 0) { amin(a, c...); } return a; } template <typename T, typename T1, typename... Tail> T amax(T& a, T1 b, Tail... c) { if(b > a) a = b; if constexpr (sizeof...(c) != 0) { amax(a, c...); } return a; }

#ifdef LOCAL
#include "debug.hpp"
#else
#define dbg(...)
#endif

#define int int64_t
const int inf = 1e18L + 5, mod = 1e9 + 7, N = 2e5 + 5;

void solve() {
    int n;
    scan(n);
    vector<int> a(n), b(n);
    scan(a, b);
    {
        map<int, vector<int>> idx;
        for (int i = 0; i < n; i++) {
            idx[b[i]].emplace_back(i);
        }
        int cnt = 0;
        for (auto &[_, vec] : idx) {
            for (auto &i : vec) {
                b[i] = cnt++;
            }
        }
    }
    vector<vector<int>> idx(n);
    for (int i = 0; i < n; i++) {
        a[i]--;
        idx[a[i]].emplace_back(i);
    }
    map<int, int> where;
    for (int i = 0; i < n; i++) {
        where[b[i]] = i;
    }
    oset<int> st;
    int ans = 0;
    map<int, int> mp;
    for (int it = 0; it < n; it++) {
        int i = where[it];
        int clr = a[i];
        int cnt = st.size() - st.order_of_key(i);
        int actual_i = i + cnt;
        // dbg(i, cnt);
        int swaps = actual_i - it;
        dbg(swaps);
        dbg(clr, idx[clr]);
        swaps -= lower_bound(idx[clr].begin(), idx[clr].end(), i) - idx[clr].begin();
        // dbg(swaps);
        swaps += mp[clr];
        dbg(swaps);
        st.insert(i);
        ans += swaps;
        mp[a[i]]++;
    }
    print(ans);
}

// 1 5 2 2 1
// 3 2 1 2 1

// 2

// 2 1 5 2 1
// 1 3 2 2 1

// 2

// 2 1 1 5 2
// 1 1 3 2 2

// 1

// 2 1 5 1 2
// 1 1 2 3 2

// 1

// 2 1 5 2 1
// 1 1 2 2 3






signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
    return 0;
}