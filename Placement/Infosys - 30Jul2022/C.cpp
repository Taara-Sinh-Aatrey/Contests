#include "bits/stdc++.h"
using namespace std;

// template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream &operator<<(ostream &os, const T_container &v) { bool f = false; for (const T &x : v) { if (f) os << " "; os << x; f = true; } return os; }

const int mod = 1e9 + 7;

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

int solve(int n, int m, int k, vector<int> a) {
#define int int64_t
    int lo = 0, hi = 2e9;
    int ans = 0;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        vector<int> delta(n + 1);
        int ops = 0;
        for (int i = 0; i < n; i++) {
            int req = max<int>(0, mid - a[i] - delta[i]);
            ops += req;
            delta[i] += req;
            delta[min<int>(i + k, n)] -= req;
            delta[i + 1] += delta[i];
        }
        if (ops <= m) {
            ans = mid;
            lo = mid + 1;
        }
        else {
            hi = mid - 1;
        }
    }
    return ans;
#undef int
}

int main() {
    cout << solve(2, 5, 1, {8, 11}) << endl;
    cout << solve(6, 2, 3, {4, 4, 4, 4, 3, 3}) << endl;
    cout << solve(3, 3, 2, {1, 7, 2}) << endl;
    return 0;
}