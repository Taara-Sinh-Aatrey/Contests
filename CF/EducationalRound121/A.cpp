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

vector<int> p_pow, invp_pow;
// Polynomial Rolling Hash
class Hash {
public:
    const int p = 31;
    const int invp = 838709685;
    const int mod = 1e9 + 9;
    int n;
    string s;
    vector<int> h;

    Hash (string _s) : s(_s) {
        assert(invp * 1LL * p % mod == 1);
        n = s.size();
        if (p_pow.empty()) {
            p_pow.resize(1, 1);
            invp_pow.resize(1, 1);
        }
        while (p_pow.size() < n) {
            p_pow.emplace_back(p_pow.back() * 1LL * p % mod);
            invp_pow.emplace_back(invp_pow.back() * 1LL * invp % mod);
        }
        compute_hash();
    }

    void compute_hash() {
        h.resize(n);
        for (int i = 0; i < n; i++) {
            h[i] = ((i > 0 ? h[i - 1] : 0) + (s[i] - 'a' + 1) * 1LL * p_pow[i]) % mod;
        }
    }

    int get (int i = 0, int j = -1) {
        if (j == -1) 
            j = n - 1;
        return (h[j] - (i > 0 ? h[i - 1] : 0) + mod) * 1LL *  invp_pow[i] % mod;
    }

};

void solve() {
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