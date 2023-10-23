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

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int N = *max_element(arr, arr + n);
    vector<int> mp[N + 1];
    for (int i = n - 1; i >= 0; i--) {
        mp[arr[i]].emplace_back(i);
    }
    vector<int> ret;
    bool ok = true;
    for (int i = 1; i <= N; i++) {
        auto &p = mp[i];
        if (p.empty()) continue;
        reverse(p.begin(), p.end());
        int del = int(p.size()) - 1;
        for (auto &idx : p) {
            if ((ret.empty() || idx > ret.back()) && del > 0) {
                ret.emplace_back(idx);
                del--;
            }
        }
        ok &= (del == 0);
    }
    if (!ok) {
        cout << -1 << '\n';
    }
    else {
        for (int i = 0; i < ret.size(); i++) {
            cout << arr[ret[i]] << '\n';
            // cout << ret[i] << '\n';
        }
    }
    return 0;
}