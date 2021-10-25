// #include "bits/stdc++.h"
// #pragma GCC optimize ("O3")
// #pragma GCC target ("sse4")
// using namespace std;

// bool debug;
// template <typename T, typename U> istream& operator>>(istream &is, pair<T, U> &p) { return is >> p.first >> p.second;}
// template <typename T, typename U> ostream& operator<<(ostream &os, const pair<T, U> &p) { return debug ? os << "(" << p.first << ", " << p.second << ")" : os << p.first << " " << p.second; }
// template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> istream &operator>>(istream &is, T_container &v) { for (T &x : v) is >> x; return is; }
// template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream &operator<<(ostream &os, const T_container &v) { bool f = false; if(debug) { os << "{"; for (const T &x : v) { if (f) os << ", "; os << x; f = true; } os << "}"; } else { for (const T &x : v) { if (f) os << " "; os << x; f = true; } } return os; }
// template <typename T, typename T1, typename... Tail> T amax(T& a, T1 b, Tail... c) {if(b > a) a = b; if constexpr (sizeof...(c) != 0) { amax(a, c...);} return a;} template <typename T, typename T1, typename... Tail> T amin(T& a, T1 b, Tail... c) {if(b < a) a = b;if constexpr (sizeof...(c) != 0) {amin(a, c...);}return a;}
// void scan() {} template <typename Head, typename ...Tail> void scan(Head &H, Tail &...T) { cin >> H; scan(T...); }
// void print() { cout << "\n"; } template <typename Head> void print(const Head &H) { cout << H << "\n"; } template <typename Head, typename ...Tail> void print(const Head &H, const Tail &...T) { cout << H << " "; print(T...); }
// void dbg_out() { cerr << "\n"; } template <typename Head, typename ...Tail> void dbg_out(const Head &H, const Tail &...T) { cerr << " " << H; dbg_out(T...); }
// #ifndef ONLINE_JUDGE
// #define dbg(...) cerr << "[" << #__VA_ARGS__ << "]:", debug = true, dbg_out(__VA_ARGS__), debug = false
// #else
// #define dbg(...)
// #endif


// #define int int64_t
// const int inf = 1e18L + 5, mod = 1e9 + 7, N = 2e5 + 5;

// class segtree {
// public:
//     struct node {
//         // don't forget to set default value (used for leaves)
//         // not necessarily neutral element!
//         int mx = 0;
//         int lazy = 0;

//         void apply(int l, int r, int v) {
//             lazy += v;
//             mx += v;
//         }
//     };

//     node unite(const node &a, const node &b) const {
//         node res;
//         res.mx = max(a.mx, b.mx);
//         return res;
//     }

//     inline void push(int x, int l, int r) {
//         int y = (l + r) >> 1;
//         int z = x + ((y - l + 1) << 1);
//         if (tree[x].lazy != 0) {
//             tree[x + 1].apply(l, y, tree[x].lazy);
//             tree[z].apply(y + 1, r, tree[x].lazy);
//             tree[x].lazy = 0;
//         }
//     }

//     inline void pull(int x, int z) {
//         tree[x] = unite(tree[x + 1], tree[z]);
//     }

//     int n;
//     vector<node> tree;

//     void build(int x, int l, int r) {
//         if (l == r) {
//             return;
//         }
//         int y = (l + r) >> 1;
//         int z = x + ((y - l + 1) << 1);
//         build(x + 1, l, y);
//         build(z, y + 1, r);
//         pull(x, z);
//     }

//     template <typename M>
//     void build(int x, int l, int r, const vector<M> &v) {
//         if (l == r) {
//             tree[x].apply(l, r, v[l]);
//             return;
//         }
//         int y = (l + r) >> 1;
//         int z = x + ((y - l + 1) << 1);
//         build(x + 1, l, y, v);
//         build(z, y + 1, r, v);
//         pull(x, z);
//     }

//     node get(int x, int l, int r, int ll, int rr) {
//         if (ll <= l && r <= rr) {
//             return tree[x];
//         }
//         int y = (l + r) >> 1;
//         int z = x + ((y - l + 1) << 1);
//         push(x, l, r);
//         node res{};
//         if (rr <= y) {
//             res = get(x + 1, l, y, ll, rr);
//         } 
//         else {
//             if (ll > y) {
//                 res = get(z, y + 1, r, ll, rr);
//             } 
//             else {
//                 res = unite(get(x + 1, l, y, ll, rr), get(z, y + 1, r, ll, rr));
//             }
//         }
//         pull(x, z);
//         return res;
//     }

//     template <typename... M>
//     void modify(int x, int l, int r, int ll, int rr, const M&... v) {
//         if (ll <= l && r <= rr) {
//             tree[x].apply(l, r, v...);
//             return;
//         }
//         int y = (l + r) >> 1;
//         int z = x + ((y - l + 1) << 1);
//         push(x, l, r);
//         if (ll <= y) {
//             modify(x + 1, l, y, ll, rr, v...);
//         }
//         if (rr > y) {
//             modify(z, y + 1, r, ll, rr, v...);
//         }
//         pull(x, z);
//     }

//     int find_first_knowingly(int x, int l, int r, const function<bool(const node&)> &f) {
//         if (l == r) {
//             return f(tree[x]) ? l : -1;
//         }
//         push(x, l, r);
//         int y = (l + r) >> 1;
//         int z = x + ((y - l + 1) << 1);
//         int res = -1;
//         if (f(tree[x + 1])) {
//             res = find_first_knowingly(x + 1, l, y, f);
//         } 
//         else if(f(tree[z])) {
//             res = find_first_knowingly(z, y + 1, r, f);
//         }
//         pull(x, z);
//         return res;
//     }

//     int find_first(int x, int l, int r, int ll, int rr, const function<bool(const node&)> &f) {
//         if (ll <= l && r <= rr) {
//             if (!f(tree[x])) {
//                 return -1;
//             }
//             return find_first_knowingly(x, l, r, f);
//         }
//         push(x, l, r);
//         int y = (l + r) >> 1;
//         int z = x + ((y - l + 1) << 1);
//         int res = -1;
//         if (ll <= y) {
//             res = find_first(x + 1, l, y, ll, rr, f);
//         }
//         if (rr > y && res == -1) {
//             res = find_first(z, y + 1, r, ll, rr, f);
//         }
//         pull(x, z);
//         return res;
//     }

//     int find_last_knowingly(int x, int l, int r, const function<bool(const node&)> &f) {
//         if (l == r) {
//             return f(tree[x]) ? l : -1;
//         }
//         push(x, l, r);
//         int y = (l + r) >> 1;
//         int z = x + ((y - l + 1) << 1);
//         int res = -1;
//         if (f(tree[z])) {
//             res = find_last_knowingly(z, y + 1, r, f);
//         } 
//         else if(f(tree[x + 1])) {
//             res = find_last_knowingly(x + 1, l, y, f);
//         }
//         pull(x, z);
//         return res;
//     }

//     int find_last(int x, int l, int r, int ll, int rr, const function<bool(const node&)> &f) {
//         if (ll <= l && r <= rr) {
//             if (!f(tree[x])) {
//                 return -1;
//             }
//             return find_last_knowingly(x, l, r, f);
//         }
//         push(x, l, r);
//         int y = (l + r) >> 1;
//         int z = x + ((y - l + 1) << 1);
//         int res = -1;
//         if (rr > y) {
//             res = find_last(z, y + 1, r, ll, rr, f);
//         }
//         if (ll <= y && res == -1) {
//             res = find_last(x + 1, l, y, ll, rr, f);
//         }
//         pull(x, z);
//         return res;
//     }

//     segtree(int _n) : n(_n) {
//         assert(n > 0);
//         tree.resize(2 * n - 1);
//         build(0, 0, n - 1);
//     }

//     template <typename M>
//     segtree(const vector<M> &v) {
//         n = v.size();
//         assert(n > 0);
//         tree.resize(2 * n - 1);
//         build(0, 0, n - 1, v);
//     }

//     node get(int ll, int rr) {
//         assert(0 <= ll && ll <= rr && rr <= n - 1);
//         return get(0, 0, n - 1, ll, rr);
//     }

//     node get(int p) {
//         assert(0 <= p && p <= n - 1);
//         return get(0, 0, n - 1, p, p);
//     }

//     template <typename... M>
//     void modify(int ll, int rr, const M&... v) {
//         assert(0 <= ll && ll <= rr && rr <= n - 1);
//         modify(0, 0, n - 1, ll, rr, v...);
//     }

//     // find_first and find_last call all FALSE elements
//     // to the left (right) of the sought position exactly once

//     int find_first(int ll, int rr, const function<bool(const node&)> &f) {
//         assert(0 <= ll && ll <= rr && rr <= n - 1);
//         return find_first(0, 0, n - 1, ll, rr, f);
//     }

//     int find_last(int ll, int rr, const function<bool(const node&)> &f) {
//         assert(0 <= ll && ll <= rr && rr <= n - 1);
//         return find_last(0, 0, n - 1, ll, rr, f);
//     }
// };

// static char stdinBuffer[100005];
// static char* stdinDataEnd = stdinBuffer + sizeof (stdinBuffer);
// static const char* stdinPos = stdinDataEnd;

// void readAhead(size_t amount)
// {
//     size_t remaining = stdinDataEnd - stdinPos;
//     if (remaining < amount) {
//        memmove(stdinBuffer, stdinPos, remaining);
//        size_t sz = fread(stdinBuffer + remaining, 1, sizeof (stdinBuffer) - remaining, stdin);
//        stdinPos = stdinBuffer;
//        stdinDataEnd = stdinBuffer + remaining + sz;
//        if (stdinDataEnd != stdinBuffer + sizeof (stdinBuffer))
//          *stdinDataEnd = 0;
//     }
// }

// void readInt(int& x) {
//     // readAhead(16);
//     x = 0;
//     while (*stdinPos >= '0' && *stdinPos <= '9') {
//        x = x * 10 + *stdinPos - '0';
//        ++stdinPos;
//     }
//     stdinPos++;
// }

// void readString(string& x) {
//     readAhead(1000);
//     x = "";
//     while ((*stdinPos >= 'a' && *stdinPos <= 'z') || (*stdinPos >= 'A' && *stdinPos <= 'Z') || (*stdinPos >= '0' && *stdinPos <= '9')) {
//        x += *stdinPos;
//        ++stdinPos;
//     }
//     stdinPos++;
// }

// signed main() {
//     readAhead(100005);
//     int n, k, d, m;
//     // scan(n, k, d, m);
//     readInt(n); readInt(k); readInt(d); readInt(m);
//     vector<int> a(n);
//     // scan(a);
//     for(auto& x : a) readInt(x);
//     a.emplace_back(0);
//     vector<int> suff = a;
//     for (int i = n - 1; i >= 0; i--) suff[i] += suff[i + 1];
//     int ans = 0;
//     vector<int> dp = suff;
//     while (k--) {
//         segtree st(n);
//         vector<int> ndp(n + 1, -inf);
//         for (int i = n - 1; i >= 0; i--) {
//             st.modify(i, i, dp[i + 1]);
//             int lo = i, hi = min(n - 1, i + d);
//             if (lo <= hi) ndp[i] = st.get(lo, hi).mx;
//             amax(ndp[i], a[i] + ndp[i + 1]);
//             st.modify(i, n - 1, m * a[i]);
//         }
//         swap(dp, ndp);
//     }
//     cout << *max_element(dp.begin(), dp.end());
//     return 0;
// }

