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

#define msb(x) (int) (31 - __builtin_clz(x))

void solve() {
    int n, m;
    scan(n, m);
    vector<int> b(n), p(m);
    scan(b, p);
    auto check = [&] (vector<int> &vec, int target) {
        if (target % 2 == 1)
            return false;
        int nn = vec.size();
        for (int i = 0; i < 1 << nn; i++) {
            int sum = 0;
            for (int j = 0; j < nn; j++) {
                if (i >> j & 1)
                    sum += vec[j];
            }
            if (sum == target / 2) {
                return true;
            }
        }
        return false;
    };
    set<int> st;
    for (int i = 0; i < 1 << m; i++) {
        vector<int> v;
        int sum = 0;
        int x = i;
        for (int j = msb(x); x > 0; j = msb(x)) {
            v.push_back(p[j]);
            sum += p[j];
            x ^= 1 << j;
        }
        if (!st.count(sum) && check(v, sum)) {
            st.emplace(sum);
        }
    }
    set<int> ns;
    for (int &bar : b) {
        for (auto & c : st) {
            ns.insert(bar + c);
        }
    }
    for (auto &d : ns) {
        print(d);
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
    return 0;
}