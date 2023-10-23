/**
 *    author:  Taara Sinh Aatrey
 *    created: 24.09.2022 22:32:11
**/

#include "bits/stdc++.h"
using namespace std;


#ifdef AATREY_DEBUG
#include "debug.hpp"
#else
#define dbg(...)
#endif

// #define int int64_t


template<typename T>
int coordinate_compress(vector<T>& a) {
    set<T> s(a.begin(), a.end());
    map<T, int> mp;
    int cnt = 0;
    for(auto &x : s) mp[x] = cnt++;
    for(auto &x : a) x = mp[x];
    return cnt;
}

const int N = 3.3e7 + 5;

vector<int> spf(N, 0);
vector<bool> prime(N, true);
vector<int> primes;
void sieve() {
    prime[0] = prime[1] = false;
    for(int i = 2; i < N; i++) {
        if(prime[i]) {
            spf[i] = i;
            primes.push_back(i);
        }
        int64_t prod;
        for(int j = 0; j < (int) primes.size() && primes[j] <= spf[i] && (prod = primes[j] * int64_t(i)) < N; j++) {
            spf[prod] = primes[j];
            prime[prod] = false;
        }
    }
}

int inverse(int a, int m) {
    if(a == 0) return 0;
    int MOD = m;
    int u = 0, v = 1;
    while (a != 0) {
        int t = m / a;
        m -= t * a; swap(a, m);
        u -= t * v; swap(u, v);
    }
    assert(m == 1);
    u %= MOD;
    if(u < 0) u += MOD;
    return u;
}

template <typename T>
T inverse(T a, T m) {
    T u = 0, v = 1;
    while (a != 0) {
        T t = m / a;
        m -= t * a; swap(a, m);
        u -= t * v; swap(u, v);
    }
    assert(m == 1);
    return u;
}

template <typename T>
class Modular {
public:
    using Type = typename decay<decltype(T::value)>::type;

    constexpr Modular() : value() {}
    template <typename U>
    Modular(const U& x) {
        value = normalize(x);
    }

    template <typename U>
    static Type normalize(const U& x) {
        Type v;
        if (-mod() <= x && x < mod()) v = static_cast<Type>(x);
        else v = static_cast<Type>(x % mod());
        if (v < 0) v += mod();
        return v;
    }

    const Type& operator()() const { return value; }
    template <typename U>
    explicit operator U() const { return static_cast<U>(value); }
    constexpr static Type mod() { return T::value; }

    Modular& operator+=(const Modular& other) { if ((value += other.value) >= mod()) value -= mod(); return *this; }
    Modular& operator-=(const Modular& other) { if ((value -= other.value) < 0) value += mod(); return *this; }
    template <typename U> Modular& operator+=(const U& other) { return *this += Modular(other); }
    template <typename U> Modular& operator-=(const U& other) { return *this -= Modular(other); }
    Modular& operator++() { return *this += 1; }
    Modular& operator--() { return *this -= 1; }
    Modular operator++(int32_t) { Modular result(*this); *this += 1; return result; }
    Modular operator--(int32_t) { Modular result(*this); *this -= 1; return result; }
    Modular operator-() const { return Modular(-value); }

    template <typename U = T>
    typename enable_if<is_same<typename Modular<U>::Type, int32_t>::value, Modular>::type & operator*=(const Modular& rhs) {
#ifdef _WIN32
        uint64_t x = static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value);
        uint32_t xh = static_cast<uint32_t>(x >> 32), xl = static_cast<uint32_t>(x), d, m;
        asm(
            "divl %4; \n\t"
            : "=a" (d), "=d" (m)
            : "d" (xh), "a" (xl), "r" (mod())
        );
        value = m;
#else
        value = normalize(static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value));
#endif
        return *this;
    }
    template <typename U = T>
    typename enable_if<is_same<typename Modular<U>::Type, int64_t>::value, Modular>::type & operator*=(const Modular& rhs) {
        int64_t q = static_cast<int64_t>(static_cast<long double>(value) * rhs.value / mod());
        value = normalize(value * rhs.value - q * mod());
        return *this;
    }
    template <typename U = T>
    typename enable_if < !is_integral<typename Modular<U>::Type>::value, Modular >::type & operator*=(const Modular& rhs) {
        value = normalize(value * rhs.value);
        return *this;
    }

    Modular& operator/=(const Modular& other) { return *this *= Modular(inverse(other.value, mod())); }

    template <typename U>
    friend const Modular<U>& abs(const Modular<U>& v) { return v; }

    template <typename U>
    friend bool operator==(const Modular<U>& lhs, const Modular<U>& rhs);

    template <typename U>
    friend bool operator<(const Modular<U>& lhs, const Modular<U>& rhs);

    template <typename U>
    friend std::istream& operator>>(std::istream& stream, Modular<U>& number);

private:
    Type value;
};

template <typename T> bool operator==(const Modular<T>& lhs, const Modular<T>& rhs) { return lhs.value == rhs.value; }
template <typename T, typename U> bool operator==(const Modular<T>& lhs, U rhs) { return lhs == Modular<T>(rhs); }
template <typename T, typename U> bool operator==(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) == rhs; }

template <typename T> bool operator!=(const Modular<T>& lhs, const Modular<T>& rhs) { return !(lhs == rhs); }
template <typename T, typename U> bool operator!=(const Modular<T>& lhs, U rhs) { return !(lhs == rhs); }
template <typename T, typename U> bool operator!=(U lhs, const Modular<T>& rhs) { return !(lhs == rhs); }

template <typename T> bool operator<(const Modular<T>& lhs, const Modular<T>& rhs) { return lhs.value < rhs.value; }

template <typename T> Modular<T> operator+(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) += rhs; }
template <typename T, typename U> Modular<T> operator+(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) += rhs; }
template <typename T, typename U> Modular<T> operator+(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) += rhs; }

template <typename T> Modular<T> operator-(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) -= rhs; }
template <typename T, typename U> Modular<T> operator-(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) -= rhs; }
template <typename T, typename U> Modular<T> operator-(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) -= rhs; }

template <typename T> Modular<T> operator*(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T, typename U> Modular<T> operator*(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T, typename U> Modular<T> operator*(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) *= rhs; }

template <typename T> Modular<T> operator/(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) /= rhs; }
template <typename T, typename U> Modular<T> operator/(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) /= rhs; }
template <typename T, typename U> Modular<T> operator/(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) /= rhs; }

template<typename T, typename U>
Modular<T> power(const Modular<T>& a, const U& b) {
    assert(b >= 0);
    Modular<T> x = a, res = 1;
    U p = b;
    while (p > 0) {
        if (p & 1) res *= x;
        x *= x;
        p >>= 1;
    }
    return res;
}

template <typename T>
bool IsZero(const Modular<T>& number) {
    return number() == 0;
}

template <typename T>
string to_string(const Modular<T>& number) {
    return to_string(number());
}

template <typename T>
std::ostream& operator<<(std::ostream& stream, const Modular<T>& number) {
    return stream << number();
}

template <typename T>
std::istream& operator>>(std::istream& stream, Modular<T>& number) {
    typename common_type<typename Modular<T>::Type, int64_t>::type x;
    stream >> x;
    number.value = Modular<T>::normalize(x);
    return stream;
}

/*
using ModType = int32_t;

struct VarMod { static ModType value; };
ModType VarMod::value;
ModType& md = VarMod::value;
using Mint = Modular<VarMod>;
*/

constexpr int32_t md = 1e9 + 7;
using Mint = Modular<std::integral_constant<decay<decltype(md)>::type, md>>;

void dbg_print(const Mint &x) { cerr << x(); }

vector<Mint> fact(1, 1);
vector<Mint> inv_fact(1, 1);

Mint C(int n, int k) {
    if (k < 0 || k > n) {
        return 0;
    }
    while ((int) fact.size() < n + 1) {
        fact.push_back(fact.back() * (int) fact.size());
        inv_fact.push_back(1 / fact.back());
    }
    return fact[n] * inv_fact[k] * inv_fact[n - k];
}

map<int, int> id;

class SEGTREE_HASH {
public:

    struct node {
        Mint sum = 0;
        void apply(int l, int r, int v) {
            sum = v * primes[v];
        }
    };

    node unite(const node &a, const node &b) const {
        node res;
        res.sum = a.sum + b.sum;
        return res;
    }

    inline void pull (int x, int z) { tree[x] = unite(tree[x + 1], tree[z]); }
    
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
        if (ll <= y) 
            modify(x + 1, l, y, ll, rr, v...);
        if (rr > y) 
            modify(z, y + 1, r, ll, rr, v...);
        pull(x, z);
    }
    
    SEGTREE_HASH(int _n) : n(_n) {
        tree.resize(2 * n - 1);
        build(0, 0, n - 1);
    }
    
    template <typename M>
    SEGTREE_HASH(const vector<M> &v) {
        n = v.size();
        tree.resize(2 * n - 1);
        build(0, 0, n - 1, v);
    }
    
    node get(int ll, int rr) {
        assert(0 <= ll && ll <= rr && rr <= n - 1);
        return get(0, 0, n - 1, ll, rr);
    }
    
    template <typename... M>
    void modify(int ll, int rr, const M&... v) {
        assert(0 <= ll && ll <= rr && rr <= n - 1);
        modify(0, 0, n - 1, ll, rr, v...);
    }
};

class SEGTREE_XOR {
public:

    struct node {
        int Xor = 0;
        void apply(int l, int r, int v) {
            Xor = v;
        }
    };

    node unite(const node &a, const node &b) const {
        node res;
        res.Xor = a.Xor ^ b.Xor;
        return res;
    }

    inline void pull (int x, int z) { tree[x] = unite(tree[x + 1], tree[z]); }
    
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
        if (ll <= y) 
            modify(x + 1, l, y, ll, rr, v...);
        if (rr > y) 
            modify(z, y + 1, r, ll, rr, v...);
        pull(x, z);
    }
    
    SEGTREE_XOR(int _n) : n(_n) {
        tree.resize(2 * n - 1);
        build(0, 0, n - 1);
    }
    
    template <typename M>
    SEGTREE_XOR(const vector<M> &v) {
        n = v.size();
        tree.resize(2 * n - 1);
        build(0, 0, n - 1, v);
    }
    
    node get(int ll, int rr) {
        assert(0 <= ll && ll <= rr && rr <= n - 1);
        return get(0, 0, n - 1, ll, rr);
    }
    
    template <typename... M>
    void modify(int ll, int rr, const M&... v) {
        assert(0 <= ll && ll <= rr && rr <= n - 1);
        modify(0, 0, n - 1, ll, rr, v...);
    }
};

signed main() {
#define int int64_t
    ios::sync_with_stdio(0);
    cin.tie(0);
    sieve();
    spf = {};
    prime = {};
    const int mod = 1e9 + 7;
    int testcases;
    cin >> testcases;
    for (int caseno = 1; caseno <= testcases; caseno++) {
        cout << "Case #" << caseno << ": ";
        id = {};
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &x : a) {
            cin >> x;
        }
        a.insert(a.begin(), 0);
        vector<int> orig = a;
        int M = coordinate_compress(a);
        for (int i = 0; i < n; i++) {
            id[orig[i]] = a[i];
        }
        vector<Mint> h(n + 1, 0);
        SEGTREE_XOR XOR(a);
        SEGTREE_HASH HASH(a);
        const int Q_MAX = 1e6;
        auto fun = [&] (int l, int r) {
            int m = (l + r) / 2;
            int e = XOR.get(l, r).Xor;
            if (e >= id.size())
                return 0;
                // l, m - 1
            Mint left = HASH.get(l, m - 1).sum;
            // m, r
            Mint right = HASH.get(m, r).sum;
            right -= e * primes[e];
            if (left == right)
                return 1;
            left = HASH.get(l, m).sum;
            left -= e * primes[e];
            // m + 1, r
            right = HASH.get(m + 1, r).sum;
            if (left == right)
                return 1;
            return 0;
        };
        int q;
        cin >> q;
        int ans = 0;
        int qq = 0;
        while (q--) {
            int t;
            cin >> t;
            if (t == 1) {
                int x, y;
                cin >> x >> y;
                if (!id.count(y)) {
                    id[y] = id.size();
                }
                y = id[y];
                a[x] = y;
                HASH.modify(x, x, y);
                XOR.modify(x, x, y);
            }
            else {
                qq++;
                int l, r;
                cin >> l >> r;
                if (l % 2 != r % 2) {
                    continue;
                }
                if (l == r) {
                    ans++;
                    continue;
                } 
                int cur = fun(l, r);
                ans += cur;
            }
        }
        cout << ans << '\n';
    }
    return 0;
#undef int
}