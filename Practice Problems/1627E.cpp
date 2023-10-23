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

template<typename T>
void upd(map<T, int> &mp, T key, int val) {
    if (mp.count(key))
        amin(mp[key], val);
    else
        mp[key] = val;
};

void solve() {
    int n, m, k;
    scan(n, m, k);
    vector<int> x(n);
    scan(x);
    map<array<int, 2>, vector<array<int, 3>>> ladders;
    map<int, int> dis[n];
    while (k--) {
        int a, b, c, d, h;
        scan(a, b, c, d, h);
        --a, --b, --c, --d;
        ladders[{a, b}].push_back({c, d, h});
        dis[a][b] = inf;
    }
    dis[n - 1][m - 1] = inf;
    dis[0][0] = 0;
    for (int floor = 0; floor < n; floor++) {
        // propagate the answer of rooms to one another
        pair<int, int> pv;
        for (auto it = dis[floor].begin(); it != dis[floor].end(); it++) {
            if (it != dis[floor].begin())
                amin(it->second, pv.second + x[floor] * abs(it->first - pv.first));
            pv = *it;
        }
        for (auto it = dis[floor].rbegin(); it != dis[floor].rend(); it++) {
            if (it != dis[floor].rbegin())
                amin(it->second, pv.second + x[floor] * abs(it->first - pv.first));
            pv = *it;
        }
        for (auto &[room, d] : dis[floor]) {
            for (auto &[nfloor, nroom, h] : ladders[{floor, room}]) {
                if (d < inf)
                    upd(dis[nfloor], nroom, d - h);
            }
        }
    }
    if (dis[n - 1][m - 1] < inf)
        print(dis[n - 1][m - 1]);
    else
        print("NO ESCAPE");
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