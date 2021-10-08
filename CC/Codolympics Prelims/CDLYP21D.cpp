#include "bits/stdc++.h"
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

int coordinate_compress(vector<pair<int, int>>& a) {
    set<int> s;
    for (auto& [l, r] : a) {
        s.insert(l);
        s.insert(r);
    }
    map<int, int> mp;
    int cnt = 0;
    for(auto& x: s) {
        mp[x] = cnt++;
    }
    for(auto& [l, r]: a) {
        l = mp[l];
        r = mp[r];
    }
    return int(s.size());
}

void solve() {
    int n, k;
    scan(n, k);
    vector<pair<int, int>> a(n);
    scan(a);
    int m = coordinate_compress(a);
    vector<int> cnt(m + 1, 0);
    for (auto& [l, r] : a) {
        cnt[l]++;
        cnt[r + 1]--;
    }
    int mx = 0;
    for (int i = 1; i <= m; i++) {
        cnt[i] += cnt[i - 1];
        mx = max(mx, cnt[i]);
    }
    cout << (mx <= k ? "Yes" : "No");
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