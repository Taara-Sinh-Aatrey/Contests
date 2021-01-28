/**
 *    author:  Taara Sinh Aatrey
 *    created: 27.01.2021 17:23:52
**/
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
    out << '\n';
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

// x | (x + 1) sets lowest unset bit of x
// x & (x - 1) unsets lowest set bit of x

struct P {
	pii dx = {0, 1}, dy = {0, 1};
	bool rev = 0;
	void operator+= (const pii& x) {
		dx.first += x.first;
		dy.first += x.second;
	}
	void mulx (const int& x) {
		dx.first *= x;
		dx.second *= x;
	}
	void muly (const int& y) {
		dy.first *= y;
		dy.second *= y;
	}
	void mul (const int & x) {
		mulx(x);
		muly(x);
	}
	void muli (const int & x) {
		mulx(x);
		muly(x);
		swap();
	}
	void swap() {
		pii temp = dx;
		dx = make_pair(-dy.first, -dy.second);
		dy = temp;
		rev = 1 - rev;
	}
};

string to_string(P a) {
	return to_string(make_pair(a.dx, a.dy));
}

/*

1->   -i
2->    i
3->    *2p - x
4->    *2p - y

*/

void solve() {
    int n;
    cin >> n;
    vt<pii> a(n);
    cin >> a;
    int m;
    cin >> m;
    vt<P> change(m + 1);
    for(int i = 1; i <= m; i++) {
    	change[i] = change[i - 1];
    	int p;
    	cin >> p;
    	if(p == 1) {
    		change[i].muli(-1);
    	} else if(p == 2) {
    		change[i].muli(1);
    	} else if(p == 3) {
    		cin >> p;
    		change[i].mulx(-1);
    		change[i] += make_pair(2 * p, 0);
    	} else {
    		cin >> p;
    		change[i].muly(-1);
    		change[i] += make_pair(0, 2 * p);
    	}
    }
    int q;
    cin >> q;
    while(q--) {
    	int op, idx;
    	cin >> op >> idx;
    	idx--;
    	P ret;
    	ret += a[idx];
    	if(change[op].rev) {
    		swap(ret.dx, ret.dy);
    	}
    	ret.mulx(change[op].dx.second);
    	ret.muly(change[op].dy.second);
    	ret += make_pair(change[op].dx.first, change[op].dy.first);
    	cout << ret.dx.first << " " << ret.dy.first << '\n';
    }
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
