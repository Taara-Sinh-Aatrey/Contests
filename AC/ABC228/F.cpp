#include "bits/stdc++.h"
using namespace std;

bool debug;
template <typename T, typename U> istream& operator>>(istream &is, pair<T, U> &p) { return is >> p.first >> p.second;}
template <typename T, typename U> ostream& operator<<(ostream &os, const pair<T, U> &p) { return debug ? os << "(" << p.first << ", " << p.second << ")" : os << p.first << " " << p.second; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> istream &operator>>(istream &is, T_container &v) { for (T &x : v) is >> x; return is; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream &operator<<(ostream &os, const T_container &v) { bool f = false; if(debug) { os << "{"; for (const T &x : v) { if (f) os << ", "; os << x; f = true; } os << "}"; } else { for (const T &x : v) { if (f) os << " "; os << x; f = true; } } return os; }
void scan() {} template <typename Head, typename ...Tail> void scan(Head &H, Tail &...T) { cin >> H; scan(T...); }
void print() { cout << "\n"; } template <typename Head> void print(const Head &H) { cout << H << "\n"; } template <typename Head, typename ...Tail> void print(const Head &H, const Tail &...T) { cout << H << " "; print(T...); }
template <typename T, typename T1, typename... Tail> T amin(T& a, T1 b, Tail... c) { if(b < a) a = b; if constexpr (sizeof...(c) != 0) { amin(a, c...); } return a; } template <typename T, typename T1, typename... Tail> T amax(T& a, T1 b, Tail... c) { if(b > a) a = b; if constexpr (sizeof...(c) != 0) { amax(a, c...); } return a; }
void dbg_out() { cerr << "\n"; } template <typename Head, typename ...Tail> void dbg_out(const Head &H, const Tail &...T) { cerr << " " << H; dbg_out(T...); }
#ifndef ONLINE_JUDGE
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]:", debug = true, dbg_out(__VA_ARGS__), debug = false
#else
#define dbg(...)
#endif

#define int int64_t
const int inf = 1e18L + 5, mod = 1e9 + 7, N = 2e5 + 5;

template <typename T, class F = function<T(const T&, const T&)>>
class SparseTable {
public:
    int n;
    vector<vector<T>> mat;
    F func;

    SparseTable(const vector<T>& a, const F& f) : func(f) {
        n = static_cast<int>(a.size());
        int max_log = 64 - __builtin_clzll(n);
        mat.resize(max_log);
        mat[0] = a;
        for (int j = 1; j < max_log; j++) {
            mat[j].resize(n - (1 << j) + 1);
            for (int i = 0; i <= n - (1 << j); i++) {
                mat[j][i] = func(mat[j - 1][i], mat[j - 1][i + (1 << (j - 1))]);
            }
        }
    }

    T get(int from, int to) const {
        assert(0 <= from && from <= to && to <= n - 1);
        int lg = 64 - __builtin_clzll(to - from + 1) - 1;
        return func(mat[lg][from], mat[lg][to - (1 << lg) + 1]);
    }
};

void solve() {
    int h, w, h1, w1, h2, w2;
    scan(h, w, h1, w1, h2, w2);
    amin(h2, h1);
    amin(w2, w1);
    vector<vector<int>> a(h, vector<int>(w));
    scan(a);
    vector<vector<int>> f(h + 1, vector<int>(w + 1));
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            f[i][j] = f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1] + a[i - 1][j - 1];
        }
    }
    vector<vector<int>> b(h - h2 + 1, vector<int>(w - w2 + 1));
    for (int i = 0; i <= h - h2; i++) {
        for (int j = 0; j <= w - w2; j++) {
            b[i][j] = f[i + h2][j + w2] - f[i][j + w2] - f[i + h2][j] + f[i][j];
        }
    }
    vector<vector<int>> c(h - h2 + 1, vector<int>(w - w1 + 1));
    for (int i = 0; i <= h - h2; i++) {
        SparseTable<int> st(b[i], [&](int i, int j) { return max(i, j); });
        for (int j = 0; j <= w - w1; j++) {
            c[i][j] = st.get(j, j + (w1 - w2));
        }
    }
    vector<vector<int>> d(h - h1 + 1, vector<int>(w - w1 + 1));
        for (int j = 0; j <= w - w1; j++) {
        vector<int> col(h - h2 + 1);
        for (int i = 0; i <= h - h2; i++) {
            col[i] = c[i][j];
        }
        SparseTable<int> st(col, [&](int i, int j) { return max(i, j); });
        for (int i = 0; i <= h - h1; i++) {
            d[i][j] = st.get(i, i + (h1 - h2));
        }
    }
    int ans = 0;
    for (int i = 0; i <= h - h1; i++) {
        for (int j = 0; j <= w - w1; j++) {
            ans = max(ans, f[i + h1][j + w1] - f[i][j + w1] - f[i + h1][j] + f[i][j] - d[i][j]);
        }
    }
    print(ans);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
    return 0;
}
