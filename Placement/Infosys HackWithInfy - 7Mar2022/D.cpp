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

vector<int> solve(int n, vector<int> a) {
    set<int> ans{0};
    vector<set<int>> save;
    set<pair<int, int>> st;
    for (auto &x : a) {
        save.emplace_back();
        save.back().emplace(x);
        ans.emplace(x);
        for (auto &p : st) {
            int val = p.first, idx = p.second;
            if (val >= x)
                break;
            for (auto &y : save[idx]) {
                save.back().emplace(x ^ y);
                ans.emplace(x ^ y);
            }
        }
        st.emplace(x, int(save.size()) - 1);
    }
    vector<int> ret;
    ret.emplace_back(ans.size());
    for (auto &x : ans)
        ret.emplace_back(x);
    return ret;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    print(solve(3, {1, 4, 1}));
    print(solve(5, {2, 1, 2, 4, 0}));
    return 0;
}