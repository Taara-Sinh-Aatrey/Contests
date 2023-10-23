Write debug.hpp in /home/contestant
------------ END -----------
fcompile() { g++ -std=c++17 -O2 -I/home/contestant sol.cpp -o sol.out }
frun() { fcompile sol && time ./sol.out; }
dbcompile() { g++ -std=c++17 -DLOCAL -DGLIBCXX_DEBUG -I/home/contestant sol.cpp -o sol.out }
dbrun() { dbcompile sol && ./sol.out; }
defrun() { dbcompile sol && ./sol.out < in > out; }
------------ END -----------
g++ -std=c++17 -O2 -I/home/contestant sol.cpp -o sol.out
g++ -std=c++17 -O2 -I/home/contestant brute.cpp -o brute.out
g++ -std=c++17 -O2 -I/home/contestant gen.cpp -o gen.out
for (( i = 1; ; i++ )); do
    echo -n "Case# $i"
    ./gen.out > in
    ./sol.out < in > out
    brute.out < in > ok
    printf "\r"
    if [[ $(diff -w out ok) ]];
    then
        echo "Case# $i"
        break
    fi
done
------------ END -----------
int inverse(int a, int m) {
    if (a == 0) return 0;
    int MOD = m, u = 0, v = 1;
    while (a != 0) {
        int t = m / a;
        m -= t * a; swap(a, m);
        u -= t * v; swap(u, v);
    }
    assert(m == 1);
    u %= MOD;
    if (u < 0) u += MOD;
    return u;
}
class CRT {
public:
    // While declaring CRT, vector of primes must be passed to the constructor
    // call get function with vector of remainders to get back the number
    int n;
    vector<int> m;
    CRT(vector<int> p) {
        m = p, n = m.size(); }
    // (rem, mod)
    pair<int, int> get(vector<int> r) {
        assert(r.size() == m.size());
        int n = int(r.size());
        // Contracts: 0 <= r0 < m0
        int r0 = 0, m0 = 1;
        for (int i = 0; i < n; i++) {
            assert(m[i] >= 1);
            int r1 = (r[i] % m[i] + m[i]) % m[i], m1 = m[i];
            if (m0 < m1) {
                swap(r0, r1); swap(m0, m1); }
            if (m0 % m1 == 0) {
                if (r0 % m1 != r1) return {0, 0};
                continue;
            }
            int g = __gcd(m0, m1), im = inverse(m0, m1);
            int u1 = (m1 / g);
            if ((r1 - r0) % g) return {0, 0};
            int x = (r1 - r0) / g % u1 * im % u1;
            r0 += x * m0; m0 *= u1;
            if (r0 < 0) r0 += m0;
        }
        return {r0, m0};
        // m0 == 0 means no solution exists }
    };
------------ END -----------
template <typename T>
vector<int> kmp_table(const T &s) {
    int n = s.size(), len = 0;
    vector<int> lps(n, 0);
    for (int i = 1; i < n; i++) {
        while (len > 0 && s[i] != s[len]) len = lps[len - 1];
        if (s[i] == s[len]) len++;
        lps[i] = len; }
    return lps; }
// find occurences of `pat` in `text`
template <typename T>
int kmp_search(const T& text, const T& pat) {
    auto lps = kmp_table(pat);
    int ret = 0;
    // finding pattern in text using lps
    int n = text.size();
    int m = pat.size();
    for (int i = 0, j = 0; i < n; ) {
        if (pat[j] == text[i]) j++, i++;
        if (j == m) {
            // pattern found
            ret++; j = lps[j - 1]; }
        else if (i < n && pat[j] != text[i]) {
            if (j != 0) j = lps[j - 1];
            else i++; } }
    return ret; }
------------ END -----------
template <typename T>
vector<int> z_function(const T &s) {
    int l = 0, r = 0, n = s.size();
    vector<int> z(n, n);
    for (int i = 1; i < n; i++) {
        z[i] = (i > r ? 0 : min(r - i + 1, z[i - l]));
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            z[i]++;
        if (i + z[i] - 1 > r) {
            l = i; r = i + z[i] - 1; }
    }
    return z; }
------------ END -----------
// Code of fft taken from https://cp-algorithms.com/algebra/fft.html
// And modified as per my use 
ll primeRoot(ll p = mod, ll x = 0) {
    vll v;
    ll t = p - 1;
    for (ll i = 2; i <= t; i++) {
        if (i * i > t) { break; }
        if (t % i == 0) {
            v.pb((p - 1) / i);
            while (t % i == 0) {
                t /= i; }
        } }
    if (t > 1) v.pb((p - 1) / t);
    for (ll i = x + 1; i < p; i++) {
        ll flag = 0;
        for (ll j = 0; j < (ll)v.size(); j++) {
            if (powerM(i, v[j], p) == 1) {
                flag = 1; break; }
        }
        if (flag == 0) return i;
    }
    return 0; }
void fft(vector<int> & a, bool invert) {
    int n = a.size();
    // assert((n & (n - 1)) == 0);
    // in other words n is power of 2
    // We write mod = c. 2^k + 1
    // So this fft function works only if input size <= 2 ^ k
    // for mod = 998244353, k = 23, so input size can be as large as 8e6
    // assert((mod - 1) % n == 0);
    // root is nth root of unity under primitive field of mod
    // root = g ^ (mod - 1) / n, for mod = 998244353, g = 3 works well
    int root = Pow(3, (mod - 1) / n);
    int inv = Pow(root, mod - 2);
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1) j ^= bit;
        j ^= bit;
        if (i < j) swap(a[i], a[j]); }
    for (int len = 2; len <= n; len <<= 1) {
        int wlen = invert ? inv : root;
        for (int i = len; i < n; i <<= 1)
            wlen = wlen * wlen % mod;
        for (int i = 0; i < n; i += len) {
            int w = 1;
            for (int j = 0; j < len / 2; j++) {
                int u = a[i+j], v = a[i+j+len/2] * w % mod;
                a[i+j] = u + v < mod ? u + v : u + v - mod;
                a[i+j+len/2] = u - v >= 0 ? u - v : u - v + mod;
                w = w * wlen % mod; }
        } }
    if (invert) {
        int n_1 = Pow(n, mod - 2);
        for (int & x : a) { x = x * n_1 % mod; }
    } }
void multiply(const vector<int> &a, const vector<int> &b, vector<int> &c) {
    // c = a * b
    vector<int> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < (int) a.size() + (int) b.size()) 
        n <<= 1;
    fa.resize(n);
    fb.resize(n);
    c.resize(n);
    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++)
        c[i] = fa[i] * fb[i] % mod;
    fft(c, true); }
------------ END -----------
class trie {
public:
    vector<vector<int>> child;
    vector<int> val;
    // TODO: set MIN_CHAR
    const char MIN_CHAR = 'a';
    // TODO: set alphabet
    const int alphabet = 26;
    int create_node() {
        child.emplace_back(alphabet, -1);
        // TODO: set default value for trie nodes
        val.emplace_back(0);
        return child.size() - 1; }
    trie() { create_node(); }
    void add(string s, int value = 1) {
        int cur = 0, n = s.size();
        for (int i = 0; i < n; i++) {
            int ch = s[i] - MIN_CHAR;
            if (child[cur][ch] == -1) child[cur][ch] = create_node();
            cur = child[cur][ch];
            // TODO: check if intermediate nodes should be updated
            val[cur] += value; }
        // TODO: check if leaf node should should be updated
        val[cur] = value; }
    int search(string s, int start = 0) {
        int cur = start, n = s.size();
        for (int i = 0; i < n; i++) {
            int ch = s[i] - MIN_CHAR;
            if (child[cur][ch] == -1) return -1;
            cur = child[cur][ch]; }
        return cur; }
    void remove(string s, int value = 1) {
        int cur = 0, n = s.size();
        for (int i = 0; i < n; i++) {
            int ch = s[i] - MIN_CHAR;
            cur = child[cur][ch];
            assert(cur != -1 && val[cur] > 0);
            // TODO: check if intermediate nodes should be updated
            val[cur] -= value; }
        // TODO: check if leaf node should should be updated
        val[cur] = value; }
};
------------ END -----------
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int rand(int a, int b) { return uniform_int_distribution<int>(a, b)(rng); }
------------ END -----------
// ---------------- debug.hpp START ------------------
#include "bits/stdc++.h"
using namespace std;
void dbg_print(const int32_t &x) { cerr << x; }
void dbg_print(const uint32_t &x) { cerr << x; }
void dbg_print(const int64_t &x) { cerr << x; }
void dbg_print(const uint64_t &x) { cerr << x; }
void dbg_print(const float &x) { cerr << x; }
void dbg_print(const double &x) { cerr << x; }
void dbg_print(const long double &x) { cerr << x; }
void dbg_print(const char &x) { cerr << x; }
void dbg_print(const string &x) { cerr << x; }
template < typename T_container, typename T = typename enable_if < !is_same<T_container, string>::value, typename T_container::value_type >::type >
void dbg_print(const T_container &v);
template <typename T, typename U>
void dbg_print(const pair<T, U> &p) {
    cerr << "(" << p.first << ", " << p.second << ")"; }
template < typename T_container, typename T = typename enable_if < !is_same<T_container, string>::value, typename T_container::value_type >::type >
void dbg_print(const T_container &v) {
    bool f = false;
    cerr << "[";
    for (const T &x : v) {
        if (f) cerr << ", ";
        dbg_print(x);
        f = true; }
    cerr << "]"; }
template <typename Head>
void dbg_out(string var, const Head &H) {
    cerr << var << " = ";
    dbg_print(H);
    cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(string var, const Head &H, const Tail &...T) {
    for (int i = 0, b = 0; i < int(var.size()); i++) {
        if (var[i] == '(' || var[i] == '{') {
            b++; }
        else if (var[i] == ')' || var[i] == '}') {
            b--; }
        else if (var[i] == ',' && b == 0) {
            cerr << var.substr(0, i) << " = ";
            dbg_print(H);
            cerr << " | ";
            dbg_out(var.substr(var.find_first_not_of(' ', i + 1)), T...);
            break; }
    } }
#define dbg(...) dbg_out(#__VA_ARGS__, __VA_ARGS__)
------------ END -----------
vector<int> spf(N, 0), unique_primes(N, 0), primes;
vector<bool> prime(N, true);
void sieve() {
    prime[0] = prime[1] = false;
    for (int i = 2; i < N; i++) {
        if (prime[i]) {
            spf[i] = i; primes.push_back(i); }
        int64_t prod;
        for (int j = 0; j < (int) primes.size() && primes[j] <= spf[i] && (prod = primes[j] * int64_t(i)) < N; j++) {
            spf[prod] = primes[j]; prime[prod] = false; }
    }
    for (int i = 2; i < N; i++) {
        int p = spf[i];
        unique_primes[i] = unique_primes[i / p] + ((i / p) % p != 0); }
}
void factorise(int num, vector<int> &factors) {
    factors.emplace_back(1);
    while (num > 1) {
        int factor = spf[num], cnt = 0, p = 1;
        int sz = factors.size();
        while (spf[num] == factor) {
            num /= factor;
            p *= factor;
            for (int i = 0; i < sz; i++)
                factors.emplace_back(factors[i] * p);
            cnt++; }
    }
};
------------ END -----------
#define int128_t __int128_t
#define uint128_t __uint128_t
istream& operator>>(istream& is, int128_t &number) { bool negative = false; char c; number = 0; c = getchar(); if (c == '-') { negative = true; c = getchar(); } for (; (c >= '0' && c <= '9'); c = getchar()) number = number * 10 + (c - '0'); if (negative) number *= -1; return is; }
istream& operator>>(istream& is, uint128_t &number) { char c; number = 0; c = getchar(); for (; (c >= '0' && c <= '9'); c = getchar()) number = number * 10 + (c - '0'); return is; }
ostream& operator<<(ostream& os, int128_t x) {if (x < 0) { os << "-"; x *= -1; } if (x == 0) { return os << "0"; } string s; while (x) { s += char(x % 10 + '0'); x /= 10; } reverse(s.begin(), s.end()); return os << s; }
ostream& operator<<(ostream& os, uint128_t x) {if (x == 0) { return os << "0"; } string s; while (x) { s += char(x % 10 + '0'); x /= 10; } reverse(s.begin(), s.end()); return os << s;}
void dbg_print(const int128_t &x) { cerr << x; } void dbg_print(const uint128_t &x) { cerr << x; }
------------ END -----------
template <typename T, class F = function<T(const T&, const T&)>>
class SparseTable {
public:
    int n;
    vector<vector<T>> mat;
    F func;
    SparseTable(const vector<T>& a, const F& f) : func(f) {
        n = static_cast<int>(a.size());
        int max_log = 64 - __builtin_clzll(n);
        mat.resize(max_log);
        mat[0] = a;
        for (int j = 1; j < max_log; j++) {
            mat[j].resize(n - (1 << j) + 1);
            for (int i = 0; i <= n - (1 << j); i++) {
                mat[j][i] = func(mat[j - 1][i], mat[j - 1][i + (1 << (j - 1))]); }
        } }
    T get(int from, int to) const {
        assert(0 <= from && from <= to && to <= n - 1);
        int lg = 64 - __builtin_clzll(to - from + 1) - 1;
        return func(mat[lg][from], mat[lg][to - (1 << lg) + 1]); }
};
------------ END -----------
class segtree {
public:
    struct node {
        void apply(int l, int r, int v) { }
    };
    node unite(const node &a, const node &b) const {
        node res;
        return res; }
    inline void push(int x, int l, int r) {
        int y = (l + r) >> 1, z = x + ((y - l + 1) << 1);
        if (tree[x].lazy != 0) {
            tree[x + 1].apply(l, y, tree[x].lazy);
            tree[z].apply(y + 1, r, tree[x].lazy);
            tree[x].lazy = 0; }
    }
    inline void pull(int x, int z) { tree[x] = unite(tree[x + 1], tree[z]); }
    int n;
    vector<node> tree;
    void build(int x, int l, int r) {
        if (l == r) {
            return; }
        int y = (l + r) >> 1, z = x + ((y - l + 1) << 1);
        build(x + 1, l, y);
        build(z, y + 1, r);
        pull(x, z); }
    template <typename M>
    void build(int x, int l, int r, const vector<M> &v) {
        if (l == r) {
            tree[x].apply(l, r, v[l]);
            return; }
        int y = (l + r) >> 1, z = x + ((y - l + 1) << 1);
        build(x + 1, l, y, v);
        build(z, y + 1, r, v);
        pull(x, z); }
    node get(int x, int l, int r, int ll, int rr) {
        if (ll <= l && r <= rr) {
            return tree[x]; }
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
        return res; }
    template <typename... M>
    void modify(int x, int l, int r, int ll, int rr, const M&... v) {
        if (ll <= l && r <= rr) {
            tree[x].apply(l, r, v...);
            return; }
        int y = (l + r) >> 1, z = x + ((y - l + 1) << 1);
        push(x, l, r);
        if (ll <= y)
            modify(x + 1, l, y, ll, rr, v...);
        if (rr > y)
            modify(z, y + 1, r, ll, rr, v...);
        pull(x, z); }
    int find_first_knowingly(int x, int l, int r, const function<bool(const node&)> &f) {
        if (l == r) {
            return f(tree[x]) ? l : -1; }
        push(x, l, r);
        int y = (l + r) >> 1, z = x + ((y - l + 1) << 1);
        int res = -1;
        if (f(tree[x + 1]))
            res = find_first_knowingly(x + 1, l, y, f);
        else if (f(tree[z]))
            res = find_first_knowingly(z, y + 1, r, f);
        pull(x, z);
        return res; }
    int find_first(int x, int l, int r, int ll, int rr, const function<bool(const node&)> &f) {
        if (ll <= l && r <= rr) {
            if (!f(tree[x])) {
                return -1; }
            return find_first_knowingly(x, l, r, f); }
        push(x, l, r);
        int y = (l + r) >> 1, z = x + ((y - l + 1) << 1);
        int res = -1;
        if (ll <= y)
            res = find_first(x + 1, l, y, ll, rr, f);
        if (rr > y && res == -1)
            res = find_first(z, y + 1, r, ll, rr, f);
        pull(x, z);
        return res; }
    int find_last_knowingly(int x, int l, int r, const function<bool(const node&)> &f) {
        if (l == r) {
            return f(tree[x]) ? l : -1; }
        push(x, l, r);
        int y = (l + r) >> 1, z = x + ((y - l + 1) << 1);
        int res = -1;
        if (f(tree[z]))
            res = find_last_knowingly(z, y + 1, r, f);
        else if (f(tree[x + 1]))
            res = find_last_knowingly(x + 1, l, y, f);
        pull(x, z);
        return res; }
    int find_last(int x, int l, int r, int ll, int rr, const function<bool(const node&)> &f) {
        if (ll <= l && r <= rr) {
            if (!f(tree[x])) {
                return -1; }
            return find_last_knowingly(x, l, r, f); }
        push(x, l, r);
        int y = (l + r) >> 1, z = x + ((y - l + 1) << 1);
        int res = -1;
        if (rr > y)
            res = find_last(z, y + 1, r, ll, rr, f);
        if (ll <= y && res == -1)
            res = find_last(x + 1, l, y, ll, rr, f);
        pull(x, z);
        return res; }
    segtree(int _n) : n(_n) {
        assert(n > 0);
        tree.resize(2 * n - 1);
        build(0, 0, n - 1); }
    template <typename M>
    segtree(const vector<M> &v) {
        n = v.size();
        assert(n > 0);
        tree.resize(2 * n - 1);
        build(0, 0, n - 1, v); }
    node get(int ll, int rr) {
        assert(0 <= ll && ll <= rr && rr <= n - 1);
        return get(0, 0, n - 1, ll, rr); }
    node get(int p) {
        assert(0 <= p && p <= n - 1);
        return get(0, 0, n - 1, p, p); }
    template <typename... M>
    void modify(int ll, int rr, const M&... v) {
        assert(0 <= ll && ll <= rr && rr <= n - 1);
        modify(0, 0, n - 1, ll, rr, v...); }
    // find_first and find_last call all FALSE elements
    // to the left (right) of the sought position exactly once
    int find_first(int ll, int rr, const function<bool(const node&)> &f) {
        assert(0 <= ll && ll <= rr && rr <= n - 1);
        return find_first(0, 0, n - 1, ll, rr, f); }
    int find_last(int ll, int rr, const function<bool(const node&)> &f) {
        assert(0 <= ll && ll <= rr && rr <= n - 1);
        return find_last(0, 0, n - 1, ll, rr, f); }
};
------------ END -----------
template<typename T_string = string>
class suffix_array {
    /*
    Notes: suffix[i] cotains the index of (i+1)th smallest suffix array
    rank[i] contains order of the suffix array starting at ith index in the sorted suffix array
    lcp[i] = lcs of i & (i-1)th smallest suffix array
    Warnings: Have you built the sparse table for range_min_query?
    */
public:
    T_string s;
    int n;
    vector<int> suffix, rank, lcp;
    vector<vector<int>> mat;
    function<int(int, int)> func;
    suffix_array(T_string _s, bool build_rmq = false) : s(_s) {
        n = s.size(); build_suffix(); build_lcp();
        if (build_rmq) build_sparse_table(); }
    void build_suffix() {
        suffix.resize(n);
        for (int i = 0; i < n; i++) suffix[i] = i;
        bool large_alphabet = false;
        for (int i = 0; i < n; i++) if (s[i] < 0 || s[i] >= 128) large_alphabet = true;
        // Sort each suffix by the first character.
        if (large_alphabet) {
            sort(suffix.begin(), suffix.end(), [&](int a, int b) {
                return s[a] < s[b];
            });
        } else {
            vector<int> freq(128, 0);
            for (int i = 0; i < n; i++)
                freq[s[i]]++;
            for (int c = 1; c < 128; c++)
                freq[c] += freq[c - 1];
            for (int i = 0; i < n; i++)
                suffix[--freq[s[i]]] = i; }
        // Compute the rank of each suffix. Tied suffixes share the same rank.
        rank.resize(n);
        rank[suffix[0]] = 0;
        for (int i = 1; i < n; i++)
            rank[suffix[i]] = s[suffix[i]] == s[suffix[i - 1]] ? rank[suffix[i - 1]] : i;
        vector<int> next_index(n);
        vector<int> values(n);
        bool done = false;
        for (int len = 1; len < n && !done; len *= 2) {
            // next_index[i] = the next index to use for a suffix of rank i. We insert them in order of the rank of the
            // suffix that comes len characters after the current suffix.
            for (int i = 0; i < n; i++)
                next_index[i] = i;
            // Compute the suffix array for 2 * len. Suffixes of length <= len are prioritized first.
            for (int i = n - len; i < n; i++)
                values[next_index[rank[i]]++] = i;
            for (int i = 0; i < n; i++) {
                int prev = suffix[i] - len;
                if (prev >= 0)
                    values[next_index[rank[prev]]++] = prev; }
            swap(suffix, values);
            // Compute the rank array for 2 * len.
            values[suffix[0]] = 0;
            done = true;
            for (int i = 1; i < n; i++) {
                int cur = suffix[i], prev = suffix[i - 1];
                if (cur + len < n && prev + len < n && rank[cur] == rank[prev] && rank[cur + len] == rank[prev + len]) {
                    values[cur] = values[prev];
                    done = false;
                } else {
                    values[cur] = i; }
            }
            swap(rank, values); }
    }
    void build_lcp() {
        lcp.resize(n);
        int k = 0;
        for (int i = 0; i < n; i++) {
            if (rank[i] == 0) continue;
            int j = suffix[rank[i] - 1];
            while (i + k < n && j + k < n && s[i + k] == s[j + k]) {
                k++; }
            lcp[rank[i]] = k;
            k = max<int>(0, k - 1); }
    }
    void build_sparse_table() {
        func = [&](const int& i, const int& j) {
            if (lcp[i] != lcp[j]) {
                return lcp[i] < lcp[j] ? i : j; }
            return min(i, j);
        };
        int max_log = 64 - __builtin_clzll(n);
        mat.resize(max_log);
        mat[0].resize(n);
        iota(mat[0].begin(), mat[0].end(), 0);
        for (int j = 1; j < max_log; j++) {
            mat[j].resize(n - (1 << j) + 1);
            for (int i = 0; i <= n - (1 << j); i++) {
                mat[j][i] = func(mat[j - 1][i], mat[j - 1][i + (1 << (j - 1))]); }
        } }
    int get_lcp(int from, int to) {
        if (from == to) {
            return n - from; }
        from = rank[from];
        to = rank[to];
        if (from > to) {
            swap(from, to); }
        assert(0 <= from && from <= to && to <= n - 1);
        // lcp(from, to) = min(lcp[from + 1], ......, lcp[to - 1], lcp[to])
        from++;
        int lg = 64 - __builtin_clzll(to - from + 1) - 1;
        // mn = index at which min lcp occurs
        int mn = func(mat[lg][from], mat[lg][to - (1 << lg) + 1]);
        return lcp[mn]; }
};
------------ END -----------
// a * s + b * t = gcd(a, b) = g auto [g, s, t] = extended_gcd(a, b)
tuple<int, int, int> extended_gcd(int a, int b) {
    int x = 1, x1 = 0, y = 0, y1 = 1;
    while (b > 0) {
        int q = a / b;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a, b) = make_tuple(b, a - q * b); }
    return make_tuple(a, x, y); }
------------ END -----------
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// functions: set.insert(val), *(set.find_by_order(order-1)), set.order_of_key(val)
// less_equal for multiset
------------ END -----------
bool miller_rabin(unsigned n) {
    if (n < 2)
        return false;
    for (unsigned p : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29})
        if (n % p == 0)
            return n == p;
    int r = __builtin_ctz(n - 1);
    unsigned d = (n - 1) >> r;
    for (unsigned a : {2, 7, 61}) {
        unsigned x = Pow(a % n, d, n);
        if (x <= 1 || x == n - 1)
            continue;
        for (int i = 0; i < r - 1 && x != n - 1; i++)
            x = unsigned(uint64_t(x) * x % n);
        if (x != n - 1)
            return false; }
    return true; }
------------ END -----------
template <typename T = int64_t>
class fenwick {
public:
    int n;
    vector<T> fetree;
    fenwick(int _n) {
        n = _n;
        fetree = vector<T> (n + 1, 0); }
    template <typename T_array>
    void build(const T_array & initial) {
        assert(int(initial.size()) == n);
        for (int i = 1; i <= n; i++) {
            fetree[i] = initial[i - 1];
            for (int k = (i & -i) >> 1; k > 0; k >>= 1)
                fetree[i] += fetree[i - k]; }
    }
    void update(int idx, T change) {
        ++idx;
        while (idx <= n) {
            fetree[idx] += change;
            idx += (idx & (-idx)); }
    }
    T query(int idx) const {
        ++idx;
        T s = 0;
        while (idx > 0) {
            s += fetree[idx];
            idx -= (idx & (-idx)); }
        return s; }
    T querylr(int l, int r) const {
        return query(r) - query(l - 1); }
    void updatelr(int l, int r, T change) {
        update(l, change);
        update(r + 1, -change); }
    T get(int i) const {
        assert(0 <= i && i < n);
        int above = i + 1;
        T sum = fetree[above];
        above -= above & -above;
        while (i != above) {
            sum -= fetree[i];
            i -= i & -i; }
        return sum; }
    static int highest_bit(int x) {
        return x == 0 ? -1 : 31 - __builtin_clz(x); }
    int find_last_prefix(T sum) const {
        if (sum < 0)
            return -1;
        int prefix = 0;
        for (int k = highest_bit(n); k >= 0; k--) {
            if (prefix + (1 << k) <= n && fetree[prefix + (1 << k)] <= sum) {
                prefix += 1 << k;
                sum -= fetree[prefix]; }
        }
        return prefix; }
};
------------ END -----------
/*
we know f(1) f(2) f(3)
f(i) = 1 * f(i - 1) + 2 * f(i - 2) + 3 * f(i - 3)
f(i) = a * f(i - 1) + b * f(i - 2) + c * f(i - 3)
               F                  init
|f(i)    | = |a b c| ^ (i - 3)   |f(3)|
|f(i - 1)|   |1 0 0|           * |f(2)|
|f(i - 2)|   |0 1 0|             |f(1)|
*/ 
vector<vector<int>> mul(const vector<vector<int>>& a, const vector<vector<int>>& b) {
    assert(a.size() > 0 && b.size() > 0 && a[0].size() == b.size());
    int n = a.size(), m = b[0].size();
    vector<vector<int>> c(n, vector<int>(m, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++){
            for(int k = 0; k < b.size(); k++) {
                c[i][j] += (a[i][k] * b[k][j]) % mod;
                if(c[i][j] >= mod) {
                    c[i][j] -= mod; } } } }
    return c; }
vector<vector<int>> power(vector<vector<int>> a, int b) {
    int n = int(a.size());
    vector<vector<int>> res(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        res[i][i] = 1; }
    while(b > 0) {
        if(b & 1) { res = mul(res, a); }
        a = mul(a, a); b >>= 1; }
    return res; }
signed main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        // To calcualate f(n) given f(1), f(2) and f(3)
        // f(i) = f(i-1) + 2 * f(i-2) + 3 * f(i-3)
        if(n <= 3) {
            cout << n << '\n';
            continue; }
        vector<vector<int>> F = {{1,2,3},{1,0,0},{0,1,0}};
        vector<vector<int>> init = {{3}, {2}, {1}};
        cout << mul(power(F, n - 3), init)[0][0]  << '\n'; }
    return 0; }
------------ END -----------
// CHECK_OVERFLOW64 = true can run up to 2 times slower (particularly on CF).
const bool CHECK_OVERFLOW64 = false;
using dist_t = long double;
struct point {
    int64_t x, y, w;
    point() : x(0), y(0) {}
    point(int64_t _x, int64_t _y) : x(_x), y(_y) {}
    point& operator+=(const point &other) { x += other.x; y += other.y; return *this; }
    point& operator-=(const point &other) { x -= other.x; y -= other.y; return *this; }
    point& operator*=(int64_t mult) { x *= mult; y *= mult; return *this; }
    point& operator/=(int64_t div) { assert(x % div == 0 && y % div == 0); x /= div; y /= div; return *this; }
    point operator+(const point &other) const { return point(*this) += other; }
    point operator-(const point &other) const { return point(*this) -= other; }
    point operator*(int64_t mult) const { return point(*this) *= mult; }
    point operator/(int64_t div) const { return point(*this) /= div; }
    bool operator==(const point &other) const { return x == other.x && y == other.y; }
    bool operator!=(const point &other) const { return !(*this == other); }
    point operator-() const { return point(-x, -y); }
    point rotate90() const { return point(-y, x); }
    int64_t norm() const {
        return (int64_t) x * x + (int64_t) y * y; }
    dist_t dist() const {
        return sqrt(dist_t(norm())); }
    bool top_half() const {
        return y > 0 || (y == 0 && x > 0); }
    friend ostream& operator<<(ostream &os, const point &p) {
        return os << '{' << p.x << ", " << p.y << '}'; }
    friend istream& operator>>(istream &is, point &p) {
        return is >> p.x >> p.y; }
    bool operator< (const point &other) const {
        return tie(x, y) < tie(other.x, other.y); }
};
int64_t cross(const point &a, const point &b) {
    return (int64_t) a.x * b.y - (int64_t) b.x * a.y; }
int64_t dot(const point &a, const point &b) {
    return (int64_t) a.x * b.x + (int64_t) a.y * b.y; }
int cross_sign(const point &a, const point &b) {
    if (CHECK_OVERFLOW64) {
        long double double_value = (long double) a.x * b.y - (long double) b.x * a.y;
        if (abs(double_value) > 1e18)
            return double_value > 0 ? +1 : -1; }
    uint64_t uint64_value = (uint64_t) a.x * b.y - (uint64_t) b.x * a.y;
    int64_t actual = int64_t(uint64_value);
    return (actual > 0) - (actual < 0); }
bool left_turn_strict(const point &a, const point &b, const point &c) {
    return cross_sign(b - a, c - a) > 0; }
bool left_turn_lenient(const point &a, const point &b, const point &c) {
    return cross_sign(b - a, c - a) >= 0; }
bool collinear(const point &a, const point &b, const point &c) {
    return cross_sign(b - a, c - a) == 0; }
// Returns twice the signed area formed by three points in a triangle. Positive when a -> b -> c is a left turn.
int64_t area_signed_2x(const point &a, const point &b, const point &c) {
    return cross(b - a, c - a); }
dist_t distance_to_line(const point &p, const point &a, const point &b) {
    assert(a != b);
    return dist_t(abs(area_signed_2x(p, a, b))) / (a - b).dist(); }
int64_t manhattan_dist(const point &a, const point &b) {
    return (int64_t) abs(a.x - b.x) + abs(a.y - b.y); }
int64_t infinity_norm_dist(const point &a, const point &b) {
    return max(abs(a.x - b.x), abs(a.y - b.y)); }
// Sort in increasing order of y, with ties broken in increasing order of x.
bool yx_compare(const point &a, const point &b) {
    return make_pair(a.y, a.x) < make_pair(b.y, b.x); }
// Sort in increasing order of angle to the x-axis.
bool angle_compare(const point &a, const point &b) {
    if (a.top_half() ^ b.top_half())
        return a.top_half();
    return cross_sign(a, b) > 0; }
bool inside_triangle(const point &x, const point &a, const point &b, const point &c) {
    return (left_turn_strict(x, a, b) && left_turn_strict(x, b, c) && left_turn_strict(x, c, a)) ||
           (left_turn_strict(x, b, a) && left_turn_strict(x, c, b) && left_turn_strict(x, a, c)); }
void normalise (int64_t &a, int64_t &b) {
    assert(a != 0 || b != 0);
    if(a < 0 || (a == 0 && b < 0)) a = -a, b = -b;
    int64_t g = __gcd(a, b);
    a /= g, b /= g; }
struct slope {
    int dx, dy;
    slope() {}
    slope (point a, point b = point(0, 0)) {
        dy = a.y - b.y;
        dx = a.x - b.x;
        normalise(dx, dy); }
    slope (int64_t _dx, int64_t _dy) : dx(_dx), dy(_dy) {
        normalise(dx, dy); }
    slope perpendicular () {
        return slope(-dy, dx); }
    bool operator==(const slope &other) const { return dx == other.dx && dy == other.dy; }
    bool operator!=(const slope &other) const { return !(*this == other); }
    bool operator< (const slope &other) const {
        return tie(dx, dy) < tie(other.dx, other.dy); }
    friend istream& operator>>(istream &is, slope &other) {
        return is >> other.dx >> other.dy;
    };
    friend ostream& operator<<(ostream &os, const slope &other) {
        return os << "{" << other.dx << " " << other.dy << "}";
    };
};
struct line {
    /*
    line : y = mx + c 
    y = (dy/dx) x + c
    ydx = xdy + cdx
    make sure gcd(dx, dy) = 1 (or, we normalize it in a sense)
    to uniquely identify a line we need: m and c
    m1 = m2 => dy_1/dx_1 = dy_2/dx_2 
    since slopes are normalized, the required condition becomes : dy_1 = dy_2 and dx_1 = dx_2 (Warning : always keep the denominator(dx) positive)
    to find c: we do c = (ydx - xdy) / dx but since dx must be same for the slope condition,
    we can do cdx = (ydx - xdy) and now the only required condition is (ydx - xdy)_1 = (ydx - xdy)_2
    */
    slope m; int64_t cdx;
    line () {}
    line (point a, int64_t dx, int64_t dy) : m(dx, dy) {
        cdx = a.y * m.dx - a.x * m.dy; }
    line (point a, slope _m) : m(_m) {
        cdx = a.y * m.dx - a.x * m.dy; }
    line (point a, point b) : m(a, b) {
        cdx = a.y * m.dx - a.x * m.dy; }
    bool operator==(const line &other) const { return m == other.m && cdx == other.cdx; }
    bool operator!=(const line &other) const { return !(*this == other); }
    bool operator< (const line &other) const {
        return tie(m, cdx) < tie(other.m, other.cdx); }
    friend istream& operator>>(istream &is, line &other) {
        return is >> other.m >> other.cdx;
    };
    friend ostream& operator<<(ostream &os, const line &other) {
        return os << "{" << other.m << " " << other.cdx << "}";
    };
};
const long double D_INF = 1e100;
------------ END -----------
int intime[N], outtime[N], nodesAtLevel[N], depth[N], nodeAt[2 * N], answer[N];
vector<vector<int>> g(N);
inline int gilbertOrder(int x, int y, int pow, int rotate) {
    if (pow == 0) return 0;
    int hpow = 1 << (pow-1);
    int seg = (x < hpow) ? ((y < hpow) ? 0 : 3) : ((y < hpow) ? 1 : 2);
    seg = (seg + rotate) & 3;
    const int rotateDelta[4] = {3, 0, 0, 1};
    int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
    int nrot = (rotate + rotateDelta[seg]) & 3;
    int subSquareSize = 1LL << (2 * pow - 2);
    int ans = seg * subSquareSize;
    int add = gilbertOrder(nx, ny, pow-1, nrot);
    ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
    return ans; }
struct Query {
    int l, r, idx, d, ord;
    inline void calcOrder() {
        ord = gilbertOrder(l, r, 21, 0); }
}q[N];
inline bool operator<(const Query &a, const Query &b) {
    return a.ord < b.ord; }
int timer = 0;  
void dfs(int u) {
    nodeAt[timer] = u; intime[u] = timer++;
    for(int v: g[u]){
        depth[v] = 1 + depth[u]; dfs(v); }
    nodeAt[timer] = u;
    outtime[u] = timer++; }
void solve() {
    int n, m; cin >> n;
    for(int u = 1; u < n; u++) {
        int p; cin >> p; p--;
        g[p].emplace_back(u); }
    dfs(0); cin >> m;
    for(int i = 0; i < m; i++) {
        int u, d; cin >> u >> d;u--;
        q[i].l = intime[u]; q[i].r = outtime[u];
        q[i].idx = i; q[i].d = d;
        q[i].calcOrder(); }
    sort(q, q + m);
    int curL = q[0].l, curR = q[0].l - 1, distinct = 0;
    auto add = [&](int x) {
        if(cnt[a[x]] == 0) distinct++;
        cnt[a[x]]++;
    };
    auto remove = [&](int x) {
        cnt[a[x]]--;
        if(cnt[a[x]] == 0) distinct--; 
    };
    for(int i = 0; i < m; i++) {
        // make sure that add operation is completed before remove
        int l = q[i].l, r = q[i].r;
        while(curL > l) {
            curL--; add(curL); }
        while(curR < r) { 
            curR++; add(curR); }
        while(curL < l) {
            remove(curL); curL++; }
        while(curR > r) { 
            remove(curR); curR--; }
        answer[q[i].idx] = distinct; }
    for(int i = 0; i < m; i++) {
        cout << answer[i] << '\n'; }
}
------------ END -----------
class SAT2 {
public:
    int n;
    vector<vector<int>> adj, adj_t;
    vector<bool> used, assignment;
    vector<int> order, comp;
    SAT2(int n): n(n) {
        adj.resize(n); adj_t.resize(n);
    };
    void dfs1(int v) {
        used[v] = true;
        for (int u : adj[v]) {
            if (!used[u]) dfs1(u); }
        order.push_back(v); }
    void dfs2(int v, int cl) {
        comp[v] = cl;
        for (int u : adj_t[v]) {
            if (comp[u] == -1) dfs2(u, cl); } }
    bool solve_2SAT() {
        order.clear(); used.assign(n, false);
        for (int i = 0; i < n; ++i) {
            if (!used[i]) dfs1(i); }
        comp.assign(n, -1);
        for (int i = 0, j = 0; i < n; ++i) {
            int v = order[n - i - 1];
            if (comp[v] == -1) dfs2(v, j++); }
        assignment.assign(n / 2, false);
        for (int i = 0; i < n; i += 2) {
            if (comp[i] == comp[i + 1]) return false;
            assignment[i / 2] = comp[i] > comp[i + 1]; }
        return true; }
    // keep `a` and `b` 0-based
    void add_disjunction(int a, bool na, int b, bool nb) {
        // na and nb signify whether a and b are to be negated
        a = 2 * a ^ na; b = 2 * b ^ nb;
        int neg_a = a ^ 1, neg_b = b ^ 1;
        adj[neg_a].pb(b), adj[neg_b].pb(a);
        adj_t[b].pb(neg_a), adj_t[a].pb(neg_b); }
};
------------ END -----------
// TODO: set these consts accordinlgy
const char MIN_CHAR = 'a';
const int ALPHABET = 26;
namespace KMP26 {
    template <typename T>
    void compute_link(const T &s, vector<array<int, ALPHABET>> &link, vector<int> &fail) {
        int n = s.size();
        // fail[i + 1] means the index where pref[index] doesn't match
        // link[i][c] means the index where pref[index] doesn't match if we set s[i]=c
        for (int i = 0; i < n; i++) {
            int c = s[i] - MIN_CHAR;
            // right now link[i][c] stores the answer for proper prefix
            int previous = link[i][c];
            fail[i] = previous;
            // but now we can take whole prefix for the further calculations
            // example: ababac
            // link[3][1] = 2
            // but after processing i=3, we can set link[3][1] = 4
            // so that it updates the correct value to link[5][1]
            link[i][c] = i + 1;
            // `i` matches `previous-1`, so `link[i+1]` should be mapped to `link[previous]`
            link[i + 1] = link[previous]; }
    }
    // Find all indices where `pattern` occurs within `text`
    template<typename T>
    vector<int> find_matches(const T &pattern, const T &text, const vector<array<int, ALPHABET>> &link) {
        if (pattern.size() > text.size())
            return {};
        vector<int> matches;
        int n = pattern.size(), m = text.size();
        int len = 0;
        for (int i = 0; i < m; i++) {
            int c = text[i] - MIN_CHAR;
            len = link[len][c];
            // Check for a match whose last character is at index i
            if (len == n)
                matches.push_back(i - (n - 1)); }
        return matches; }
}

const int lvl = 19;
vector<vector<int>> p(lvl, vector<int>(n, -1)); // to cal
vector<int> depth(n, 0); // to cal
dfs(0, -1);
auto go_up = [&] (int node, int dis) {
    for (int i = lvl - 1; i >= 0; i--)
        if (node >= 0 && (dis >> i & 1)) node = p[i][node];
    return node;
};
auto find_lca = [&] (int u, int v) {
    if (depth[u] > depth[v]) swap(u, v);
    v = go_up(v, depth[v] - depth[u]);
    if (u == v) return u;
    for (int i = lvl - 1; i >= 0; i--) {
        if (p[i][u] != p[i][v]) {u = p[i][u], v = p[i][v]; }}
    return p[0][u];
};