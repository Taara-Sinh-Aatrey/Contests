/**
 *    author:  Taara Sinh Aatrey
 *    created: 24.02.2021 09:18:49
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


void solve() {
    int n, m;
    cin >> n >> m;
    vt<vt<int>> a(n, vt<int>(m));
    cin >> a;
    auto check = [&]() {
        bool ok = true;
        for(int i = 1; i < n; i++) {
            int diff = 0;
            for(int j = 0; j < m; j++) {
                if(a[i][j] != a[0][j]) {
                    diff++;
                }
            }
            if(diff > 2) {
                ok = false;
                break;
            }
        }
        if(ok) {
            cout << "Yes\n";
            cout << a[0];
            exit(0);
        }
    };
    check();
    for(int i = 1; i < n; i++) {
        int diff = 0;
        vt<int> vec;
        for(int j = 0; j < m; j++) {
            if(a[i][j] != a[0][j]) {
                vec.pb(j);
                diff++;
            }
        }
        if(diff <= 2) continue;
        if(diff > 4) {
            cout << "No";
            return;
        }
        if(diff == 3) {
            for(int it = 0; it < 3; it++) {
                int idx = vec[it];
                int ti = a[0][idx];
                a[0][idx] = a[i][idx];
                bool ok = true;
                for(int ii = 0; ii < n; ii++) {
                    int diif = 0;
                    vt<int> v;
                    for(int jj = 0; jj < m; jj++) {
                        if(a[ii][jj] != a[0][jj]) {
                            v.pb(jj);
                            diif++;
                        }
                    }
                    if(diif <= 2) continue;
                    if(diif >= 4) {
                        ok = false;
                        break;
                    }
                    for(int iit = 0; iit < 3; iit++) {
                        int iidx = vec[iit];
                        int tii = a[0][iidx];
                        a[0][iidx] = a[ii][iidx];
                        check();
                        a[0][iidx] = tii;
                    }
                    ok = false;
                    break;
                }
                if(ok)
                    check();
                a[0][idx] = ti;
            }
            cout << "No";
            return;
        } else {
            for(int it1 = 0; it1 < diff; it1++) {
                for(int it2 = it1 + 1; it2 < diff; it2++) {
                    int idx1 = vec[it1], idx2 = vec[it2];
                    int ti = a[0][idx1];
                    int tj = a[0][idx2];
                    a[0][idx1] = a[i][idx1];
                    a[0][idx2] = a[i][idx2];
                    check();
                    a[0][idx1] = ti;
                    a[0][idx2] = tj;
                }
            }
            cout << "No";
            return;
        }
    }
}

signed main()
{
#ifdef LOCAL
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    solve();
    return 0;
}

