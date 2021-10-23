#include "bits/stdc++.h"
using namespace std;

bool debug;
template <typename T, typename U> istream& operator>>(istream &is, pair<T, U> &p) { return is >> p.first >> p.second;}
template <typename T, typename U> ostream& operator<<(ostream &os, const pair<T, U> &p) { return debug ? os << "(" << p.first << ", " << p.second << ")" : os << p.first << " " << p.second; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> istream &operator>>(istream &is, T_container &v) { for (T &x : v) is >> x; return is; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream &operator<<(ostream &os, const T_container &v) { bool f = false; if(debug) { os << "{"; for (const T &x : v) { if (f) os << ", "; os << x; f = true; } os << "}"; } else { for (const T &x : v) { if (f) os << " "; os << x; f = true; } } return os; }
void scan() {} template <typename Head, typename ...Tail> void scan(Head &H, Tail &...T) { cin >> H; scan(T...); }
void print() { cout << "\n"; } template <typename Head> void print(const Head &H) { cout << H << "\n"; } template <typename Head, typename ...Tail> void print(const Head &H, const Tail &...T) { cout << H << " "; print(T...); }
template <typename T, typename T1, typename... Tail> T amin(T& a, T1 b, Tail... c) { if(b < a) a = b; if constexpr (sizeof...(c) != 0) { amin(a, c...); } return a; } template <typename T, typename T1, typename... Tail> T amax(T& a, T1 b, Tail... c) { if(b > a) a = b; if constexpr (sizeof...(c) != 0) { amax(a, c...); } return a; }
void dbg_out() { cerr << "\n"; } template <typename Head, typename ...Tail> void dbg_out(const Head &H, const Tail &...T) { cerr << " " << H; dbg_out(T...); }
#ifndef ONLINE_JUDGE
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]:", debug = true, dbg_out(__VA_ARGS__), debug = false
#else
#define dbg(...)
#endif

#define int int64_t
const int inf = 1e18L + 5, mod = 1e9 + 7, N = 2e5 + 5;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int rand(int a, int b) { return uniform_int_distribution<int>(a, b)(rng); }

void solve() {
    int n, k;
    scan(n, k);
    // trivial case
    if (k == 0) {
        print("YES");
        print(0);
        return;
    }
    int msb = 31 - __builtin_clz(k);
    // even? sorry
    if (k & 1 ^ 1) {
        print("NO");
        return;
    }
    print("YES");
    function<bool(int, int, int, int, vector<int>&)> rec = [&] (int b, int k, int start, int sign, vector<int>& starting_points) {
        // the actual starting point of current range is `start + 1`
        if (b == -1) {
            return k == 0;
        }
        int cur_len = 1 << b;
        
        // check for out of range 
        if (sign == 1) {
            if (start + 1 <= 0 || start + cur_len > n)
                return false;
        }
        else {
            if (start - cur_len + 1 <= 0 || start > n)
                return false;
        }
        
        int nstart = start + sign * cur_len; // start point of the next range
        int nsign = k > cur_len ? sign : -sign; // direction of the next range
        int nk = abs(k - cur_len); // k for the next range
        
        // go towards nsign direction
        if(!rec(b - 1, nk, nstart, nsign, starting_points)) {
            // clear the constructed answer
            starting_points.clear();
            
            // nsign goes out of range, try opposite direction which essentially means instead of traversing a->b, traverse b->a and this must work (since k isn't big enough), hence the assert
            assert(rec(b - 1, nk, nstart + nsign * nk, -nsign, starting_points));
        }
        
        starting_points.emplace_back(sign == 1 ? start + 1 : start - cur_len + 1);
        return true;
    };
    vector<int> starting_points;
    assert(rec(msb, k, 0, 1, starting_points));
    print(msb + 1);
    for (auto x : starting_points) {
        print(x);
    }
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

/*
1
1 3
1 3 5 7
1 3 5 7 9 11 13 15

11 3 1 1
13 5 1 1
17 1 7 3 1
------------------------------------------------------------------
Input: 32 17
Simulation:

                                          18
                                             19 20
                                                   21 22 23 24
                                       17 18 19 20 21 22 23 24
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 
----------------------------------------------------------------
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17
*/