#include "bits/stdc++.h"
#include <cfenv>
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

class fenwick {
public:
    int n;
    vector<int> tree;
    // original array should follow 0 based indexing
    fenwick() {

    }

    fenwick(int _n) {
        n = _n;
        tree.resize(n + 1, 0);
    }

    fenwick(vector<int>& arr) {
        n = arr.size();
        tree.resize(n + 1, 0);
        for(int i = 0; i < n; i++) {
            modify(i, arr[i]);
        }
    }

    void modify(int idx, int val) {
        idx += 1;
        while(idx <= n) {
            tree[idx] += val;
            idx += idx & (-idx);
        }
    } 

    int get(int idx) {
        idx += 1;
        int ret = 0;
        while(idx > 0) {
            ret += tree[idx];
            idx -= idx & (-idx);
        }
        return ret;
    }
};

int coordinate_compress(vector<int>& a) {
    set<int> s(a.begin(), a.end());
    map<int, int> mp;
    int cnt = 0;
    for(auto& x: s) {
        mp[x] = cnt++;
    }
    for(int& x: a) {
        x = mp[x];
    }
    return int(s.size());
}

void solve() {
    int n, m;
    scan(n, m);
    int tot = n * m;
    vector<int> a(tot);
    scan(a);
    int sz = coordinate_compress(a);
    vector<int> order(tot);
    // order[i] -> person at ith seat
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](const int& i, const int& j) {
        if(a[i] == a[j]) {
            return i > j;
        }
        return a[i] < a[j];
    });
    // seats[r] -> {{r1, c1}, {r2, c2}}
    // seats with rating r
    vector<vector<pair<int, int>>> seats(sz);
    for(int seat = 0; seat < tot; seat++) {
        seats[a[order[seat]]].emplace_back(-(seat / m), seat % m);
    }
    for(auto& vec : seats) {
        sort(vec.begin(), vec.end());
    }
    fenwick f(tot);
    int ans = 0;
    for(int i = 0; i < tot; i++) {
        auto [row, col] = seats[a[i]].back();
        seats[a[i]].pop_back();
        row = -row;
        int start = row * m;
        int seat = start + col;
        ans += f.get(seat) - (start == 0 ? 0 : f.get(start - 1));
        f.modify(seat, 1);
    }  
    print(ans);
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