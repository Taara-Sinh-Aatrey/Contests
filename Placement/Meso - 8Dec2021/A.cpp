#include "bits/stdc++.h"    
using namespace std;

bool debug;
template <typename T, typename U> istream& operator>>(istream &is, pair<T, U> &p) { return is >> p.first >> p.second; }
template <typename T, typename U> ostream& operator<<(ostream &os, const pair<T, U> &p) { return debug ? os << "(" << p.first << ", " << p.second << ")" : os << p.first << " " << p.second; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> istream &operator>>(istream &is, T_container &v) { for (T &x : v) is >> x; return is; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream &operator<<(ostream &os, const T_container &v) { bool f = false; if(debug) { os << "["; for (const T &x : v) { if (f) os << ", "; os << x; f = true; } os << "]"; } else { for (const T &x : v) { if (f) os << " "; os << x; f = true; } } return os; }
void scan() {} template <typename Head, typename ...Tail> void scan(Head &H, Tail &...T) { cin >> H; scan(T...); }
void print() { cout << "\n"; } template <typename Head> void print(const Head &H) { cout << H << "\n"; } template <typename Head, typename ...Tail> void print(const Head &H, const Tail &...T) { cout << H << " "; print(T...); }
template <typename Head> void dbg_out(string var, const Head &H) { cerr << var << " = " << H << endl; } template <typename Head, typename ...Tail> void dbg_out(string var, const Head &H, const Tail &...T) { for (int i = 0, b = 0; i < int(var.size()); i++) { if (var[i] == '(' || var[i] == '{') { b++; } else if (var[i] == ')' || var[i] == '}') { b--; } else if (var[i] == ',' && b == 0) { cerr << var.substr(0, i) << " = " << H << " | "; dbg_out(var.substr(var.find_first_not_of(' ', i + 1)), T...); break; } } }
template <typename T, typename T1, typename... Tail> T amin(T& a, T1 b, Tail... c) { if(b < a) a = b; if constexpr (sizeof...(c) != 0) { amin(a, c...); } return a; } template <typename T, typename T1, typename... Tail> T amax(T& a, T1 b, Tail... c) { if(b > a) a = b; if constexpr (sizeof...(c) != 0) { amax(a, c...); } return a; }
#ifndef ONLINE_JUDGE
#define dbg(...) debug = true, dbg_out(#__VA_ARGS__, __VA_ARGS__), debug = false
#else
#define dbg(...)
#endif

class dsu {
public:
    vector<int> p, mx;
    int n;

    dsu(int _n) : n(_n) {
        p.resize(n);
        mx.resize(n);
        iota(p.begin(), p.end(), 0);
        iota(mx.begin(), mx.end(), 1);
    }

    inline int get(int x) {
        return (x == p[x] ? x : (p[x] = get(p[x])));
    }

    inline long unite(int x, int y) {
        x = get(x);
        y = get(y);
        long change = 0;
        if (x != y) {
            p[x] = y;
            change += max(mx[y], mx[x]) - (mx[x] + mx[y]);
            mx[y] = max(mx[y], mx[x]);
            mx[x] = 0;
        }
        return change;
    }
};

vector<long> networkSums(int n, vector<int> from, vector<int> to) {
    int m = from.size();
    long sum = n * 1LL * (n + 1) / 2;
    dsu d(n);
    vector<long> ans(m);
    for (int i = 0; i < m; i++) {
        int u = from[i], v = to[i];
        --u, --v;
        sum += d.unite(u, v);
        ans[i] = sum;
    }
    return ans;
}

signed main() {
    print(networkSums(5, {1, 2, 1, 4}, {2, 3, 3, 5}));
    print(networkSums(2, {1, 2}, {2, 1}));
    print(networkSums(1, {1}, {1}));
    return 0;
}