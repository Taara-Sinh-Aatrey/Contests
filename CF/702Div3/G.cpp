/**
 *    author:  Taara Sinh Aatrey
 *    created: 16.02.2021 21:07:22
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
    int n, m;
    cin >> n >> m;
    vt<int> a(n);
    cin >> a;
    vt<pii> pref;
    int cur = 0;
    For(i, n) {
        cur += a[i];
        if(cur <= 0) {
            continue;
        }
        if(pref.empty() || cur > pref.back().first) {
            pref.pb({cur, i + 1});
        }
    }
    int sum = cur;
    while(m--) {
        int x;
        cin >> x;
        int ans = 0;
        if(pref.empty()) {
            ans = -1;
        } else if(x <= pref.back().first) {
                pii s = {x, -INF};
                auto it = lower_bound(pref.begin(), pref.end(), s);
                ans = it->second - 1;
        } else if(sum <= 0) {
            ans = -1;
        } else {
            if(pref.back().second == n) {
                int q = x / pref.back().first;
                ans = q * n - 1;
                x = x % pref.back().first;
            } else {
                int q = (x - pref.back().first + sum - 1) / sum;
                ans = q * n - 1;
                x = x - q * sum;
            }
            pii s = {x, -INF};
            assert(x >= 0);
            if(x != 0) {
                auto it = lower_bound(all(pref), s);
                ans += it->second;
            }
        }
        cout << ans << " ";
    }
    cout << '\n';
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
    FOR(tt, t) solve();
    return 0;
}
/*
    Things to keep in mind :-
    x | (x + 1) sets lowest unset bit of x
    x & (x - 1) unsets lowest set bit of x
*/

