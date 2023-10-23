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
    int n, l;
    scan(n, l);
    vector<int> a(n), dir(n);
    for (int i = 0; i < n; i++) {
        scan(a[i], dir[i]);
    }
    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&] (auto &i, auto &j) {
        return a[i] < a[j];
    });
    vector<pair<int, int>> ts;
    for (int i = 0; i < n; i++) {
        if (dir[i] == 0) {
            ts.emplace_back(a[i], 0);
        }
        else {
            ts.emplace_back(l - a[i], 1);
        }
    }
    sort(ts.begin(), ts.end());
    vector<int> ans;
    int low = 0, high = n - 1;
    for (int i = 0, j; i < n; i = j) {
        j = i;
        vector<int> v;
        while (j < n && ts[j].first == ts[i].first) {
            if (ts[j].second == 0) {
                v.emplace_back(ord[low++] + 1);
            }
            else {
                v.emplace_back(ord[high--] + 1);
            }
            j++;
        }
        sort(v.begin(), v.end());
        for (auto &x : v) {
            ans.emplace_back(x);
        }
    }
    print(ans);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    scan(t);
    for (int tt = 1; tt <= t; tt++) {
        cout << "Case #" << tt << ": ";
        solve();
    }
    return 0;
}