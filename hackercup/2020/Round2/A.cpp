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
const int inf = 1e18L + 5, mod = 1e9 + 7, N = 2e5 + 5;

void solve() {
    int n, k;
    scan(n, k);
    auto read = [&]() {
        vector<int> vec(k);
        scan(vec);
        int w, x, y, z;
        scan(w, x, y, z);
        for(int i = k; i < n; i++) {
            vec.emplace_back((vec[i - 2] * w + vec[i - 1] * x + y) % z);
        }
        return vec;
    };
    auto s = read(), x = read(), y = read();
    for (int i = 0; i < n; i++) {
        y[i] += x[i];
    }
    pair<int, int> take{0, 0}, give{0, 0};
    pair<int, int> extra{0, 0};
    for(int i = 0; i < n; i++) {
        x[i] -= s[i];
        y[i] -= s[i];
        if(x[i] <= 0 && y[i] >= 0) {
            extra.first -= min<int>(x[i], 0);
            extra.second += max<int>(y[i], 0);
        }
        else {
            if(y[i] < 0) {
                give.first -= y[i];
                give.second -= x[i];
            }
            else {
                take.first += x[i];
                take.second += y[i];
            }
        }
    }
    if(take.first > give.second) {
        give.second += extra.first;
    }
    else if(take.second < give.first) {
        take.second += extra.second;
    }
    
    if(take.first > give.second || take.second < give.first) {
        print(-1);
    }
    else {
        print(max(take.first, give.first));
    }
}

signed main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        cout << "Case #" << tt << ": ";
        solve();
    }

    return 0;
}