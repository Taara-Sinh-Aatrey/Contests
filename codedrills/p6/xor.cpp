/**
 *    author:  Taara Sinh Aatrey
 *    created: 13.04.2021 20:44:39
**/

#undef _GLIBCXX_DEBUG
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
#define lsb(x) __builtin_ctz(x)
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


void solve() {
    int n, k;
    cin >> n >> k;
    vt<int> a(n);
    cin >> a;

    vt<vt<int>> b[32];
    int pairs[32];
    b[31].emplace_back(a);

    int dupl = 0;

    for(int i = 30; i >= 0; i--) {
        pairs[i] = 0;
        for(auto& vec : b[i + 1]) {
            vt<int> vec1, vec2;
            if(vec.empty()) {
                continue;
            }
            for(int &x : vec) {
                if(x >> i & 1) {
                    vec1.pb(x);
                } else {
                    vec2.pb(x);
                }
            }
            b[i].pb(vec1);
            b[i].pb(vec2);
            pairs[i] += sz(vec1) * sz(vec2);
            if(i == 0) {
                dupl += sz(vec1) * (sz(vec1) - 1) / 2;
                dupl += sz(vec2) * (sz(vec2) - 1) / 2;
            }
        }
        // dbg(i, b[i], pairs[i]);
    }

    if(k <= dupl) {
        cout << 0 << '\n';
        return;
    }

    k -= dupl;

    for(int i = 0; i <= 30; i++) {
        // dbg(i, pairs[i]);
        if(k > pairs[i]) {
            k -= pairs[i];
            continue;
        }
        vt<int> ans;
        for(int j = 0; j < sz(b[i]); j += 2) {
            for(int& x: b[i][j]) {
                for(int &y: b[i][j + 1]) {
                    ans.emplace_back(x ^ y);
                }
            }
        }

        // dbg(ans);

        sort(all(ans));

        cout << ans[k - 1] << '\n';

        break;
    }
}

signed main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        // cout << "Case #" << tt << ": ";
        solve();
    }
    return 0;
}


