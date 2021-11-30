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

void solve() {
    int n;
    scan(n);
    vector<int> a(n), b(n);
    scan(a, b);
    a.insert(a.begin(), 0);
    b.insert(b.begin(), 0);
    vector<int> c(n + 1), d(n + 1);
    b[1] = a[1];
    c[1] = 1, d[1] = 0;
    for (int i = 2; i <= n; i++) {
        c[i] = 0;
        d[i] = b[i] - a[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 2 * i; j <= n; j += i) {
            c[j] -= c[i];
            d[j] -= d[i];
        }
    }
    map<int, array<int, 2>> mp, pref, suff;
    for (int i = 1; i <= n; i++) {
        int x = 0;
        if (c[i] > 0) {
            // c[i] * x + d[i] >= 0
            // x >= ceil(-d[i] / c[i]) (positive)
            x = ceil(-d[i] * 1.0 / c[i]);
            mp[x][0] += c[i];
            mp[x][1] += d[i];
        }
        else if (c[i] < 0) {
            // c[i] * x + d[i] >= 0
            // x <= floor(-d[i] / c[i]) (positive)
            // x >= 1 + floor(-d[i] / c[i]) (negative)
            x = 1 + floor(-d[i] * 1.0 / c[i]);
            c[i] = -c[i];
            d[i] = -d[i];
            mp[x][0] += c[i];
            mp[x][1] += d[i];
        }
        else {
            mp[-inf][1] += abs(d[i]);
        }
    }
    pref = suff = mp;
    array<int, 2> prv;
    prv[0] = prv[1] = 0;
    for (auto &[x, ar] : pref) {
        ar[0] += prv[0];
        ar[1] += prv[1];
        prv = ar;
    }
    prv[0] = prv[1] = 0;
    for (auto it = suff.rbegin(); it != suff.rend(); it++) {
        auto &[x, ar] = *it;
        ar[0] = -ar[0];
        ar[1] = -ar[1];
        ar[0] += prv[0];
        ar[1] += prv[1];
        prv = ar;
    }
    int q;
    scan(q);
    while (q--) {
        int x;
        scan(x);
        x -= a[1];
        auto it = mp.upper_bound(x);
        array<int, 2> ar;
        ar[0] = ar[1] = 0;
        if (it != mp.end()) {
            int key = it->first;
            ar[0] += suff[key][0];
            ar[1] += suff[key][1];
        }
        if (it != mp.begin()) {
            it = prev(it);
            int key = it->first;
            ar[0] += pref[key][0];
            ar[1] += pref[key][1];
        }
        print(ar[0] * x + ar[1]);
    }
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

// 3     7+x
// 3+x   5

//x    -x-2