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

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int rand(int a, int b) { return uniform_int_distribution<int>(a, b)(rng); }

map<int, long double> mp;

void solve() {
    int n, k;
    scan(n, k);
    int u, e;
    scan(u, e);
    set<pair<int, int>> st;
    set<int> rem;
    for (int i = 1; i <= n; i++) {
        rem.emplace(i);
    }
    auto Erase = [&] (int node) {
        if (rem.count(node)) {
            rem.erase(node);
        }    
    };
    auto Insert = [&] (int u, int e) {
        st.emplace(u, e);
        Erase(u);    
    };
    Insert(u, e);
    for (int i = 1; i <= k; i++) {
        if (rand(0, 1) <= 1 || rem.empty()) {
            cout << 'W' << endl;
        }
        else {
            cout << "T " << *rem.begin() << endl;
        }
        scan(u, e);
        Insert(u, e);
    }
    int sum = 0, cnt = 0;
    for (auto &[x, y] : st) {
        sum += y;
        cnt += 1;
    }
      
    auto ratio = [&] () {
        return 1;
        // return mp.lower_bound(n)->second;
    };
    int estimate = sum * 0.5 * ratio() / cnt * n;
    cout << "E " << estimate << endl;
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