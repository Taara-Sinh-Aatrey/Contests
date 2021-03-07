/**
 *    author:  Taara Sinh Aatrey
 *    created: 01.03.2021 18:19:20
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

const long double eps = 1e-9;

#define pdd pair<long double, long double>


void solve() {
    int n;
    cin >> n;
    const long double pi = acos(-1);
    // dbg(pi);
    vt<array<int, 4>> a(n);
    for(auto &p: a) {
        cin >> p[0] >> p[1];
        int an, r;
        cin >> an >> r;
        int p2 = an - r, p3 = an + r;
        p2 = (p2 + 360) % 360;
        p3 = (p3 + 360) % 360;
        if(p2 > p3) {
            swap(p2, p3);
        }
        p[2] = p2, p[3] = p3;
    }

    vt<vt<int>> g(n);
    vt<int> indeg(n, 0);

    queue<int> q;

    for(int i = 0; i < n; i++) {
        auto& [x, y, l, r] = a[i];
        for(int j = 0; j < n; j++) {
            if(i == j) {
                continue;
            }
            int dx = a[j][0] - x, dy = a[j][1] - y;
            long double ang = atan2(dy, dx);
            if(ang < 0) {
                ang += pi;
            }
            ang *= 180 / pi;
            if(dy < 0) {
                ang += 180;
            }
            if(r - l < 180 && ang + eps > l && ang - eps < r) {
                g[i].pb(j);
                indeg[j]++;
            } else if(r - l > 180 && (ang + eps > r || ang - eps < l)) {
                g[i].pb(j);
                indeg[j]++;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        if(indeg[i] == 0) {
            q.emplace(i);
        }
    }

    vt<int> print;

    while(!q.empty()) {
        int u = q.front();
        q.pop();
        print.pb(u + 1);
        for(int v: g[u]) {
            indeg[v]--;
            if(indeg[v] == 0) {
                q.emplace(v);
            }
        }
    }
    if(sz(print) < n) {
        cout << -1 << '\n';
        return;
    }
    cout << print;
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
    // cin >> t;
    FOR(tt, t) solve();
    return 0;
}


/*

0 ->
1 -> 3
2 -> 0
3 -> 2


*/
