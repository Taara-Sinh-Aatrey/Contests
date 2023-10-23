#include "bits/stdc++.h"
#include <cmath>
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

int countSubArrays(int n, int k, string s) {
    vector<int> st(26);
    int ans = 0;
    vector<int> low(n, -1);
    int cnt = 0;
    int j = -1;
    for (int i = 0; i < n; i++) {
        while (j + 1 < n && cnt < k) {
            j++;
            if (st[s[j] - 'a'] == 0)
                cnt++;
            st[s[j] - 'a']++;
        }
        if (cnt == k)
            low[i] = j;
        st[s[i] - 'a']--;
        if (st[s[i] - 'a'] == 0)
            cnt--;
    }
    vector<int> high(n, -1);
    j = -1;
    st.assign(26, 0);
    for (int i = 0; i < n; i++) {
        while (j + 1 < n && cnt + (st[s[j + 1] - 'a'] ? 0 : 1) <= k) {
            j++;
            if (st[s[j] - 'a'] == 0)
                cnt++;
            st[s[j] - 'a']++;
        }
        if (cnt == k)
            high[i] = j;
        st[s[i] - 'a']--;
        if (st[s[i] - 'a'] == 0)
            cnt--;
    }
    for (int i = 0; i < n; i++) {
        if (low[i] != -1) {
            ans += high[i] - low[i] + 1;
        }
    }
    return ans;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    print(countSubArrays(4, 2, "abbc"));
    return 0;
}