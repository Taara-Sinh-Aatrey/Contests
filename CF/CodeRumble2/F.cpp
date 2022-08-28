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

void solve(int tt) {
    int n, m;
    scan(n, m);
    vector<int> a(n);
    scan(a);
    vector<vector<int>> g(n);
    vector<pair<int, int>> save;
    for(int i = 0; i < m; i++) {
        int u, v;
        scan(u, v);
        save.emplace_back(u, v);
        --u, --v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    if (tt == 76) {
        print(1);
        print(n, m);
        print(a);
        for (auto &p : save) {
            print(p);
        }
    }
    return;
    vector<vector<int>> components;
    {
        vector<bool> vis(n);
        for (int i = 0; i < n; i++) {
            if (vis[i]) continue;
            vector<int> cyc;
            function<void(int)> dfs = [&] (int u) {
                vis[u] = true;
                cyc.emplace_back(u);
                for(auto& v : g[u]) {
                    if(vis[v]) {
                        continue;
                    }
                    dfs(v);
                }
            };
            dfs(i);
            components.emplace_back(cyc);
        }
    }
    int gans = 0;
    Mint gways = 1;
    int left = 0;
    for (auto &component : components) {
        vector<bool> cyc(n);
        for (auto &i : component) {
            vector<bool> vis(n), act(n);
            function<void(int, int)> dfs = [&] (int u, int par) {
                act[u] = true;
                vis[u] = true;
                for(auto& v : g[u]) {
                    if (v == par) {
                        continue;
                    }
                    if(act[v]) {
                        cyc[v] = true;
                        continue;
                    }
                    else if (!vis[v]) {
                        dfs(v, u);
                    }
                }
                act[u] = false;
            };
            dfs(i, -1);
        }
        queue<int> q;
        for (auto &i : component) {
            if (cyc[i]) {
                q.emplace(i);
            }
        }
        vector<int> ccc(n);
        while (!q.empty()) {
            auto u = q.front();
            q.pop();
            vector<bool> vis(n);
            for (auto &v : g[u]) {
                if (!cyc[v])
                    ccc[v]++;
                if (!cyc[v] && ccc[v] == 2) {
                    q.emplace(v);
                    cyc[v] = true;
                }
            }
        }
        Mint ways = 1;
        int nodes = 0;
        int ans = 0;
        // int min_val = inf;
        bool done = false;
        auto fun = [&] (int node) {
            vector<bool> vis(n);
            vector<int> sz(n), cnt(n);
            function<Mint(int)> dfs = [&] (int u) -> Mint {
                vis[u] = true;
                Mint ret = 1;
                for(auto& v : g[u]) {
                    if(cyc[v]) continue;
                    if (!vis[v]) {
                        auto way = dfs(v);
                        sz[u] += sz[v];
                        cnt[u] += cnt[v];
                        ret *= way * C(cnt[u], cnt[v]);
                    }
                }
                if (sz[u] > 0) {
                    cnt[u] += 1;
                    ans += a[u];
                }
                sz[u]++;
                return ret;
            };
            auto way = dfs(node);
            nodes += cnt[node];
            ways *= way * C(nodes, cnt[node]);
            // dbg(i + 1, way);
            // dbg(i + 1, cnt[i], nodes, ways);
            // dbg(cnt);
        };
        int cc_cnt = 0;
        for (auto &i : component) {
            // amin(min_val, a[i]);
            if (cyc[i]) {
                cc_cnt++;
                done = true;
                fun(i);
                // dbg(i + 1, way);
                // dbg(i + 1, cnt[i], nodes, ways);
                // dbg(cnt);
            }
        }
        if (!done) {
            vector<pair<int, Mint>> vv;
            int min_val = inf;
            for (auto &i : component) {
                // if (a[i] == min_val) {
                    ways = 1;
                    nodes = 0;
                    ans = 0;
                    fun(i);
                    // wayss += ways;
                    amin(min_val, ans);
                    vv.emplace_back(ans, ways);
                    // dbg(i, ways);
                // }
            }
            Mint wayss = 0;
            for (auto &[ans, ways] : vv) {
                if (min_val == ans) {
                    wayss += ways;
                }
            }
            gways *= wayss;
            gans += min_val;
            left += 1;
        }
        else {
            left += cc_cnt;
            gans += ans;
            gways *= ways;            
        }
    }
    print(left, gans, gways);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    scan(t);
    for (int tt = 1; tt <= t; tt++) {
        cout << "Case #" << tt << ": ";
        solve(tt);
    }
    return 0;
}