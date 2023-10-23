#include "bits/stdc++.h"
#include <random>
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

int solve3(int x, int y) {
    if (x < y) {
        swap(x, y);
    }
    int ans = min({x / 2, y, x - y});
    x -= ans * 2;
    y -= ans;
    x -= 2;
    y -= 1;
    ans++;
    x = abs(x);
    y = abs(y);
    if (x < y) {
        swap(x, y);
    }
    int c = min(x, y) / 3;
    ans += 2 * c;
    x -= 3 * c;
    y -= 3 * c;
    assert(x >= y);
    ans += 2 * (x / 4);
    while (x >= 2 && y >= 1) {
        ans++;
        x -= 2;
        y -= 1;
    }
    while (x >= 1 && y >= 2) {
        ans++;
        x -= 1;
        y -= 2;
    }
    if (!(x == 0 && y == 0)) {
        // 0 1
        // 0 2
        // 0 3 
        // 1 1 
        ans += 2 + ((x + y) % 2 == 1);
    }
    // print(ans);
    return ans;
}

int solve2(int x, int y) {
    if (x < y) {
        swap(x, y);
    }
    int ans = min({x / 2, y, x - y});
    x -= ans * 2;
    y -= ans;
    int c = min(x, y) / 3;
    ans += 2 * c;
    x -= 3 * c;
    y -= 3 * c;
    assert(x >= y);
    ans += 2 * (x / 4);
    while (x >= 2 && y >= 1) {
        ans++;
        x -= 2;
        y -= 1;
    }
    while (x >= 1 && y >= 2) {
        ans++;
        x -= 1;
        y -= 2;
    }
    if (!(x == 0 && y == 0)) {
        // 0 1
        // 0 2
        // 0 3 
        // 1 1 
        ans += 2 + ((x + y) % 2 == 1);
    }
    // print(ans);
    return ans;
}

int solve4(int x, int y) {
    // int x, y;
    // scan(x, y);
    if (x < y) {
        swap(x, y);
    }
    // int ans = min({x / 2, y, x - y});
    // x -= ans * 2;
    // y -= ans;
    int ans = 0;
    int c = min(x, y) / 3;
    ans += 2 * c;
    x -= 3 * c;
    y -= 3 * c;
    x -= 2;
    y -= 1;
    ans++;
    x = abs(x);
    y = abs(y);
    if (x < y) {
        swap(x, y);
    }
    c = min({x / 2, y, x - y});
    x -= c * 2;
    y -= c;
    ans += c;
    ans += 2 * (x / 4);
    while (x >= 2 && y >= 1) {
        ans++;
        x -= 2;
        y -= 1;
    }
    while (x >= 1 && y >= 2) {
        ans++;
        x -= 1;
        y -= 2;
    }
    if (!(x == 0 && y == 0)) {
        // 0 1
        // 0 2
        // 0 3 
        // 1 1 
        ans += 2 + ((x + y) % 2 == 1);
    }
    // print(ans);
    return ans;
}

int solve1(int x, int y) {
    // int x, y;
    // scan(x, y);
    if (x < y) {
        swap(x, y);
    }
    // int ans = min({x / 2, y, x - y});
    // x -= ans * 2;
    // y -= ans;
    int ans = 0;
    int c = min(x, y) / 3;
    ans += 2 * c;
    x -= 3 * c;
    y -= 3 * c;
    c = min({x / 2, y, x - y});
    x -= c * 2;
    y -= c;
    ans += c;
    ans += 2 * (x / 4);
    while (x >= 2 && y >= 1) {
        ans++;
        x -= 2;
        y -= 1;
    }
    while (x >= 1 && y >= 2) {
        ans++;
        x -= 1;
        y -= 2;
    }
    if (!(x == 0 && y == 0)) {
        // 0 1
        // 0 2
        // 0 3 
        // 1 1 
        ans += 2 + ((x + y) % 2 == 1);
    }
    // print(ans);
    return ans;
}

map<pair<int, int>, int> mp;
const int lim = 7;

int solve(int X, int Y) {
    int ans = inf;
    for (int x = -lim; x <= lim; x++) {
        for (int y = -lim; y <= lim; y++) {
            int rx = abs(X - x), ry = abs(Y - y);
            amin(ans, mp[{x, y}] + min({solve1(rx, ry), solve2(rx, ry)}));
        }
    }
    return ans;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    scan(t);
    mp[{0, 0}] = 0;
    queue<pair<int, int>> q;
    q.emplace(0, 0);
    const int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
    const int dy[] = {1, -1, 2, -2, 2, -2, 1, -1};
    int ops = 0;
    int ans = inf;
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        ops++; 
        for (int dir = 0; dir < 8; dir++) {
            int nx = x + dx[dir], ny = y + dy[dir];
            if (mp.count({nx, ny}) && mp[{nx, ny}] <= mp[{x, y}] + 1)
                continue;
            if (abs(nx) > lim || abs(ny) > lim)
                continue;
            mp[{nx, ny}] = mp[{x, y}] + 1;
            q.emplace(nx, ny);
        }
    }
    for (int tt = 1; tt <= t; tt++) {
        // solve();
        // int x = rand(0, 10), y = rand(0, 10);
        int x, y;
        scan(x, y);
        print(solve(x, y));
        // if (mp[{x, y}] != min({solve1(x, y), solve2(x, y), solve3(x, y), solve4(x, y)})) {
        //     dbg(x, y);
        //     dbg(mp[{x, y}], solve1(x, y), solve2(x, y));
        //     break;
        // }
    }
    return 0;
}

/*
2 1
2 1
-1 2

2 1
2 -1
1 2

2 -1
2 1
2 -1
2 -1
1 2
*/