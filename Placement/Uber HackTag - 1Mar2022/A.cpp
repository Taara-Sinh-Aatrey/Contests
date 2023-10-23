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

// // int inverse(int a, int m) {
// //     if(a == 0) return 0;
// //     int MOD = m;
// //     int u = 0, v = 1;
// //     while (a != 0) {
// //         int t = m / a;
// //         m -= t * a; swap(a, m);
// //         u -= t * v; swap(u, v);
// //     }
// //     assert(m == 1);
// //     u %= MOD;
// //     if(u < 0) u += MOD;
// //     return u;
// // }

// // // #define int int64_t

// // int solve(string A, string B) {
// //     int n = A.size();
// //     int m = B.size();
// //     const int mod = 1e9 + 7;
// //     vector<int> fact(max(n, m) + 1, 1);
// //     for (int i = 1; i <= n; i++) {
// //         fact[i] = (fact[i - 1] * 1LL * i) % mod;
// //     }
// //     vector<int> fA(26, 0);
// //     for (int i = 0; i < n; i++) {
// //         fA[A[i] - 'a']++;
// //     }
// //     vector<int> fB(26, 0);
// //     for (int i = 0; i < m; i++) {
// //         fB[B[i] - 'a']++;
// //     }
// //     auto ncr = [&] (int N, int R) {
// //         return fact[N] * 1LL * inverse(fact[R] * 1LL * fact[N - R] % mod, mod) % mod;
// //     };
// //     int ans = 1;
// //     for (int ch = 0; ch < 26; ch++) {
// //         int f = min(fA[ch], fB[ch]);
// //         int ways = 0;
// //         for (int len = 0; len <= f; len++) {
// //             ways += ncr(fA[ch], len) * 1LL * ncr(fB[ch], len) % mod;
// //         }
// //         ans = ans * 1LL * ways % mod;
// //     }
// //     ans--;
// //     return ans;
// // }

// // int goodSubsequence(int n, vector<int> a) {
// //     a.emplace_back(0);
// //     vector<int> pos{n};
// //     int sum = 0;
// //     for (int i = n - 1; i >= 0; i--) {
// //         if (a[i] >= 0) {
// //             pos.emplace_back(i);
// //             sum += a[i];
// //         }
// //     }
// //     int ans = pos.size();
// //     for (int it = 0; it + 1 < pos.size(); it++) {
// //         int beg = pos[it + 1] + 1;
// //         int end = pos[it];
// //         sum -= a[pos[it]];
// //         multiset<int> ms(a.begin() + beg, a.begin() + end);
// //         int cur = sum;
// //         int inc = 0;
// //         while (!ms.empty() && cur + *ms.rbegin() >= 0) {
// //             cur += *ms.rbegin();
// //             ms.erase(prev(ms.end()));
// //             inc++;
// //         }
// //         dbg(beg, end, inc);
// //         ans += inc;
// //     }
// //     return ans - 1;
// // }

// const int N = 1e5 + 5;

// vector<int> spf(N, 0);
// vector<bool> prime(N, true);
// vector<int> primes;
// void sieve() {
//     prime[0] = prime[1] = false;
//     for(int i = 2; i < N; i++) {
//         if(prime[i]) {
//             spf[i] = i;
//             primes.push_back(i);
//         }
//         int prod;
//         for(int j = 0; j < (int) primes.size() && primes[j] <= spf[i] && (prod = primes[j] * i) < N; j++) {
//             spf[prod] = primes[j];
//             prime[prod] = false;
//         }
//     }
// }

// void prime_factorise(int num, vector<pair<int, int>> &prime_factors) {
//     while(num > 1) {
//         int factor = spf[num];
//         int cnt = 0;
//         while(spf[num] == factor) {
//             num /= factor;
//             cnt++;
//         }
//         prime_factors.emplace_back(factor, cnt);
//     }
// };

// int solve(int n, vector<int> a) {
//     sieve();
//     reverse(a.begin(), a.end());
//     const int inf = 1e9;
//     vector<int> dp(n, -1);
//     vector<int> lst(N, -1);
//     for (int i = 0; i < n; i++) {
//         int j = -1;
//         vector<pair<int, int>> prime_factors;
//         prime_factorise(abs(a[i]), prime_factors);
//         for (auto &[p, cnt] : prime_factors) {
//             j = max(j, lst[p]);
//             lst[p] = i;
//         }
//         dp[i] = j;
//     }
//     int ans = 0;
//     int cur = n - 1;
//     while (cur >= 0) {
//         int nxt = dp[cur];
//         if (nxt == -1)
//             break;
//         int mx = *max_element(a.begin() + nxt, a.begin() + cur + 1);
//         int g = gcd(a[nxt], a[cur]);
//         ans += mx - g;
//         cur = nxt;
//     }
//     return ans;
// }

// signed main() {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     // int n;
//     // cin >> n;
//     // vector<int> a(n);
//     // scan(a);
//     // print(solve("c", "aab"));
//     // print(solve("abbbb", "b"));
//     // print(goodSubsequence(2, {-5, -2}));
//     // print(goodSubsequence(4, {2, -2, 4, -3}));
//     // print(goodSubsequence(6, {2, 3, -4, -1, -2, -1}));
//     // cout << goodSubsequence(n, a);
//     // print(solve(5, {46, 29, 41, 7, 23}));
//     // print(solve(7, {38, 13, 43, 47, 6, 43, 3}));
//     // print(solve(7, {21, 31, 33, 23, 14, 37, 3}));
//     return 0;
// }

// /*
// i                   j
// 10                 15
// */

#include <bits/stdc++.h>
using namespace std;

#define int int64_t

class segtree {
public:
    struct node {
        int sum = 0, lazy = 0;

        void apply(int l, int r, int v) {
            sum += (r - l + 1) * v;
            lazy += v;
        }
    };

    node unite(const node &a, const node &b) const {
        node res;
        res.sum = a.sum + b.sum;
        return res;
    }

    inline void push(int x, int l, int r) {
        int y = (l + r) >> 1, z = x + ((y - l + 1) << 1);
        if (tree[x].lazy != 0) {
            tree[x + 1].apply(l, y, tree[x].lazy);
            tree[z].apply(y + 1, r, tree[x].lazy);
            tree[x].lazy = 0;
        }
    }

    inline void pull(int x, int z) { tree[x] = unite(tree[x + 1], tree[z]); }

    int n;
    vector<node> tree;

    void build(int x, int l, int r) {
        if (l == r) {
            return;
        }
        int y = (l + r) >> 1, z = x + ((y - l + 1) << 1);
        build(x + 1, l, y);
        build(z, y + 1, r);
        pull(x, z);
    }

    template <typename M>
    void build(int x, int l, int r, const vector<M> &v) {
        if (l == r) {
            tree[x].apply(l, r, v[l]);
            return;
        }
        int y = (l + r) >> 1, z = x + ((y - l + 1) << 1);
        build(x + 1, l, y, v);
        build(z, y + 1, r, v);
        pull(x, z);
    }

    node get(int x, int l, int r, int ll, int rr) {
        if (ll <= l && r <= rr) {
            return tree[x];
        }
        int y = (l + r) >> 1, z = x + ((y - l + 1) << 1);
        push(x, l, r);
        node res{};
        if (rr <= y)
            res = get(x + 1, l, y, ll, rr);
        else if (ll > y)
            res = get(z, y + 1, r, ll, rr);
        else
            res = unite(get(x + 1, l, y, ll, rr), get(z, y + 1, r, ll, rr));
        pull(x, z);
        return res;
    }

    template <typename... M>
    void modify(int x, int l, int r, int ll, int rr, const M&... v) {
        if (ll <= l && r <= rr) {
            tree[x].apply(l, r, v...);
            return;
        }
        int y = (l + r) >> 1, z = x + ((y - l + 1) << 1);
        push(x, l, r);
        if (ll <= y)
            modify(x + 1, l, y, ll, rr, v...);
        if (rr > y)
            modify(z, y + 1, r, ll, rr, v...);
        pull(x, z);
    }

    segtree(int _n) : n(_n) {
        assert(n > 0);
        tree.resize(2 * n - 1);
        build(0, 0, n - 1);
    }

    template <typename M>
    segtree(const vector<M> &v) {
        n = v.size();
        assert(n > 0);
        tree.resize(2 * n - 1);
        build(0, 0, n - 1, v);
    }

    node get(int ll, int rr) {
        assert(0 <= ll && ll <= rr && rr <= n - 1);
        return get(0, 0, n - 1, ll, rr);
    }

    node get(int p) {
        assert(0 <= p && p <= n - 1);
        return get(0, 0, n - 1, p, p);
    }

    template <typename... M>
    void modify(int ll, int rr, const M&... v) {
        assert(0 <= ll && ll <= rr && rr <= n - 1);
        modify(0, 0, n - 1, ll, rr, v...);
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<segtree> st(2);
    vector<vector<int>> dp(2, vector<int>(n));
    for (int i = 0; i < 2; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            sum += ((i + j) % 2 == 0 ? 1 : -1) * a[j];
            dp[i][j] = sum;
        }
        st[i] = segtree(dp[i]);
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
        
    }
}

signed main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

