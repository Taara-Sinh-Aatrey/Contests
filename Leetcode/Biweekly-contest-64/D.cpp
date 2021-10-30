#include "bits/stdc++.h"
#include <functional>
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

int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {0, -1, 1, -1, 1, -1, 0, 1};
map<string, vector<int>> mp;

class Solution {
public:
    int countCombinations(vector<string>& pieces, vector<vector<int>>& positions) {
        mp["queen"] = {0, 1, 2, 3, 4, 5, 6, 7};
        mp["rook"] = {0, 3, 4, 6};
        mp["bishop"] = {1, 2, 5, 7};
        int ans = 0;
        int n = pieces.size();
        auto check = [&] (vector<pair<int, int>> a) {
            auto p = positions;
            int steps = 0;
            bool ok = true;
            while (ok) {
                ok = false;
                steps++;
                for (int i = 0; i < n; i++) {
                    if (steps <= a[i].second) {
                        p[i][0] += dx[a[i].first];
                        p[i][1] += dy[a[i].first];
                    }
                    if (steps < a[i].second) {
                        ok = true;
                    }
                }
                for (int i = 0; i < n; i++) {
                    for (int j = i + 1; j < n; j++) {
                        if (p[i] == p[j]) return 0;
                    }
                }
            }
            return 1;
        };
        vector<pair<int, int>> vec;
        function<void(int)> rec = [&] (int i) {
            if (i >= n) {
                ans += check(vec);
                return;
            }
            int w = 0;
            for (auto &dir : mp[pieces[i]]) {
                for (int x = 0; x <= 7; x++) {
                    if (x == 0 && w != 0) continue;
                    int nx = positions[i][0] + dx[dir] * x;
                    int ny = positions[i][1] + dy[dir] * x;
                    if (nx > 8 || nx < 1 || ny > 8 || ny < 0) {
                        continue;
                    } 
                    w = 1;
                    vec.emplace_back(dir, x);
                    rec(i + 1);
                    vec.pop_back();
                }
            }
        };
        rec(0);
        return ans;
    }
};