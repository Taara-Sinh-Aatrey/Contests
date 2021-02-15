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

int n;
int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};
char ch[] = {'R', 'D', 'L', 'U'};
char rch[] = {'L', 'U', 'R', 'D'};

bool valid(int i, int j) {
	return (0 <= i && i < n && 0 <= j && j < n);
}

void solve() {
    cin >> n;
    int pu, pl, pd, pr;
    cin >> pu >> pl >> pd >> pr;
    vt<vt<pii>> a(n, vt<pii>(n));
    For(i, n) {
    	For(j, n) {
    		cin >> a[i][j];
    		a[i][j].first--;
    		a[i][j].second--;
    	}
    }
	vt<vt<char>> ans(n, vt<char>(n, '?'));
    for(int r = 0; r < n; r++) {
    	for(int c = 0; c < n; c++) {
    		queue<pii> q;
    		q.emplace(r, c);
    		while(!q.empty()) {
    			auto [x, y] = q.front();
    			q.pop();
    			For(i, 4) {
					int nx = x + dx[i];
					int ny = y + dy[i];
					if(valid(nx, ny) && make_pair(nx, ny) != make_pair(r, c) && ans[nx][ny] == '?' && a[nx][ny] == make_pair(r, c)) {
						ans[nx][ny] = rch[i];
						q.emplace(nx, ny);
    				}
    			}
    		}
    	}
    }
    for(int r = 0; r < n; r++) {
    	for(int c = 0; c < n; c++) {
    		if(a[r][c] != make_pair(r, c) && ans[r][c] == '?') {
    			cout << -1;
    			return;
    		}
    	}
    }
    for(int r = 0; r < n; r++) {
    	for(int c = 0; c < n; c++) {
    		queue<pii> q;
    		q.emplace(r, c);
    		while(!q.empty()) {
    			auto [x, y] = q.front();
    			q.pop();
    			For(i, 4) {
					int nx = x + dx[i];
					int ny = y + dy[i];
					if(valid(nx, ny) && make_pair(nx, ny) != make_pair(r, c) && ans[nx][ny] == '?' && a[nx][ny] == make_pair(r, c)) {
						ans[nx][ny] = rch[i];
						q.emplace(nx, ny);
    				}
    			}
    		}
    	}
    }

    vt<vt<vt<char>>> p(n);

    vt<vt<int>> row(n, vt<int>(n, 0)), col(n, vt<int>(n, 0));
    Rev(i, n) {
        Rev(j, n) {
            if(i + 1 < n) {
                col[i][j] = col[i + 1][j];
            }
            if(j + 1 < n) {
                row[i][j] = row[i][j + 1];
            }
            if(ans[i][j] != '?') {
                row[i][j] = col[i][j] = 0;
            } else {
                row[i][j]++;
                col[i][j]++;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(ans[i][j] != '?')
                continue;
            if(i + 1 < n && row[i][j] % 2 == 1 && ans[i + 1][j] == '?') {
                ans[i][j] = 'D';
                ans[i + 1][j] = 'U';
            } else if(j + 1 < n && ans[i][j + 1] == '?') {
                ans[i][j] = 'R';
                ans[i][j + 1] = 'L';
            } else {
                cout << -1;
                return;
            }
        }
    }

    for(int R = 0; R < n; R++) {
        for(int C = 0; C < n; C++) {
            queue<pii> q;
            vt<vt<int>> cnt(n, vt<int>(n, 0));
            int r = R, c = C;
            cnt[r][c] = 1;
            while(true) {
                if(ans[r][c] == 'U') {
                    r--;
                } else if(ans[r][c] == 'D') {
                    r++;
                } else if(ans[r][c] == 'L') {
                    c--;
                } else {
                    c++;
                }
                cnt[r][c]++;
                if(cnt[r][c] == 2) {
                    break;
                }
            }
            if(make_pair(r, c) != a[r][c]) {
                cout << -1;
                return;
            }
        }
    }

    cout << n * n * pu << '\n';
    for(auto &x: ans) {
        cout << x << '\n';
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
