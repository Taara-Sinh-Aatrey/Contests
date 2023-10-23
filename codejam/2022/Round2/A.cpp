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
    int n, k;
    scan(n, k);
    if (k % 2 == 1 || k < 2 * (n / 2)) {
        print("IMPOSSIBLE");
        return;
    }
    vector<int> cnt(n / 2 + 2);
    for (int i = 1; i <= n / 2 + 1; i++) {
        cnt[i] = cnt[i - 1] + max<int>(1, (n - (i - 1) * 2) * 4 - 4);
    }
    auto get_val = [&] (int R, int C) {
        int x = min({R, n + 1 - R, C, n + 1 - C});
        int r = x, c = x, val = cnt[x - 1] + 1;
        int skip = n - (x - 1) * 2 - 1;
        if (r == R) {
            val += C - c;
            return val;
        }
        val += skip;
        c += skip;
        if (c == C) {
            val += R - r;
            return val;
        }
        val += skip;
        r += skip;
        if (r == R) {
            val += c - C;
            return val;
        }
        val += skip;
        c -= skip;
        assert(c == C);
        val += r - R;
        return val;
    };
    const int dx[] = {-1, 0, 1, 0};
    const int dy[] = {0, -1, 0, 1};
    auto farthest_next = [&] (int r, int c) {
        int fr, fc;
        int mx = -inf;
        for (int dir = 0; dir < 4; dir++) {
            int nr = r + dx[dir];
            int nc = c + dy[dir];
            if (nr < 1 || nr > n || nc < 1 || nc > n) {
                continue;
            }
            int nval = get_val(nr, nc);
            if (nval > mx) {
                mx = nval;
                fr = nr;
                fc = nc;
            }
        }
        return pair(fr, fc);
    };
    vector<pair<int, int>> ans;
    int to_skip = n * n - 1 - k;
    int mxv = 0;
    auto process = [&] (int r, int c, int v) {
        if (v < mxv) {
            return;
        }
        auto [fr, fc] = farthest_next(r, c);
        auto fv = get_val(fr, fc);
        int diff = fv - (v + 1);
        if (diff > 0 && diff <= to_skip) {
            ans.emplace_back(v, fv);
            mxv = fv;
            to_skip -= diff;
        }    
    };
    for (int ring = 1; ring <= n / 2; ring++) {
        int len = n - (ring - 1) * 2 - 1;
        int v = cnt[ring - 1] + 1 + len / 2;
        int r = ring, c = ring + len / 2;
        process(r, c, v);
        v += len;
        c += len / 2;
        r += len / 2;
        process(r, c, v);
        v += len;
        r += len / 2;
        c -= len / 2;
        process(r, c, v);
        v += len;
        c -= len / 2;
        r -= len / 2;
        process(r, c, v);
    }
    print(ans.size());
    for (auto &p : ans) {
        print(p);
    }
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