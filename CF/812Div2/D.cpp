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

void solve() {
    auto ask = [&] (int a, int b) {
        cout << "? " << a << " " << b << endl;
        int cmp;
        cin >> cmp;
        assert(~cmp);
        return cmp;    
    };
    int n;
    cin >> n;
    n = 1 << n;
    vector<int> a(n);
    iota(a.begin(), a.end(), 1);
    auto decide = [&] (int x, int y) {
        int res = ask(a[x], a[y]);
        assert(res > 0);
        return res == 1 ? a[x] : a[y];
    };
    while (a.size() >= 4) {
        int sz = a.size();
        vector<int> winners;
        for (int i = 0; i < sz; i += 4) {
            int cmp = ask(a[i], a[i + 2]);
            if (cmp == 0) {
                winners.emplace_back(decide(i + 1, i + 3));
            }
            else if (cmp == 1) {
                winners.emplace_back(decide(i, i + 3));
            }
            else {
                winners.emplace_back(decide(i + 1, i + 2));
            }
        }
        swap(a, winners);
    }
    int winner = a.size() == 1 ? a[0] : decide(0, 1);
    cout << "! " << winner << endl;
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