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

const int inf = 1e9 + 5, mod = 1e9 + 7, N = 2e5 + 5;

int getPalindromesCount(string s) {
#define int int64_t
    map<string, int> dp;
    dp[""] = 1;
    auto add = [&] (int &x, int y) {
        x += y;
        if (x >= mod) {
            x -= mod;
        }    
    };
    int ans = 0;
    for (auto &ch : s) {
        auto ndp = dp;
        for (auto &[str, cnt] : dp) {
            auto nstr = str + ch;
            if (nstr.size() == 5) {
                bool ok = true;
                for (int i = 0; i < 2; i++) {
                    if (nstr[i] != nstr[4 - i]) {
                        ok = false;
                    }
                }
                if (ok) {
                    add(ans, cnt);
                }
            }
            else {
                add(ndp[nstr], cnt);
            }
        }
        swap(dp, ndp);
    }
    return ans;
#undef int
}

int main() {
    print(getPalindromesCount("010110"));
    print(getPalindromesCount("01111"));
    return 0;
}