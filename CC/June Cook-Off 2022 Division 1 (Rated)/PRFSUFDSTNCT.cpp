#include "bits/stdc++.h"
#include <filesystem>
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

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int rand(int a, int b) { return uniform_int_distribution<int>(a, b)(rng); }

void solve() {
    int n = 6;
    scan(n);
    vector<int> p(n), s(n);
    scan(p, s);
    set<int> st;
    for (int i = 0; i < 2 * n; i++) {
        st.insert(i);
    }
    vector<int> a(n);
    set<int> must_be_duplicated;
    set<int> can_be_duplicated;
    for (int i = 0; i < n; i++) {
        if (i == 0 || p[i] > p[i - 1]) {
            // unique
            a[i] = *st.begin();
            st.erase(st.begin());
            can_be_duplicated.insert(a[i]);
            if (i + 1 < n && s[i] > s[i + 1]) {
                // cant_be_duplicated
                can_be_duplicated.erase(a[i]);
            }
            else if (i + 1 < n) {
                must_be_duplicated.insert(a[i]);
            }
            continue;
        }
        if (!must_be_duplicated.empty()) {
            a[i] = *must_be_duplicated.begin();
            must_be_duplicated.erase(must_be_duplicated.begin());
            if (i + 1 < n && s[i] == s[i + 1]) {
                must_be_duplicated.insert(a[i]);
            }
        }
        else {
            if (can_be_duplicated.empty()) {
                print("NO");
                return;
            }
            a[i] = *can_be_duplicated.begin();
        }
    }
    vector<int> P(n), S(n);
    st.clear();
    for (int i = 0; i < n; i++) {
        st.insert(a[i]);
        P[i] = st.size();
    }
    st.clear();
    for (int i = n - 1; i >= 0; i--) {
        st.insert(a[i]);
        S[i] = st.size();
    }
    print(P == p && S == s ? "YES" : "NO");
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