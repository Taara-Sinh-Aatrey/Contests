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

string solve(int n, string s) {
    vector<vector<char>> mp = {
        {' ', '0'},
        {',', '@'},
        {'A', 'B', 'C', 'a', 'b', 'c', '2'},
        {'D', 'E', 'F', 'd', 'e', 'f', '3'},
        {'G', 'H', 'I', 'g', 'h', 'i', '4'},
        {'J', 'K', 'L', 'j', 'k', 'l', '5'},
        {'M', 'N', 'O', 'm', 'n', 'o', '6'},
        {'P', 'Q', 'R', 'S', 'p', 'q', 'r', 's', '7'},
        {'T', 'U', 'V', 't', 'u', 'v', '8'},
        {'W', 'X', 'Y', 'Z', 'w', 'x', 'y', 'z', '9'}
    };
    string ans = "";
    n = s.size();
    for (int i = 0, j; i < n; i = j) {
        int d = s[i] - '0';
        j = i;
        while (j < n && s[j] == s[i]) {
            j++;
        }
        int cnt = (j - i - 1) % mp[d].size();
        ans += mp[d][cnt];
        if (j < n && s[j] == '_')
            j++;
    }
    return ans;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    print(solve(1, "222_222"));
    return 0;
}