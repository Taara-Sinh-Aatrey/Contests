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
void dbg_out() { cerr << "\n"; } template <typename Head, typename ...Tail> void dbg_
#ifndef ONLINE_JUDGE
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]:", debug = true, dbg_out(__VA_ARGS__), debug = false
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
    map<int, int> mp;
    for (int i = 0, j; i < n - 1; i = j) {
        j = i + 1;
        int x = -1;
        while (j < n) {
            int y = a[j] > a[j - 1];
            if (a[j] != a[j - 1]) {
                if (x == -1)
                    x = y;
                else if (x != y)
                    break;
            }
            j++;
        }
        j--;
        if (abs(a[j] - a[i]) <= 1) continue;
        mp[min(a[i], a[j]) + 1]++;
        mp[max(a[i], a[j])]--;
    }
    vector<int> mn(n - 1, inf), mx(n - 1, -inf);
    for (auto it = mp.begin(); it != mp.end(); it++) {
        if (next(it) == mp.end()) break;
        next(it)->second += it->second;
        int lo = it->first, hi = next(it)->first - 1, len = it->second;
        if (len == 0) continue;
        amin(mn[len - 1], lo);
        amax(mx[len - 1], hi);
    }
    int mini = inf, maxi = -inf;
    for (int len = n - 3; len >= 0; len--) {
        amin(mn[len], mn[len + 1]);
        amax(mx[len], mx[len + 1]);
    }
    for (int i = 0; i < n; i++) {
        if (mn[i] >= inf) {
            mn[i] = mx[i] = -1;
        }
    }
    print(mn);
    print(mx);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
    return 0;
}