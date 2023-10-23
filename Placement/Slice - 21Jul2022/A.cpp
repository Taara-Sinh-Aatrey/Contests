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
const int inf = 1e18L + 5, N = 2e5 + 5;


signed main() {
    const int mod = 1e9 + 7;
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int m;
    cin >> m;
    auto addSelf = [&] (int &x, int y) {
        x += y;
        if (x >= mod) {
            x -= mod;
        }
    };
    int ans = 0;
    for (int rep = 0; rep < 2; rep++) {
        vector<int> dp(m + 2);
        for (int i = 1; i <= m; i++) {
            dp[i] = a[0] == -1 || i == a[0];
        }
        int cur = rep;
        for (int it = 1; it < n; it++) {
            vector<int> ndp(m + 2, 0);
            if (cur == 1) {
                // should increase now
                for (int i = 1; i <= m; i++) {
                    addSelf(dp[i], dp[i - 1]);
                }
            }
            else {
                // should decrease now
                for (int i = m; i >= 1; i--) {
                    addSelf(dp[i], dp[i + 1]);
                }
            }
            for (int j = 1; j <= m; j++) {
                if (a[it] == -1 || j == a[it]) {
                    addSelf(ndp[j], dp[cur == 1 ? j - 1 : j + 1]);
                }
            }
            swap(dp, ndp);
            cur ^= 1;
        }
        for (int i = 1; i <= m; i++) {
            addSelf(ans, dp[i]);
        }
    }
    cout << ans << '\n';
    return 0;
}