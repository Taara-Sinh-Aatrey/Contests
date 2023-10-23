/**
 *    author:  Taara Sinh Aatrey
 *    created: 31.12.2022 11:18:31
**/

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

#ifdef AATREY_DEBUG
#include "debug.hpp"
#else
#define dbg(...)
#endif

#define int int64_t

vector<string> solve(vector<string> a) {
    vector<string> ans;
    for (auto &s : a) {
        int n = s.size();
        if (n == 1) {
            ans.push_back(stoll(s) % 8 == 0 ? "YES" : "NO");
        }
        else if (n == 2) {
            string t = s;
            reverse(t.begin(), t.end());
            ans.push_back(stoll(s) % 8 == 0 || stoll(t) % 8 == 0 ? "YES" : "NO");
        }
        else {
            int num1 = 0;
            bool found = false;
            for (int i = 0; i < n && !found; i++) {
                for (int j = 0; j < n && !found; j++) {
                    if (j == i) continue;
                    for (int k = 0; k < n && !found; k++) {
                        if (k == i || k == j) {
                            continue;
                        }
                        int num = (s[k] - '0') * 100 + (s[j] - '0') * 10 + (s[i] - '0');
                        if (num % 8 == 0) {
                            found = true;
                        }
                    }
                }
            }
            ans.push_back(found ? "YES" : "NO");
        }
    }
    return ans;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << solve({"65", "71", "2700", "1360", "38510"}) << endl;
    return 0;
}