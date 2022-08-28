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
    string s;
    scan(s);
    int MM = stoi(s.substr(0, 2));
    int SS = stoi(s.substr(3));
    int p;
    scan(p);
    int best = inf;
    int diff = inf;
    string ans;
    int total = MM * 60 + SS;
    int buffer = int(floor(total * p / 100.0));
    for (int tm = total - buffer; tm <= total + buffer; tm++) {
        int mm = tm / 60;
        int ss = tm % 60;
        while (ss < 100 && mm >= 0) {
            string a = to_string(mm), b = to_string(ss);
            if (mm && ss < 10) {
                b = "0" + b;
            }
            string c = b;
            if (mm > 0) {
                c = a + c;
            }
            char pv = c[0];
            int taken = c.size();
            for (auto &ch : c) {
                if (ch != pv) {
                    taken++;
                }
                pv = ch;
            }
            if (taken < best || (taken == best && abs(total - tm) < diff)) {
                ans = c;
                best = taken;
                diff = abs(total - tm);
            }
            mm--;
            ss += 60;
        }
    }
    print(ans);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    scan(t);
    cout << fixed << setprecision(10);
    for (int tt = 1; tt <= t; tt++) {
        cout << "Case #" << tt << ": ";
        solve();
    }
    return 0;
}