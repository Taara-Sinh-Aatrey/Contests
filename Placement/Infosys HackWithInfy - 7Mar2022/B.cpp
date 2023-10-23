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


int solve(int n, vector<int> a, int q, vector<int> queries) {
    vector<int> G(n);
    for (int i = 0; i < n; i++) {
        G[i] = gcd(a[i], a[(i + 1) % n]);
    }
    multiset<int> ms(G.begin(), G.end());
    auto remove = [&] (int i) {
        i = (i + n) % n;
        ms.erase(ms.find(G[i]));
    };
    auto insert = [&] (int i) {
        i = (i + n) % n;
        G[i] = gcd(a[i], a[(i + 1) % n]);
        ms.emplace(G[i]);
    };
    int ans = 0;
    for (auto &i : queries) {
        remove(i - 1); remove(i + 1);
        swap(a[i], a[(i + 1) % n]);
        insert(i - 1); insert(i + 1);
        int x = *ms.rbegin();
        ans ^= x;
    }
    return ans;
}

signed main() {
    print(solve(2, {7, 8}, 3, {0, 1, 1}));
    print(solve(4, {30, 12, 24, 23}, 3, {0, 3, 2}));
    return 0;
}