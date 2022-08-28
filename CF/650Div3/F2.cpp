#include "bits/stdc++.h"
using namespace std;

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
    vector<int> a(n);
    scan(a);
    map<int, int> fo, lo, fr;
    for (int i = 0; i < n; i++) {
        lo[a[i]] = i;
        fr[a[i]]++;
    }
    for (int i = n - 1; i >= 0; i--) {
        fo[a[i]] = i;
    }
    vector<int> b = a;
    sort(b.begin(), b.end());
    map<int, int> dp1, dp2;
    vector<int> at(n);
    for (int i = 0; i < n; i++) {
        int x = a[i];
        // starting from x
        dp2[x]++;
        dp1[x]++;
        if (x != b[0]) {
            int y = *prev(lower_bound(b.begin(), b.end(), x));
            amax(dp2[x], dp1[y] + 1);
            if (lo[y] < i) {
                // amax(dp2[x], dp2[y] + 1); this is wrong since this can be done only if y is the first element in the sequence or y is an inner element and all of its occurence is present in the sequence that's why we need the below line which ensures that all occurence of y is present in the sequence
                amax(dp2[x], at[fo[y]] + fr[y]);
            }
        }
        amax(dp2[x], dp1[x]);
        at[i] = max(dp1[x], dp2[x]);
    }
    print(n - *max_element(at.begin(), at.end()));
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    scan(t);
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
    return 0;
}