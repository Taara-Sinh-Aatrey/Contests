/**
 *    author:  Taara Sinh Aatrey
 *    created: 23.05.2021 17:33:50
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

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int rand(int a, int b) { return uniform_int_distribution<int>(a, b)(rng); }


const int mod = 1e9 + 7;
const int INF = 1e18L + 5;
const int N = 2e5 + 5;

int x;

void solve() {

    srand(time(NULL));

    long double win, draw;
    cin >> win >> draw;

    string s = "RSP";
    // cout << string(30, 'R');
    for(int i = 0; i < 15; i++) {
        for(int j = 0; j < 4; j++) {
            // cout << s[i % 3];
            // cout << "RRSSPP";
            // random_shuffle(s.begin(), s.end());
            // cout << s
            cout << s[i % 3];
        }
    }

    // long double temp = win + draw;

    // win /= temp;
    // draw /= temp;

    // // dbg(win, draw);


    // vector<long double> wt(3, 1.0 / 3);
    // for(int it = 0; it < 60; it++) {
    //     // dbg(wt);
    //     vector<long double> score(3, 0);
    //     long double total_score = 0;
    //     for(int i = 0; i < 3; i++) {
    //         score[(i + 2) % 3] += draw * wt[i] / (it + 1);
    //         total_score += draw * wt[i] / (it + 1);
    //         score[(i + 1) % 3] += win * wt[i] / (it + 1);
    //         total_score += win * wt[i] / (it + 1);
    //     }
    //     // dbg(score);
    //     int choice = max_element(score.begin(), score.end()) - score.begin();
    //     cout << s[choice];
    //     long double r = 1;
    //     for(int i = 0; i < 3; i++) {
    //         wt[i] += (i == choice ? r / 100 : 0) + (100 - r) * score[i] / (100 * total_score);
    //     }
    // }
    cout << '\n';

}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t >> x;

    for (int tt = 1; tt <= t; tt++) {
        cout << "Case #" << tt << ": ";
        solve();
    }
    
    return 0;
}

/*
RS



*/