#include "bits/stdc++.h"
using namespace std;

template <typename T, typename U> istream& operator>>(istream &is, pair<T, U> &p) { return is >> p.first >> p.second; }
template <typename T, typename U> ostream& operator<<(ostream &os, const pair<T, U> &p) { return os << p.first << " " << p.second; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> istream &operator>>(istream &is, T_container &v) { for (T &x : v) is >> x; return is; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream &operator<<(ostream &os, const T_container &v) { bool f = false; for (const T &x : v) { if (f) os << " "; os << x; f = true; } return os; }
void scan() {} template <typename Head, typename ...Tail> void scan(Head &H, Tail &...T) { cin >> H; scan(T...); }
void print() { cout << "\n"; } template <typename Head> void print(const Head &H) { cout << H << "\n"; } template <typename Head, typename ...Tail> void print(const Head &H, const Tail &...T) { cout << H << " "; print(T...); }
template <typename T, typename T1, typename... Tail> T amin(T& a, T1 b, Tail... c) { if(b < a) a = b; if constexpr (sizeof...(c) != 0) { amin(a, c...); } return a; } template <typename T, typename T1, typename... Tail> T amax(T& a, T1 b, Tail... c) { if(b > a) a = b; if constexpr (sizeof...(c) != 0) { amax(a, c...); } return a; }

#ifdef AATREY_DEBUG
#include "debug.hpp"
#else
#define dbg(...)
#endif


long getMaximumEvenSum(vector<int> a) {
#define int long
    const int inf = 1e18L + 5;
    vector<int> odds;
    int sum = 0;
    for (auto &x : a) {
        if (x & 1)
            odds.emplace_back(x);
        else if (x > 0)
            sum += x;
    }
    sort(odds.rbegin(), odds.rend());
    for (int i = 0; i + 1 < odds.size(); i += 2) {
        int cur = odds[i] + odds[i + 1];
        if (cur <= 0) break;
        sum += cur;
    }
    return sum;
#undef int
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << getMaximumEvenSum({2, 3, 6, -5, 10, 1, 1}) << endl;
    cout << getMaximumEvenSum({6, 3, 4, -1, 9, 17}) << endl;
    cout << getMaximumEvenSum({-1, -2, -3, 8, 7}) << endl;
    return 0;
}