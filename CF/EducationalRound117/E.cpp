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

#define int int64_t
const int inf = 1e18L + 5, mod = 1e9 + 7, N = 2e5 + 5;

struct fraction {
    int num, den;
    
    fraction () : num(0), den(1) {}
     
    fraction (int _num, int _den) : num(_num), den(_den) {}
    
    bool operator< (const fraction &other) const {
        return num * other.den < other.num * den;
    }
    
    bool operator<= (const fraction &other) const {
        return num * other.den <= other.num * den;
    }
    
    bool operator> (const fraction &other) const {
        return num * other.den > other.num * den;
    }
    
    bool operator>= (const fraction &other) const {
        return num * other.den >= other.num * den;
    }
    
    friend ostream& operator<< (ostream &os, const fraction &f) {
        // return os << f.num << "/" << f.den << "=" << (long double) f.num / f.den;
        return os << (long double) f.num / f.den;
    }
};

void solve() {
    int n;
    scan(n);
    vector<pair<int, int>> a(n);
    for (auto &[x, y] : a) {
        scan(x, y);
        --x;
    }
    fraction ans(0, 1);
    vector<int> vec;
    for (int i = 1; i <= 20; i++) {
        vector<int> msg(N);
        for (auto &[x, y] : a) {
            msg[x] += min(y, i);
        }
        vector<int> ord(N);
        iota(ord.begin(), ord.end(), 0);
        sort(ord.begin(), ord.end(), [&] (auto &i, auto &j) { return msg[i] > msg[j]; });
        int sum = 0;
        vector<int> v;
        for (int it = 0; it < i; it++) {
            int j = ord[it];
            sum += msg[j];
            v.emplace_back(j + 1);
        }
        fraction cur(sum, i);
        if (cur > ans) {
            ans = cur;
            swap(vec, v);
        }
    }
    sort(vec.begin(), vec.end());
    print(vec.size());
    print(vec);
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