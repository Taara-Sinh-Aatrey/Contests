// #include "bits/stdc++.h"
// using namespace std;

// template <typename T, typename U> istream& operator>>(istream &is, pair<T, U> &p) { return is >> p.first >> p.second; }
// template <typename T, typename U> ostream& operator<<(ostream &os, const pair<T, U> &p) { return os << p.first << " " << p.second; }
// template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> istream &operator>>(istream &is, T_container &v) { for (T &x : v) is >> x; return is; }
// template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream &operator<<(ostream &os, const T_container &v) { bool f = false; for (const T &x : v) { if (f) os << " "; os << x; f = true; } return os; }
// void scan() {} template <typename Head, typename ...Tail> void scan(Head &H, Tail &...T) { cin >> H; scan(T...); }
// void print() { cout << "\n"; } template <typename Head> void print(const Head &H) { cout << H << "\n"; } template <typename Head, typename ...Tail> void print(const Head &H, const Tail &...T) { cout << H << " "; print(T...); }
// template <typename T, typename T1, typename... Tail> T amin(T& a, T1 b, Tail... c) { if(b < a) a = b; if constexpr (sizeof...(c) != 0) { amin(a, c...); } return a; } template <typename T, typename T1, typename... Tail> T amax(T& a, T1 b, Tail... c) { if(b > a) a = b; if constexpr (sizeof...(c) != 0) { amax(a, c...); } return a; }

// #ifdef LOCAL
// #include "debug.hpp"
// #else
// #define dbg(...)
// #endif

// #define int int64_t
// const int inf = 1e18L + 5, N = 2e5 + 5;

// map<pair<int, int>, int> mp;
// map<pair<int, int>, int> Ans;

// void solve() {
//     auto check = [&] (int num) {
//         int sum = 0;
//         int prod = 1;
//         while (num > 0) {
//             int d = num % 10;
//             sum += d;
//             prod *= d;
//             num /= 10;
//         }
//         return prod % sum == 0;
//     };
//     auto check2 = [&] (int num) {
//         int sum = 0;
//         int prod = 1;
//         while (num > 0) {
//             int d = num % 10;
//             if (d == 0) {
//                 return true;
//             }
//             sum += d;
//             prod *= d;
//             num /= 10;
//         }
//         return false;
//     };
//     int l, r;
//     scan(l, r);
//     if (Ans.count({l, r})) {
//         print(Ans.count({l, r}));
//         return;
//     }
//     int answer = 0, z = 0;
//     // for (int num = l; num <= r; num++) {
//     //     answer += check(num);
//     //     z += check2(num);
//     //     // if (check2(num)) {
//     //     //     dbg(num);
//     //     // }
//     // }
//     const int MAX = to_string(r).size() * 9;
//     vector<int> nums(MAX + 1), nums2(MAX + 1);
//     int xx = 0;
//     for (int mod = 1; mod <= MAX; mod++) {
//         vector<int> v{1};
//         int x = mod;
//         for (int p = 2; p <= 9; p++) {
//             if (mod % p == 0)
//                 v.emplace_back(p);
//             while (x % p == 0)
//                 x /= p;
//         }
//         if (x != 1)
//             continue;
//         xx++;
//         // dbg(mod);
//         auto fun = [&] (int _x) {
//             if (_x == 0)
//                 return int(0);
//             vector<vector<int>> dp(mod + 1, vector<int>(mod, 0));
//             int eq = 1;
//             int sum = 0;
//             int prod = 1;
//             string _s = to_string(_x);
//             int n = _s.size();
//             for (int i = 0; i < n; i++) {
//                 int d = _s[i] - '0';
//                 vector<vector<int>> ndp(mod + 1, vector<int>(mod));
//                 for (int s = 0; s <= mod; s++) {
//                     for (int p = 0; p < mod; p++) {
//                         for (int x = 1; x <= 9 && s + x <= mod; x++) {
//                         // for (auto &x : v) {
//                             if (s + x > mod)
//                                 continue;
//                             ndp[s + x][(p * x) % mod] += dp[s][p];
//                         }
//                     }
//                 }
//                 for (int x = 1; x < d && sum + x <= mod; x++) {
//                     ndp[sum + x][(prod * x) % mod] += eq;
//                 }
//                 if (i != 0) {
//                     for (int x = 1; x <= 9 && x <= mod; x++) {
//                         ndp[x][x % mod]++;
//                     }
//                 }
//                 sum += d;
//                 prod = (prod * d) % mod;
//                 if (d == 0)
//                     eq = 0;
//                 swap(dp, ndp);
//             }
//             return dp[mod][0] + (sum == mod && prod == 0 && eq ? 1 : 0);        
//         };
//         if (!mp.count({r, mod}))
//             mp[{r, mod}] = nums[mod] = fun(r);
//         if (!mp.count({l, mod}))
//             mp[{l, mod}] = nums2[mod] = fun(l - 1);
//     }
//     int ans = 0;
//     for (int sum = 1; sum <= MAX; sum++) {
//         ans += nums[sum] - nums2[sum];
//     }
//     // dbg(nums);
//     // dbg(answer, z);
//     // print(ans);
//     auto fun = [&] (int _x) {
//         if (_x == 0)
//             return int(0);
//         int ret = 0;
//         int cnt = 0;
//         string _s = to_string(_x);
//         int n = _s.size();
//         int eq = 1;
//         bool ok = false;
//         for (int i = 0; i < n; i++) {
//             int d = _s[i] - '0';
//             ret = ret * 10 + cnt + (!ok && i != 0 && d > 0) + (ok * d);
//             cnt *= 9;
//             if (i != 0) {
//                 cnt += 9 + (!ok * max<int>(0, d - 1));
//             }
//             else {
//                 cnt += (!ok * max<int>(0, d - 1));
//             }
//             if (d == 0)
//                 ok = true;
//             // dbg(ret, cnt);
//         }
//         return ret + ok;        
//     };
//     // dbg(fun(r) - fun(l - 1));
//     ans += fun(r) - fun(l - 1);
//     // dbg(xx);
//     print(ans);
//     Ans[{l, r}] = ans;
// }

// signed main() {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     int t = 1;
//     scan(t);
//     for (int tt = 1; tt <= t; tt++) {
//         cout << "Case #" << tt << ": ";
//         solve();
//     }
//     // for (int )
//     return 0;
// }

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
const int inf = 1e18L + 5, N = 2e5 + 5;

map<pair<int, int>, int> mp;
map<pair<int, int>, int> Ans;

void solve() {
    auto check = [&] (int num) {
        int sum = 0;
        int prod = 1;
        while (num > 0) {
            int d = num % 10;
            sum += d;
            prod *= d;
            num /= 10;
        }
        return prod % sum == 0;
    };
    auto check2 = [&] (int num) {
        int sum = 0;
        int prod = 1;
        while (num > 0) {
            int d = num % 10;
            if (d == 0) {
                return true;
            }
            sum += d;
            prod *= d;
            num /= 10;
        }
        return false;
    };
    int l, r;
    scan(l, r);
    if (Ans.count({l, r})) {
        print(Ans.count({l, r}));
        return;
    }
    int answer = 0, z = 0;
    // for (int num = l; num <= r; num++) {
    //     answer += check(num);
    //     z += check2(num);
    //     // if (check2(num)) {
    //     //     dbg(num);
    //     // }
    // }
    const int MAX = to_string(r).size() * 9;
    vector<int> nums(MAX + 1), nums2(MAX + 1);
    for (int mod = 1; mod <= MAX; mod++) {
        auto fun = [&] (int _x) {
            if (_x == 0)
                return int(0);
            vector<vector<int>> dp(mod + 1, vector<int>(mod, 0));
            int eq = 1;
            int sum = 0;
            int prod = 1;
            string _s = to_string(_x);
            int n = _s.size();
            for (int i = 0; i < n; i++) {
                int d = _s[i] - '0';
                vector<vector<int>> ndp(mod + 1, vector<int>(mod));
                for (int s = 0; s <= mod; s++) {
                    for (int p = 0; p < mod; p++) {
                        for (int x = 1; x <= 9 && s + x <= mod; x++) {
                            ndp[s + x][(p * x) % mod] += dp[s][p];
                        }
                    }
                }
                for (int x = 1; x < d && sum + x <= mod; x++) {
                    ndp[sum + x][(prod * x) % mod] += eq;
                }
                if (i != 0) {
                    for (int x = 1; x <= 9 && x <= mod; x++) {
                        ndp[x][x % mod]++;
                    }
                }
                sum += d;
                prod = (prod * d) % mod;
                if (d == 0)
                    eq = 0;
                swap(dp, ndp);
            }
            return dp[mod][0] + (sum == mod && prod == 0 && eq ? 1 : 0);        
        };
        if (!mp.count({r, mod}))
            mp[{r, mod}] = fun(r);
        if (!mp.count({l - 1, mod}))
            mp[{l - 1, mod}] = fun(l - 1);
    }
    int ans = 0;
    for (int sum = 1; sum <= MAX; sum++) {
        ans += mp[{r, sum}] - mp[{l - 1, sum}];
    }
    // dbg(nums);
    // dbg(answer, z);
    // print(ans);
    auto fun = [&] (int _x) {
        if (_x == 0)
            return int(0);
        int ret = 0;
        int cnt = 0;
        string _s = to_string(_x);
        int n = _s.size();
        int eq = 1;
        bool ok = false;
        for (int i = 0; i < n; i++) {
            int d = _s[i] - '0';
            ret = ret * 10 + cnt + (!ok && i != 0 && d > 0) + (ok * d);
            cnt *= 9;
            if (i != 0) {
                cnt += 9 + (!ok * max<int>(0, d - 1));
            }
            else {
                cnt += (!ok * max<int>(0, d - 1));
            }
            if (d == 0)
                ok = true;
            // dbg(ret, cnt);
        }
        return ret + ok;        
    };
    // dbg(fun(r) - fun(l - 1));
    ans += fun(r) - fun(l - 1);
    print(ans);
    Ans[{l, r}] = ans;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    scan(t);
    for (int tt = 1; tt <= t; tt++) {
        cout << "Case #" << tt << ": ";
        solve();
    }
    return 0;
}