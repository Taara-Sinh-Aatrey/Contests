#include "bits/stdc++.h"
#include <algorithm>
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

const int inf = 1e9 + 5, mod = 1e9 + 7;

string rollTheString(string s, vector<int> roll) {
    int n = s.size();
    vector<int> cnt(n);
    for (int i = 0; i < roll.size(); i++) {
        int x = roll[i] - 1;
        cnt[x]++;
    }
    for (int i = n - 1; i >= 0; i--) {
        if (i + 1 < n) {
            cnt[i] += cnt[i + 1];
        }
        int val = s[i] - 'a';
        val += cnt[i];
        val %= 26;
        s[i] = char('a' + val);
    }
    return s;
}

int main() {    
    print(rollTheString("abz", {3, 2, 1}));
    return 0;
}