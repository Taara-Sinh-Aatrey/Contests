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

vector<int> hidden;
int n;
vector<vector<int>> a(5);

void solve() {
    // int n;
    scan(n);
    a = vector<vector<int>>(5, vector<int>(n));
    scan(a);
    vector<int> p = {0, 1, 2, 3, 4};
    // auto check = [&] (vector<int> &x, vector<int> &y) {
    //     if (x == y)
    //         return true;
    //     int i = 0, j = 0;
    //     int skip = inf;
    //     bool skipped = false;
    //     while (i < n) {
    //         if (x[i] == y[j]) {
    //             i++, j++;
    //         }
    //         else if (!skipped && skip == inf) {
    //             skipped = true;
    //             skip = x[i];
    //             i++;
    //         }
    //         else if (skipped && skip == y[j]) {
    //             j++;
    //             skip = inf;
    //         }
    //         else {
    //             return false;
    //         }
    //     }
    //     return true;
    // };
    // vector<int> ans = a[0];
    // int best = 0;
    // for (int i = 0; i < 5; i++) {
    //     int score = 0;
    //     for (int j = 0; j < 5; j++) {
    //         if (check(a[i], a[j]) || check(a[j], a[i]))
    //             score++;
    //     }
    //     if (score > best) {
    //         best = score;
    //         ans = a[i];
    //     }
    // }
    // for (auto &x : ans) {
    //     print(x);
    // }
    vector<int> ans;
    vector<int> swp(5);
    for (int i = 0; i < n; i++) {
        map<int, int> mp, mp2;
        for (int x = i; x <= i + 1 && x < n; x++) {
            for (int j = 0; j < 5; j++) {
                if (x == i || swp[j] < 2)
                    mp[a[j][x]]++;
                if (x == i)
                    mp2[a[j][x]]++;
            }
        }
        pair<int, int> p{0, 0};
        for (auto &[x, y] : mp) {
            if (y > p.first || (y == p.first && mp2[x] > mp2[p.second])) {
                p = {y, x};
            }
        }
        int ele;
        if (mp[a[0][i]] == 5) {
            ele = a[0][i];
        }
        else {
            ele = p.second;
        }
        ans.emplace_back(ele);
        for (int j = 0; j < 5; j++) {
            if (a[j][i] != ele) {
                // assert(swp[j] < 2);
                if (i + 1 < n && a[j][i + 1] == ele) {
                    swp[j] = 1;
                    swap(a[j][i], a[j][i + 1]);
                }
                else {
                    swp[j] = 2;
                    int ind = find(a[j].begin(), a[j].end(), ele) - a[j].begin();
                    a[j].erase(a[j].begin() + ind);
                    a[j].insert(a[j].begin() + i, ele);
                }
            }
            else if (swp[j] == 1) {
                swp[j] = 2;
            }
        }
    }
    for (auto &x : ans)
        print(x);
    // if (ans != hidden) {
    //     dbg(ans);
    //     dbg(hidden);
    //     exit(0);
    // }
}

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int rand(int a, int b) { return uniform_int_distribution<int>(a, b)(rng); }

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    for (int tt = 1; tt <= t; tt++) {
        // n = rand(5, 10);
        // hidden = vector<int>(n);
        // iota(hidden.begin(), hidden.end(), 1);
        // shuffle(a.begin(), a.end(), rng);
        // vector<int> perm(n);
        // iota(perm.begin(), perm.end(), 0);
        // for (int j = 0; j < 5; j++) {
        //     if (j >= n) {
        //         a[j] = hidden;
        //         continue;
        //     }
        //     vector<int> b = hidden;
        //     int ind = perm[j];
        //     int ele = b[ind];
        //     b.erase(b.begin() + ind);
        //     b.insert(b.begin() + rand(0, n - 2), ele);
        //     a[j] = b;
        // }
        // dbg(n);
        // dbg(hidden);
        // for (int i = 0; i < 5; i++) {
        //     dbg(a[i]);
        // }
        solve();
    }
    return 0;
}