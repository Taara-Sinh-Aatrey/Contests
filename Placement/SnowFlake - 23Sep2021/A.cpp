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

vector<string> closestStraightCity(vector<string> c, vector<int> x, vector<int> y, vector<string> q) {
    map<int, vector<pair<int, string>>> X, Y;
    map<string, pair<int, int>> coord;
    int n = c.size();
    for(int i = 0; i < n; i++) {
        coord[c[i]] = {x[i], y[i]};
        X[x[i]].emplace_back(y[i], c[i]);
        Y[y[i]].emplace_back(x[i], c[i]);
    }
    for(auto& [xx, vec] : X) {
        sort(vec.begin(), vec.end());
    }
    for(auto& [yy, vec] : Y) {
        sort(vec.begin(), vec.end());
    }
    const int inf = INT_MAX;
    vector<string> ret;
    for(auto& city : q) {
        auto& [xx, yy] = coord[city];
        pair<int, string> ans = {inf, "NONE"};
        {
            auto& vec = X[xx];
            pair<int, string> to_search = {yy, city};
            auto it = lower_bound(vec.begin(), vec.end(), to_search);
            if(it != vec.end() && next(it) != vec.end()) {
                it = next(it);
                ans = min(ans, pair<int, string>(it->first - yy, it->second));
                it = prev(it);
            }
            if(it != vec.begin()) {
                it = prev(it);
                ans = min(ans, pair<int, string>(yy - it->first, it->second));
            }
        }
        {
            auto& vec = Y[yy];
            pair<int, string> to_search = {xx, city};
            auto it = lower_bound(vec.begin(), vec.end(), to_search);
            if(it != vec.end() && next(it) != vec.end()) {
                it = next(it);
                ans = min(ans, pair<int, string>(it->first - xx, it->second));
                it = prev(it);
            }
            if(it != vec.begin()) {
                it = prev(it);
                ans = min(ans, pair<int, string>(xx - it->first, it->second));
            }
        }
        ret.emplace_back(ans.second);    }
    return ret;
}

signed main() {
    print(closestStraightCity({"fastcity", "bigbanana", "xyz"}, {23, 23, 23}, {1, 10, 20}, {"fastcity", "bigbanana", "xyz"}));
    print(closestStraightCity({"london", "warsaw", "hackerland"}, {1, 10, 20}, {1, 10, 10}, {"london", "warsaw", "hackerland"}));
    return 0;
}