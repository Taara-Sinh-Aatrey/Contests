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

const int inf = 1e9 + 5, mod = 1e9 + 7, N = 2e5 + 5;


void solve() {
    int n, m;
    scan(n, m);
    vector<pair<int, int>> a(n);
    scan(a);
    map<int, int> lcnt, rcnt;
    map<int, int64_t> left, right;
    map<int, int64_t> arr;
    for (auto &[idx, p] : a) {
        int l = idx - p;
        int r = idx + p;
        arr[idx] -= p;
        left[idx] += p;
        right[idx] += p;
        lcnt[idx]++;
        rcnt[idx]++;
        lcnt[l]--;
        rcnt[l] += 0;
        rcnt[r]--;
        lcnt[r] += 0;
    }
    for (auto it = lcnt.rbegin(); it != lcnt.rend(); it++) {
        int i = it->first;
        arr[i] += left[i];
        if (next(it) != lcnt.rend()) {
            int j = next(it)->first;
            lcnt[j] += lcnt[i];
            left[j] += left[i] - (i - j) * lcnt[i];
        }
    }
    left = map<int, int64_t>();
    lcnt = map<int, int>();
    for (auto it = rcnt.begin(); it != rcnt.end(); it++) {
        int i = it->first;
        arr[i] += right[i];
        if (next(it) != rcnt.end()) {
            int j = next(it)->first;
            rcnt[j] += rcnt[i];
            right[j] += right[i] - (j - i) * rcnt[i];
        }
    }
    right = map<int, int64_t>();
    rcnt = map<int, int>();
    for (auto &[x, y] : arr) {
        y -= min<int64_t>(y, m);
    }
    map<int, int64_t> pref;
    for (auto it = arr.begin(); it != arr.end(); it++) {
        int i = it->first;
        amax(pref[i], arr[i]);
        if (next(it) != arr.end()) {
            int j = next(it)->first;
            if (pref[i] > 0)
                amax(pref[j], pref[i] + j - i);
        }
    }
    map<int, int64_t> suff;
    for (auto it = arr.rbegin(); it != arr.rend(); it++) {
        int i = it->first;
        amax(suff[i], arr[i]);
        if (next(it) != arr.rend()) {
            int j = next(it)->first;
            if (suff[i] > 0)
                amax(suff[j], suff[i] + i - j);
        }
    }
    string s;
    for (auto &[x, y] : a) {
        s += y >= max(pref[x], suff[x]) ? '1' : '0';
    }
    print(s);
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