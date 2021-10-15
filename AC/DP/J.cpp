/**
 *    author:  Taara Sinh Aatrey
 *    created: 27.02.2021 15:36:07
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
const int N = 300 + 5;

double p[N][N][N], ev[N][N][N];

void solve() {
    int n;
    cin >> n;
    vt<int> a(3, 0);
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        x--;
        a[x]++;
    }

    p[a[0]][a[1]][a[2]] = 1.0;

    for(int three = n; three >= 0; three--) {
        for(int two = n; two >= 0; two--) {
            for(int one = n; one >= 0; one--) {
                if(one + two + three == 0 || one + two + three > n) {
                    continue;
                }
                // I reached this state 
                // But since I need to move to a new valid state, I will select some plate
                // But in doing so, I will keep on wasting operations as some of the plates
                // have no sushi left
                double p_waste = (double) (n - (one + two + three)) / n;
                // ev_waste = p_waste + p_waste^2 + p_waste^3 +................
                // ev_waste = p_waste / (1 - p_waste)
                double ev_waste = (double) p_waste / (1 - p_waste);
                // Finally we need to perform 1 operation to move to a new state
                ev_waste += 1; // (Although this one operation is not wasted)
                ev[one][two][three] += ev_waste * p[one][two][three];

                int plates = one + two + three;

                if(one) {
                    double p_go = (double) one / plates;
                    p[one - 1][two][three] += p[one][two][three] * p_go; 
                    ev[one - 1][two][three] += ev[one][two][three] * p_go; 
                }
                if(two) {
                    double p_go = (double) two / plates;
                    p[one + 1][two - 1][three] +=  p[one][two][three] * p_go;
                    ev[one + 1][two - 1][three] +=  ev[one][two][three] * p_go;
                }
                if(three) {
                    double p_go = (double) three / plates;
                    p[one][two + 1][three - 1] +=  p[one][two][three] * p_go; 
                    ev[one][two + 1][three - 1] +=  ev[one][two][three] * p_go; 
                }
            }
        }
    }
    cout << fixed << setprecision(10) << ev[0][0][0];
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

