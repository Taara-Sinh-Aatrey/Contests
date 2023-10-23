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
const int inf = 9e18L + 5, mod = 1e9 + 7, N = 2e5 + 5;

void solve() {
    int n;
    scan(n);
    vector<pair<int, int>> a(n), b(n + 1);
    scan(a, b);
    vector<vector<int>> D(n, vector<int>(n + 1));
    for (int i = 0; i < n; i++) {
        int mn = inf;
        for (int j = 0; j <= n; j++) {
            D[i][j] = (b[j].first - a[i].first) * (b[j].first - a[i].first) + (b[j].second - a[i].second) * (b[j].second - a[i].second);
            amin(mn, D[i][j]);
        }
        int cnt = 0;
        for (int j = 0; j <= n; j++) {
            cnt += D[i][j] == mn;
        }
        if (cnt == 1 && D[i][0] == mn) {
            print("IMPOSSIBLE");
            return;
        }
    }
    vector<bool> taken(n + 1);
    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);
    vector<int> choices, sweets;
    function<bool(int)> rec = [&] (int idx) {
        if (idx >= n) {
            sweets = choices;
            return true;
        }
        int child = ord[idx];
        vector<int> dist(n + 1, inf);
        int mn = inf;
        for (int sweet = 0; sweet <= n; sweet++) {
            if (!taken[sweet]) {
                dist[sweet] = D[child][sweet];
                amin(mn, dist[sweet]);
            }
        }
        for (int sweet = 1; sweet <= n; sweet++) {
            if (dist[sweet] == mn) {
                taken[sweet] = true;
                choices.emplace_back(sweet);
                if (rec(idx + 1)) {
                    return true;
                }
                choices.pop_back();
                taken[sweet] = false;
            }
        }
        return false;
    };
    do {
        if (rec(0)) {
            print("POSSIBLE");
            for (int i = 0; i < n; i++) {
                print(ord[i] + 1, sweets[i] + 1);
            }
            return;
        }
    } while (next_permutation(ord.begin(), ord.end()));
    print("IMPOSSIBLE");
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