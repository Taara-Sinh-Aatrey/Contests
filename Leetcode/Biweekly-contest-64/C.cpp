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

#define ll long long
const ll inf = 1e18L + 5, mod = 1e9 + 7, N = 2e5 + 5;

class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& q) {
        vector<int> ans;
        vector<int> p;
        vector<int> pref(s.size());
        for (int i = 0; i < s.size(); i++) {
            if (i > 0) pref[i] = pref[i - 1];
            if (s[i] == '|') {
                p.emplace_back(i);
            }
            else {
                pref[i]++;
            }
        }
        for (auto &v : q) {
            int l = v[0], r = v[1];
            auto it = lower_bound(p.begin(), p.end(), l);
            if (it == p.end()) {
                ans.emplace_back(0);
                continue;
            }
            l = *it;
            r = *prev(upper_bound(p.begin(), p.end(), r));
            if (l > r) {
                ans.emplace_back(0);
                continue;
            }
            ans.emplace_back(pref[r] - (l > 0 ? pref[l - 1] : 0));
        }
        return ans;
    }
};