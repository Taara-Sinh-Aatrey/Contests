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

void solve() {
    int n;
    scan(n);
    vector<int> a(2 * n);
    int x = 1e9, sum = 0;
    for (int i = 0; i < n; i++) {
        if (i < 30)
            a[i] = 1LL << i;
        else
            a[i] = x--;
        sum += a[i];
        if (i > 0)
            cout << " ";
        cout << a[i];
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        cin >> a[n + i];
        sum += a[n + i];
    }
    sort(a.begin(), a.end());
    assert(sum % 2 == 0);
    sum /= 2;
    vector<int> ans;
    while (sum > (1LL << 30) - 1) {
        ans.emplace_back(a.back());
        sum -= a.back();
        a.pop_back();
    }
    assert(sum < (1LL << 30));
    for (int bit = 0; bit < 30; bit++) {
        if (sum >> bit & 1) {
            ans.emplace_back(1LL << bit);
        }
    }
    for (int i = 0; i < int(ans.size()); i++) {
        if (i > 0) {
            cout << " ";
        }
        cout << ans[i];
        sum -= ans[i];
    }
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    scan(t);
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
    return 0;
}