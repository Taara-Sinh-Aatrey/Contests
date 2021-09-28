#include "bits/stdc++.h"
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
// struct S {
//     int add = inf;
//     int nxt_range = 0;
//     int cur;
//     S (int _add, int _nxt_range, int _cur) : add(_add), nxt_range(_nxt_range), cur(_cur) {}
//     bool operator< (const S &other) const {
//         if (add != other.add) 
//     } 
// };

template <typename T, typename T1, typename... Tail>
T amax(T& a, T1 b, Tail... c) {
    if(b > a) a = b;
    if constexpr (sizeof...(c) != 0) {
        amax(a, c...);
    }
    return a;
}
template <typename T, typename T1, typename... Tail>
T amin(T& a, T1 b, Tail... c) {
    if(b < a) a = b;
    if constexpr (sizeof...(c) != 0) {
        amin(a, c...);
    }
    return a;
}

const int inf = 1e18L + 5, mod = 1e9 + 7, N = 40;

void solve() {
    int n;
    scan(n);
    vector<int> a(n);
    scan(a);
    // dp[j] is max value of next free range for range j
    // vector<int> dpmn(2 * N + 1, -1);
    vector<int> dpmn(2 * N + 1, inf);
    vector<int> dpmx(2 * N + 1, -1);
    dpmn[a[0]] = a[0];
    dpmx[a[0]] = a[0];
    for (int i = 1; i < n; i++) {
        vector<int> ndpmn(2 * N + 1, inf);
        vector<int> ndpmx(2 * N + 1, -1);
        for (int j = 1; j + a[i] <= 2 * N; j++) {
            // print(j);
            if(dpmx[j] < 0 || dpmn[j] >= inf) continue;
            {
                int x = dpmx[j];
                if(a[i] >= x) {
                    // print(j + a[i] - x);
                    amax(ndpmx[j + a[i] - x], j + a[i] - x); 
                    amin(ndpmn[j + a[i] - x], j + a[i] - x); 
                }
                else {
                    // print(j + a[i] - x);
                    amax(ndpmx[j], max(x - a[i], j + a[i] - x)); 
                    amin(ndpmn[j], max(x - a[i], j + a[i] - x)); 
                }
                
            }
            {
                int x = j - dpmx[j];
                if(a[i] >= x) {
                    // print(j + a[i] - x);
                    amax(ndpmx[j + a[i] - x], j + a[i] - x); 
                    amin(ndpmn[j + a[i] - x], j + a[i] - x); 
                }
                else {
                    amax(ndpmx[j], max(x - a[i], j + a[i] - x)); 
                    amin(ndpmn[j], max(x - a[i], j + a[i] - x)); 
                }
            }
            
            
            {
                int x = dpmn[j];
                if(a[i] >= x) {
                    // print(j + a[i] - x);
                    amax(ndpmx[j + a[i] - x], j + a[i] - x); 
                    amin(ndpmn[j + a[i] - x], j + a[i] - x); 
                }
                else {
                    // print(j + a[i] - x);
                    amax(ndpmx[j], max(x - a[i], j + a[i] - x)); 
                    amin(ndpmn[j], max(x - a[i], j + a[i] - x)); 
                }
                
            }
            {
                int x = j - dpmn[j];
                if(a[i] >= x) {
                    // print(j + a[i] - x);
                    amax(ndpmx[j + a[i] - x], j + a[i] - x); 
                    amin(ndpmn[j + a[i] - x], j + a[i] - x); 
                }
                else {
                    amax(ndpmx[j], max(x - a[i], j + a[i] - x)); 
                    amin(ndpmn[j], max(x - a[i], j + a[i] - x)); 
                }
            }
        }
        swap(dpmn, ndpmn);
        swap(dpmx, ndpmx);
        // for (int j = 0; j <= 2 * N; j++) {
        //     if(dpmn[j] > 0) {
        //         print(j, dpmn[j]);
        //     }
        // }
        // print();
    }
    int ans = inf;
    for (int i = 1; i <= 2 * N; i++) {
        if (dpmn[i] <= 0) continue;
        print(i);
        return;
    }
    // assert(false);
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