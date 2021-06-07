/**
 *    author:  Taara Sinh Aatrey
 *    created: 15.05.2021 09:41:31
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
    int n, q;
    cin >> n >> q;
    vt<int> a(n);
    cin >> a;
    vt<int> pos(n + 1);
    for(int i = 0; i < n; i++) {
        pos[a[i]] = i;
    }

    set<pii> pairs;

    pairs.emplace(a[0], a[0]);
    for(int i = 1; i < n; i++) {
        pii search = {a[i], 0};
        auto it = pairs.lower_bound(search);
        if(it != pairs.begin()) {
            it--;
            auto [low, high] = *it;
            if(high == a[i] - 1) {
                high = a[i];
                pairs.erase(it);
                pairs.emplace(low, high);
            } else {
                pairs.emplace(a[i], a[i]);
            }
        } else {
            pairs.emplace(a[i], a[i]);
        }
    }

    auto get_it = [&](int val) {
        pii search = {val + 1, 0};
        auto it = pairs.lower_bound(search);
        if(it != pairs.begin()) {
            it--;
        }
        return it;
    };

    while(q--) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        if(x > y) {
            swap(x, y);
        }

        if(x != y) {

            auto it1 = get_it(a[x]);
            auto it2 = get_it(a[y]);

            vt<pii> vec;
            if(it1 == it2) {
                // 10  50  70  100
                // 10  70  50  100
                // 10   50
                // 51   69
                // 70 100
                auto [l, h] = *it1;
                pairs.erase(it1);
                vec.emplace_back(l, a[x]);
                if(a[x] + 1 <= a[y] - 1) {
                    vec.emplace_back(a[x] + 1, a[y] - 1);
                }
                vec.emplace_back(a[y], h);
                swap(a[x], a[y]);
                swap(pos[a[x]], pos[a[y]]);
            } else {
                auto [l1, h1] = *it1;
                auto [l2, h2] = *it2;

                // 10 15 20       30  35 40

                pairs.erase(it1);
                if(a[x] != h1 && pos[a[x] + 1] < y) {
                    vec.emplace_back(l1, a[x]);
                    vec.emplace_back(a[x] + 1, h1);
                } else {
                    vec.emplace_back(l1, h1);
                }

                pairs.erase(it2);
                if(a[y] != l2 && pos[a[y] - 1] > x) {
                    vec.emplace_back(l2, a[y] - 1);
                    vec.emplace_back(a[y], h2);
                } else {
                    vec.emplace_back(l2, h2);
                }

                swap(a[x], a[y]);
                swap(pos[a[x]], pos[a[y]]);
                
            }

            sort(all(vec));

            if(!vec.empty()) {


                vt<pii> temp;

                auto merge_forward = [&]() {
                    if(temp.back().second != n) {
                        auto it = get_it(temp.back().second + 1);
                        if(it == pairs.end()) {
                            return;
                        }
                        auto [l, h] = *it;
                        if(pos[temp.back().second] < pos[l] && temp.back().second + 1 == l) {
                            temp.back().second = h;
                            pairs.erase(it);
                        }
                    }
                };

                auto merge_backward = [&]() {
                    if(temp.back().first != 1) {
                        auto it = get_it(temp.back().first - 1);
                        if(it == pairs.end()) {
                            return;
                        }
                        auto [l, h] = *it;
                        if(pos[h] < pos[temp.back().first] && h + 1 == temp.back().first) {
                            temp.back().first = l;
                            pairs.erase(it);
                        }
                    }
                };
                for(auto [l, h] : vec) {
                    if(!temp.empty()) {
                        merge_backward();
                        merge_forward();
                    }
                    if(temp.empty() || pos[temp.back().second] > pos[l] || temp.back().second + 1 != l) {
                        temp.emplace_back(l, h);
                    } else {
                        temp.back().second = h;
                    }
                }

                merge_backward();
                merge_forward();

                for(auto [l, h] : temp) {
                    pairs.emplace(l, h);
                }
            }
        }
        cout << sz(pairs) << '\n';
    }

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

/*

15 2 3 7 8 9 1 19 4 14 5 20 13 16 10 11 6 12 18 17

1
2 3 4 5 6
7 8 9 10 11 12
13
14
15 16 17
18
19 20


*/