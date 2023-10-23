#include "bits/stdc++.h"
#include <streambuf>
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

int n;
vector<int> a;
map<pair<int, int>, int> save;

int rec (int idx, int rem) {
    if (idx >= n)
        return 0;
    int need = 2 * rem - 1;
    assert(n - idx >= need);
    auto it = save.find({idx, rem});
    if (it != save.end())
        return it->second;
    save[{idx, rem}] = a[idx] + rec(idx + 2, rem - 1);
    if (n - idx > need) {
        amax(save[{idx, rem}], rec(idx + 1, rem));
    }
    return save[{idx, rem}];
};

void solve() {
    scan(n);
    a.resize(n);
    scan(a);
    int take = n / 2;
    print(rec(0, take));
}

signed main() {
#ifdef LOCAL
    freopen("after_contest_02_in", "r", stdin);
    freopen("out", "w", stdout);
    freopen("out", "w", stderr);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
    return 0;
}