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
const int inf = 1e18L + 5, mod = 1e9 + 7, N = 2500 + 5;

const int base = 1e9;

#define ld long double

#define data data69

const ld eps = 1e-9;

struct data {
    int x;
    ld y;
    data (int num) {
        x = 0;
        y = num;
        while (y >= base) {
            y /= base;
            x++;
        }    
    };
    void operator *= (const data &other) {
        x += other.x;
        y *= other.y;
        while (y >= base) {
            y /= base;
            x++;
        }
    }
    bool operator < (const data &other) const {
        return x < other.x || (x == other.x && y < other.y);
    }
    bool operator > (const data &other) const {
        return x > other.x || (x == other.x && y > other.y);
    }
    bool operator == (const data &other) const {
        return x == other.x && abs(y - other.y) <= eps;
    }
};

vector<data> fact;

void solve() {
    vector<int> n(3);
    scan(n);
    vector<vector<int>> a(3);
    vector<data> b(3, data(1));
    for (int i = 0; i < 3; i++) {
        a[i].resize(n[i]);
        scan(a[i]);
        for (auto &x : a[i]) {
            b[i] *= fact[x];
        }
    }
    int ind = max_element(b.begin(), b.end()) - b.begin();
    sort(b.begin(), b.end());
    if (b[1] == b[2]) {
        print("TIE");
        return;
    }
    print(char('A' + ind));
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    scan(t);
    fact.resize(N, data(1));
    fact[0] = data(1);
    for (int i = 1; i < N; i++) {
        fact[i] = fact[i - 1];
        fact[i] *= data(i);
    }
    for (int tt = 1; tt <= t; tt++) {
        cout << "Case #" << tt << ": ";
        solve();
    }
    return 0;
}