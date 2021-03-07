/**
 *    author:  Taara Sinh Aatrey
 *    created: 02.03.2021 20:32:43
**/

// #undef _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

template <typename A, typename B>
string to_string(pair<A, B> p);

string to_string(const string& s) { return '"' + s + '"'; }

string to_string(const char* s) { return to_string((string) s); }

string to_string(const char& ch) { return "'" + string(1, ch) + "'"; }

string to_string(bool b) { return (b ? "true" : "false"); }

string to_string(vector<bool> v) {
    bool first = true;
    string res = "{";
    for (int i = 0; i < static_cast<int>(v.size()); i++) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(v[i]);
    }
    res += "}";
    return res;
}
template <typename A>
string to_string(A v) {
    bool first = true;
    string res = "{";
    for (const auto& x : v) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}
template <typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
void debug_out() { cout << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cout << " " << to_string(H);
    debug_out(T...);
}
#ifndef ONLINE_JUDGE
#define dbg(...) cout << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define dbg(...) 42
#endif

#define int int64_t
#define ar array<int, 2>
#define pii pair<int, int>
#define pb push_back
#define vt vector
#define For(i, n) for (int i = 0; i < n; i++)
#define Rev(i, n) for (int i = n - 1; i >= 0; i--)
#define FOR(i, n) for (int i = 1; i <= n; i++)
#define REV(i, n) for (int i = n; i >= 1; i--)
#define Rep(i, a, b) for (int i = a; i <= b; i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define msb(x) (int) (31 - __builtin_clz(x))
template <typename T>
using mxpq = priority_queue<T>;
template <typename T>
using mnpq = priority_queue<T, vt<T>, greater<T>>;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int rand(int a, int b) { return uniform_int_distribution<int>(a, b)(rng); }

template <typename T1, typename T2>
istream& operator>>(istream& in, pair<T1, T2>& a) {
    in >> a.first >> a.second;
    return in;
}
template <typename T1, typename T2>
ostream& operator<<(ostream& out, pair<T1, T2>& a) {
    out << a.first << " " << a.second;
    return out;
}
template <class A, size_t S>
istream& operator>>(istream& in, array<A, S>& a) {
    for (A& x : a) in >> x;
    return in;
}
template <class A, size_t S>
ostream& operator<<(ostream& out, array<A, S>& a) {
    bool f = false;
    for (A& x : a) {
        if (f) out << " ";
        out << x;
        f = true;
    }
    return out;
}
template <typename T>
istream& operator>>(istream& in, vt<T>& a) {
    for (T& x : a) in >> x;
    return in;
}
template <typename T>
ostream& operator<<(ostream& out, vt<T>& a) {
    bool f = false;
    for (T& x : a) {
        if (f) out << " ";
        out << x;
        f = true;
    }
    return out;
}
void out(bool ok, bool cap = true) {
    if (cap) cout << (ok ? "YES" : "NO") << '\n';
    else cout << (ok ? "Yes" : "No") << '\n';
}
template <typename T, typename T1>
T amax(T& a, T1 b) {
    if (b > a) a = b;
    return a;
}
template <typename T, typename T1>
T amin(T& a, T1 b) {
    if (b < a) a = b;
    return a;
}

const int mod = 1e9 + 7;
const int INF = 1e18L + 5;
const int N = 2e5 + 5;


void solve(int tt) {
    int n, m;
    cin >> n >> m;
    vt<int> A[2], B[2];
    {
        int x;
        for(int i = 0; i < n; i++) {
            cin >> x;
            if(x > 0) {
                A[0].emplace_back(x);
            } else {
                A[1].emplace_back(-x);
            }
        }
        reverse(all(A[1]));
        for(int i = 0; i < m; i++) {
            cin >> x;
            if(x > 0) {
                B[0].emplace_back(x);
            } else {
                B[1].emplace_back(-x);
            }
        }
        reverse(all(B[1]));
    }
    int ans = 0;
    for(int it = 0; it < 2; it++) {
        auto &a = A[it];
        auto &b = B[it];
        n = sz(a), m = sz(b);
        vt<int> suff(m + 1, 0);
        for(int i = m - 1; i >= 0; i--) {
            suff[i] = suff[i + 1] + binary_search(all(a), b[i]);
        }
        int best = suff[0];
        for(int i = 0; i < m; i++) {
            int elements = upper_bound(all(a), b[i]) - a.begin();
            int low = upper_bound(all(b), b[i] - elements) - b.begin();
            int cur = i - low + 1 + suff[i + 1];
            amax(best, cur);
        }
        ans += best;
    }
    cout << ans << '\n';
}

signed main()
{
#ifdef LOCAL
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    FOR(tt, t) solve(tt);
    return 0;
}

/*

1 6 11 14 19 23

18 19 20 21 22 23 


*/

// #include <algorithm>
// #include <array>
// #include <cassert>
// #include <chrono>
// #include <cmath>
// #include <cstring>
// #include <functional>
// #include <iomanip>
// #include <iostream>
// #include <map>
// #include <numeric>
// #include <queue>
// #include <random>
// #include <set>
// #include <vector>
// using namespace std;

// // http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
// template<class Fun> class y_combinator_result {
//     Fun fun_;
// public:
//     template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
//     template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
// };
// template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }


// template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
// template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

// void dbg_out() { cerr << endl; }
// template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
// #ifdef NEAL_DEBUG
// #define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
// #else
// #define dbg(...)
// #endif

// template<typename T, bool maximum_mode = false>
// struct RMQ {
//     int n = 0;
//     vector<vector<T>> range_min;

//     RMQ(const vector<T> &values = {}) {
//         if (!values.empty())
//             build(values);
//     }

//     static int highest_bit(int x) {
//         return x == 0 ? -1 : 31 - __builtin_clz(x);
//     }

//     static T better(T a, T b) {
//         return maximum_mode ? max(a, b) : min(a, b);
//     }

//     void build(const vector<T> &values) {
//         n = int(values.size());
//         int levels = highest_bit(n) + 1;
//         range_min.resize(levels);

//         for (int k = 0; k < levels; k++)
//             range_min[k].resize(n - (1 << k) + 1);

//         if (n > 0)
//             range_min[0] = values;

//         for (int k = 1; k < levels; k++)
//             for (int i = 0; i <= n - (1 << k); i++)
//                 range_min[k][i] = better(range_min[k - 1][i], range_min[k - 1][i + (1 << (k - 1))]);
//     }

//     T query_value(int a, int b) const {
//         assert(0 <= a && a < b && b <= n);
//         int level = highest_bit(b - a);
//         return better(range_min[level][a], range_min[level][b - (1 << level)]);
//     }
// };


// const int INF = int(1e9) + 5;

// int solve(vector<int> A, vector<int> B) {
//     assert(is_sorted(A.begin(), A.end()));
//     assert(is_sorted(B.begin(), B.end()));
//     int N = int(A.size());
//     int M = int(B.size());
//     vector<int> suffix_match(N + 1, 0);

//     for (int i = N - 1; i >= 0; i--)
//         suffix_match[i] = suffix_match[i + 1] + binary_search(B.begin(), B.end(), A[i]);

//     vector<int> consecutive(M, 0);

//     for (int i = 0; i < M; i++)
//         consecutive[i] = 1 + (i > 0 && B[i] == B[i - 1] + 1 ? consecutive[i - 1] : 0);

//     RMQ<int, true> rmq(consecutive);
//     int best = 0;

//     for (int prefix = 0; prefix <= N; prefix++) {
//         int prefix_match = 0;

//         if (prefix > 0) {
//             int start = int(lower_bound(B.begin(), B.end(), A[prefix - 1]) - B.begin());
//             int end = int(lower_bound(B.begin(), B.end(), prefix < N ? A[prefix] : INF) - B.begin());

//             for (int i = start; i < end; i++) {
//                 int cutoff = int(upper_bound(B.begin(), B.end(), B[i] - prefix) - B.begin());
//                 prefix_match = max(prefix_match, i - cutoff + 1);
//             }
//         }

//         best = max(best, prefix_match + suffix_match[prefix]);
//     }

//     return best;
// }

// void run_case() {
//     int N, M;
//     cin >> N >> M;
//     vector<int> A_neg, B_neg;
//     vector<int> A_pos, B_pos;

//     for (int i = 0; i < N; i++) {
//         int a;
//         cin >> a;

//         if (a < 0)
//             A_neg.push_back(-a);
//         else
//             A_pos.push_back(a);
//     }

//     for (int i = 0; i < M; i++) {
//         int b;
//         cin >> b;

//         if (b < 0)
//             B_neg.push_back(-b);
//         else
//             B_pos.push_back(b);
//     }

//     reverse(A_neg.begin(), A_neg.end());
//     reverse(B_neg.begin(), B_neg.end());
//     cout << solve(A_pos, B_pos) << " " << solve(A_neg, B_neg) << '\n';
// }

// int main() {
//     ios::sync_with_stdio(false);
// #ifndef NEAL_DEBUG
//     cin.tie(nullptr);
// #endif

//     int tests;
//     cin >> tests;

//     while (tests-- > 0)
//         run_case();
// }
