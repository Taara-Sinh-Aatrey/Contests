#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <sys/resource.h>
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

int distinctMoves(string s, int n, int x, int y) {
    const int N = 3e3 + 5;
    const int mod = 1e9 + 7;
    auto add = [&] (int& x, int y) {
        x += y;
        if (x >= mod) x -= mod;
    };
    vector<int> both(N), R(N), L(N), ans(N, 0);
    both[x] = 1;
    for (auto &ch : s) {
        vector<int> nboth(N);
        if (ch == 'l') {
            for (int i = 1; i < N; i++) {
                add(nboth[i - 1], both[i]);
                add(ans[i - 1], both[i]);
                add(nboth[i - 1], L[i]);
                add(ans[i - 1], L[i]);
                L[i] = 0;
            }
            for (int i = 0; i < N; i++) {
                add(R[i], both[i]);
                both[i] = 0;
            }
        }
        else {
            for (int i = N - 2; i >= 0; i--) {
                add(nboth[i + 1], both[i]);
                add(ans[i + 1], both[i]);
                add(nboth[i + 1], R[i]);
                add(ans[i + 1], R[i]);
                R[i] = 0;
            }
            for (int i = 0; i < N; i++) {
                add(L[i], both[i]);
                both[i] = 0;
            }
        }
        swap(nboth, both);
    }
    return ans[y];
}

signed main() {
    cout << distinctMoves("rrlrlr", 6, 1, 2) << '\n';
    return 0;
}