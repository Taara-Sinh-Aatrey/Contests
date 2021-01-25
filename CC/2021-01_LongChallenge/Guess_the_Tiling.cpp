#include <bits/stdc++.h>
using namespace std;

string to_string(const string& s) { return '"' + s + '"'; }

template <typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

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

template <size_t N>
string to_string(bitset<N> v) {
    string res = "";
    for (size_t i = 0; i < N; i++) {
        res += static_cast<char>('0' + v[i]);
    }
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

#define ll long long
#define ar array<ll, 2>
#define pll pair<ll, ll>
#define in insert
#define pb push_back
#define vt vector
#define For(i, n) for (ll i = 0; i < n; i++)
#define Rev(i, n) for (ll i = n - 1; i >= 0; i--)
#define FOR(i, n) for (ll i = 1; i <= n; i++)
#define REV(i, n) for (ll i = n; i >= 1; i--)
#define Rep(i, a, b) for (ll i = a; i <= b; i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

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
ostream& operator<<(ostream& out, pair<T1, T2> a) {
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
        if (f) {
            out << " ";
        }
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
    for (T x : a) {
        if (f) {
            out << " ";
        }
        out << x;
        f = true;
    }
    out << '\n';
    return out;
}
template <class A, size_t S>
istream& operator>>(istream& in, vt<array<A, S>>& a) {
    for (array<A, S>& x : a) in >> x;
    return in;
}
template <class A, size_t S>
ostream& operator<<(ostream& out, vt<array<A, S>>& a) {
    bool f = false;
    for (array<A, S>& x : a) {
        if (f) {
            out << " ";
        }
        out << x;
        f = true;
    }
    out << '\n';
    return out;
}
template <typename T>
void out(T a[], size_t n) {
    For(i, n) {
        if (i > 0) {
            cout << " ";
        }
        cout << a[i];
    }
    cout << '\n';
}
template <typename T>
void in(T a[], size_t n) {
    For(i, n) cin >> a[i];
}
void out(bool ok, bool cap = true) {
    if (cap)
        cout << (ok ? "YES" : "NO") << '\n';
    else
        cout << (ok ? "Yes" : "No") << '\n';
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

const ll mod = 1e9L + 7;
const ll INF = 1e18L + 5;
const ll N = 2e5 + 5;

ll n, q, k;
vt<ll> a;

// class interactor{
// public:
//     vt<vt<int>> b;
//     ll n;
//     interactor(){
//         n = 4;
//         srand(time(NULL));
//         b.resize(n, vt<ll>(n));
//         for(int i = 0; i < n; i++){
//             for(int j = 0; j < n; j++){
//                 b[i][j] = rand() % 2;
//             }
//         }
//     }

//     int get_z(){
//         int sum = 0;
//         for(int i = 0; i < n - 1; i++){
//             for(int j = 0; j < n - 1; j++){
//                 if(b[i][j] == 0 && b[i + 1][j] == 1 && b[i][j + 1] == 1 && b[i + 1][j + 1] == 0){
//                     sum++;
//                 }
//             }
//         }
//         return sum;
//     }
// };


void solve() {
    // interactor II;
    cin >> n >> q >> k;
    vt<vt<ll>> a(n, vt<ll>(n, -1));

    ll Z;
    auto qry = [&](ll x, ll y, bool sp) {
        cout << 1 << " " << x + 1 << " " << y + 1 << endl;
        ll z;
        cin >> z;
        Z = z;
        ll pv = a[x][y];
        if(sp && n % 2 == 1 && x == n - 2 && y -1 >= 0 && a[x - 1][y - 1] == 0 && a[x - 1][y] == 1 && a[x][y - 1] == 1 && pv == 1){
            z--;
            a[x][y] = 1 - pv;
        }
        if(sp && n % 2 == 1 && x == n - 2 && y + 1 < n && a[x + 1][y + 1] == 0 && a[x + 1][y] == 1 && a[x][y + 1] == 1 && pv == 1){
            z--;
            a[x][y] = 1 - pv;
        }
        if(sp && n % 2 == 1 && x == n - 2 && y -1 >= 0 && a[x - 1][y - 1] == 0 && a[x - 1][y] == 1 && a[x][y - 1] == 1 && pv == 0){
            z++;
            a[x][y] = 1 - pv;
        }
        if(sp && n % 2 == 1 && x == n - 2 && y + 1 < n && a[x + 1][y + 1] == 0 && a[x + 1][y] == 1 && a[x][y + 1] == 1 && pv == 0){
            z++;
            a[x][y] = 1 - pv;
        }
        return z;
    };

    auto fun = [&](vt<array<ll, 2>> cell, vt<ll> op, bool sp) {
        for (ll idx : op) {
            ll cur = qry(cell[idx][0], cell[idx][1], sp);
            if (idx == 0 && cur != k) {
                // assert(abs(cur - k) == 1);
                auto x = cell[0];
                if (cur < k) {
                    a[x[0]][x[1]] = 1;
                } else {
                    a[x[0]][x[1]] = 0;
                }
                ll val = 1;
                for (int i = 1; i < sz(cell); i++) {
                    x = cell[i];
                    a[x[0]][x[1]] = val;
                    val = 1 - val;
                }
                k = Z;
                break;
            }
            k = Z;
        }
    };

    int i = 0;
    vt<array<ll, 2>> cell;
    vt<ll> op;
    for (; i + 1 < n; i += 2) {
        cell = {{i, 0}, {i, 1}, {i + 1, 1}, {i + 1, 0}};
        op = {0, 1, 0, 2, 0, 1, 0, 3, 0, 2, 0, 1, 0, 2, 0};
        fun(cell, op, 0);
        for (int j = 2; j < n; j++) {
            assert(a[i + 1][j - 1] == 0);
            k = qry(i + 1, j - 1, 0);
            a[i + 1][j - 1] = 1;
            cell = {{i, j - 1}, {i, j}, {i + 1, j}};
            op = {0, 1, 0, 2, 0, 1, 0};
            fun(cell, op, 0);
        }
    }

    if (i < n) {
        for (ll j = 0; j + 1 < n; j += 2) {
            cell = {{n - 2, j}, {n - 1, j}, {n - 1, j + 1}};
            op = {0, 1, 0, 2, 0, 1, 0};
            fun(cell, op, 1);
        }
        k = qry(n - 2, n - 2, 0);
        k = qry(n - 2, n - 1, 0);
        ll cur = qry(n - 1, n - 2, 0);
        a[n - 2][n - 2] = 0;
        a[n - 2][n - 1] = 1;
        a[n - 1][n - 2] = 1;
        if (cur > k) {
            // assert(cur == k + 1);
            a[n - 1][n - 1] = 0;
        } else {
            a[n - 1][n - 1] = 1;
        }
    }

    cout << 2 << endl;
    For(i, n) {
        For(j, n) { 
            cout << a[i][j] << " "; 
        }
        cout << endl;
    }

    ll verdict;
    cin >> verdict;
    assert(verdict == 1);
}

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t = 1;
    cin >> t;
    FOR(tt, t) solve();
    return 0;
}