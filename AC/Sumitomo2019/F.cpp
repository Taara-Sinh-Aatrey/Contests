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
// A1 != B1 && A2 != B2

// A1 > B1 == A2 > B2 => never meet

// Meeting never possible before T1

// If they never meet before T1+T2 time, they will never meet
    vector<int> t(2), a(2), b(2);
    scan(t, a, b);
    if (a[0] < b[0]) {
        swap(a, b);
    }
    if (a[0] * t[0] + a[1] * t[1] > b[0] * t[0] + b[1] * t[1]) {
        // if ((a[0] > b[0]) == (a[1] > b[1])) // this is a subset of the above condition
        print(0);
        return;
    }
    else if (a[0] * t[0] + a[1] * t[1] == b[0] * t[0] + b[1] * t[1]) {
        print("infinity");
        return;
    }
    else {
        int ans = 0;
        // faster in the first half is ultimately before than slower in the first half
        // so they must have intersected exactly once
        int loss = b[0] * t[0] + b[1] * t[1] - a[0] * t[0] + a[1] * t[1];
        int start1 = 0, start2 = 0;
        int state = 0;
        int iter = 0;
        int last_useful_iter = -1;
        while (iter - last_useful_iter <= 100) {
            dbg(start1, start2);  
            int end1 = start1 + a[state] * t[state];
            int end2 = start2 + b[state] * t[state];
            if (start1 != start2 && (start1 > start2) != (end1 > end2)) {
                ans++;
                last_useful_iter = iter;
            }
            iter++;
            start1 = end1;
            start2 = end2;
            state ^= 1;
        }
        print(ans);
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