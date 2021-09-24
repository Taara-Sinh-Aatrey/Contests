#include "bits/stdc++.h"
#include <exception>
using namespace std;

bool debug;
template <typename T, typename U> istream& operator>>(istream &is, pair<T, U> &p) { return is >> p.first >> p.second;}
template <typename T, typename U> ostream& operator<<(ostream &os, const pair<T, U> &p) { return debug ? os << "(" << p.first << ", " << p.second << ")" : os << p.first << " " << p.second; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> istream &operator>>(istream &is, T_container &v) { for (T &x : v) is >> x; return is; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream &operator<<(ostream &os, const T_container &v) { bool f = false; if(debug) { os << "{"; for (const T &x : v) { if (f) os << ", "; os << x; f = true; } os << "}"; } else { for (const T &x : v) { if (f) os << " "; os << x; f = true; } } return os; }
void scan() {} template <typename Head, typename ...Tail> void scan(Head &H, Tail &...T) { cin >> H; scan(T...); }
void print() { cout << "\n"; } template <typename Head> void print(const Head &H) { cout << H << "\n"; } template <typename Head, typename ...Tail> void print(const Head &H, const Tail &...T) { cout << H << " "; print(T...); }
void dbg_out() { cerr << "\n"; } template <typename Head, typename ...Tail> void dbg_out(const Head &H, const Tail &...T) { cerr << " " << H; dbg_out(T...); }
#ifndef ONLINE_JUDGE
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]:", debug = true, dbg_out(__VA_ARGS__), debug = false
#else
#define dbg(...)
#endif

#define int int64_t
const int inf = 1e18L + 5, mod = 1e9 + 7, N = 2e5 + 5;

void solve() {
    int n, m, e, k;
    scan(n, m, e, k);
    auto read = [&](int sz, int md) {
        vector<int> a(sz);
        for (int i = 0; i < k; i++) {
            cin >> a[i];
        }
        int x, y, z;
        cin >> x >> y >> z;
        for (int i = k; i < sz; i++) {
            a[i] = a[i - 2] * x + a[i - 1] * y + z;
            a[i] %= md;
        }
        return a;
    };
    auto x = read(n, m), y = read(n, m), Edge = read(e, n * m + n), Wt = read(e, 1e9);
    vector<int> weight(n * m + n, 1);
    vector<multiset<int>> mx(n), smx(n);
    multiset<int> red;
    for (int i = 0; i < n; i++) {
        red.insert(1);
    }
    for (int i = 0; i < n; i++) {
        if(x[i] == y[i]) {
            for (int j = 0; j < m; j++) {
                mx[i].insert(1);
            }
            continue;
        }
        if(x[i] > y[i]) swap(x[i], y[i]);
        int u = x[i];
        while(u != y[i]) {
            mx[i].insert(1);
            u++;
        }
        while(u != x[i]) {
            smx[i].insert(1);
            u++;
            if(u == m) u = 0;
        }
        red.insert(1);
    }
    int tot = n * m + n;
    int removed = n;
    int ans = 1;
    for (int i = 0; i < e; i++) {
        int edge = Edge[i];
        int wt = Wt[i];
        tot += wt - weight[edge];
        if(edge < n * m) {
            int id = edge / m;
            int pos = edge % m;
            if(x[id] != y[id]) {
                removed -= max(*prev(mx[id].end()), *prev(smx[id].end()));
                red.erase(red.find(min(*prev(mx[id].end()), *prev(smx[id].end()))));
                if(x[id] <= pos && pos < y[id]) {
                    mx[id].erase(mx[id].find(weight[edge]));
                    weight[edge] = wt;
                    mx[id].insert(weight[edge]);
                }
                else {
                    smx[id].erase(smx[id].find(weight[edge]));
                    weight[edge] = wt;
                    smx[id].insert(weight[edge]);
                }
                removed += max(*prev(mx[id].end()), *prev(smx[id].end()));
                red.insert(min(*prev(mx[id].end()), *prev(smx[id].end())));
            }
            else {
                removed -= *prev(mx[id].end());
                mx[id].erase(mx[id].find(weight[edge]));
                weight[edge] = wt;
                mx[id].insert(weight[edge]);
                removed += *prev(mx[id].end());
            }
        }
        else {
            red.erase(red.find(weight[edge]));
            weight[edge] = wt;
            red.insert(weight[edge]);
        }
        ans *= (tot - removed - *prev(red.end())) % mod;
        ans %= mod;
    }
    print(ans);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        cout << "Case #" << tt << ": ";
        solve();
    }
    return 0;
}