#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <ios>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
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
    auto check = [&] (vector<double> &a) {
        vector<double> f = {0, a[0]};    
        for (int i = 1; i < a.size(); i++)
            f = {f[1], max(f[0], f[1]) + a[i]};
        return max(f[0], f[1]);
    };
    int n;
    scan(n);
    vector<int> a(n);
    scan(a);
    {
        double low = 0, high = 1e9;
        for (int it = 0; it < 100; it++) {
            double mid = (low + high) / 2;
            vector<double> b(n);
            for (int i = 0; i < n; i++)
                b[i] = a[i] - mid;
            if (check(b) >= 0)
                low = mid;
            else
                high = mid;
        }
        cout << fixed << setprecision(20) << (low + high) * 0.5 << '\n';
    }
    {
        int low = 0, high = 1e9;
        while (low <= high) {
            int mid = (low + high) / 2;
            vector<double> b(n);
            for (int i = 0; i < n; i++)
                b[i] = a[i] >= mid ? 1 : -1;
            if (check(b) > 0.5)
                low = mid + 1;
            else
                high = mid - 1;
        }
        print(high);
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