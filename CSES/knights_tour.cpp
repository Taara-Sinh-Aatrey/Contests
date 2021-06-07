/**
 *    author:  Taara Sinh Aatrey
 *    created: 21.05.2021 16:29:46
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


const int mod = 1e9 + 7;
const int INF = 1e18L + 5;
const int N = 2e5 + 5;

        
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


int dr[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dc[] = {-1, 1, -2, 2, -2, 2, -1, 1};

void solve() {

    int x, y;
    cin >> x >> y;
    x--, y--;
    swap(x, y);
    
    vector<vector<int>> taken(8, vector<int>(8, 0));

    
    auto e = [&](int r, int c) {
        return 0 <= r && r < 8 && 0 <= c && c < 8 && !taken[r][c];
    };

    auto deg = [&](pair<int, int> p) {
        int ret = 0;
        for(int d = 0; d < 8; d++) {
            int nr = p.first + dr[d];
            int nc = p.second + dc[d];
            ret += e(nr, nc);
        }
        return ret;
    };

    function<void(int, int, int)> rec = [&](int r, int c, int moves) {
        taken[r][c] = moves;
        if(moves == 64) {
            for(int i = 0; i < 8; i++) {
                for(int j = 0; j < 8; j++) {
                    cout << taken[i][j] << " \n"[j == 7];
                }
            }
            exit(0);
        }
        vector<pair<int, int>> options;
        for(int d = 0; d < 8; d++) {
            int nr = r + dr[d];
            int nc = c + dc[d];
            if(e(nr, nc)) {
                options.emplace_back(nr, nc);
            }
        }

        sort(options.begin(), options.end(), [&](const pair<int, int>& a, const pair<int, int>& b){
            return deg(a) < deg(b);
        });

        for(auto& [nr, nc]: options) {
            rec(nr, nc, moves + 1);
        }

        taken[r][c] = 0;
    };

    rec(x, y, 1);
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;

    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
    
    return 0;
}