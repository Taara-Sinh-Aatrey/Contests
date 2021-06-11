/**
 *    author:  Taara Sinh Aatrey
 *    created: 23.05.2021 22:03:59
**/

#include <bits/stdc++.h>
using namespace std;

#define int int64_t

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
istream& operator>>(istream& in, vector<T>& a) {
    for (T& x : a) in >> x;
    return in;
}
template <typename T>
ostream& operator<<(ostream& out, vector<T>& a) {
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
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}
#ifndef ONLINE_JUDGE
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define dbg(...) 42
#endif


const int mod = 1e9 + 7;
const int INF = 1e18L + 5;
const int N = 2e5 + 5;

void solve() {

    int n;
    cin >> n;

    vector<int> a(n), p(n);
    cin >> a >> p;
    for(auto& x: p) {
        x--;
    }

    vector<pair<int, int>> id(n, {-1, -1});
    vector<vector<int>> vec; 
    for(int i = 0; i < n; i++) {
        if(id[i].first == -1) {
            int x = i;
            vector<int> temp;
            int sz = int(vec.size()), cur = 0;
            do {
                temp.emplace_back(x);
                id[x] = {sz, cur};
                x = p[x];
                cur++;
            } while(x != i);
            vec.emplace_back(temp);
        }
    }

    int q;
    cin >> q;
    int rot = 0;
    while(q--) {
        int t;
        cin >> t;
        if(t == 1) {
            rot++;
        }
        else if(t == 2) {
            int x, y;
            cin >> x >> y;
            x--, y--;
            auto [x1, x2] = id[x];
            auto [y1, y2] = id[y];
            int sx = int(vec[x1].size());
            int sy = int(vec[y1].size());
            x2 -= rot;
            x2 = (x2 % sx + sx) % sx;
            y2 -= rot;
            y2 = (y2 % sy + sy) % sy; 
            x = vec[x1][x2];
            y = vec[y1][y2];
            swap(a[x], a[y]);
        }
        else {
            int x;
            cin >> x;
            x--;
            auto [x1, x2] = id[x];
            int sx = int(vec[x1].size());
            x2 -= rot;
            x2 = (x2 % sx + sx) % sx;
            cout << a[vec[x1][x2]] << '\n';
        }
    }

}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
    
    return 0;
}