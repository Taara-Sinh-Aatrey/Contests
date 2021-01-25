/**
 *    author:  Taara Sinh Aatrey
 *    created: 14.01.2021 22:35:46
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

class max_segtree {
public:
	int seg[1 << 19];
	vt<int> arr;
	int n;

	max_segtree(int _n, vt<int> _arr) {
		n = _n;
		arr = _arr;
		build(0, n - 1, 0);
	}

	max_segtree() {
	}

	int build(int st, int en , int idx) {
		if (st == en) {
			seg[idx] = arr[st];
			return seg[idx];
		}
		int mid = (st + en) / 2;
		int lhs = build(st, mid, 2 * idx + 1);
		int rhs = build(mid + 1, en, 2 * idx + 2);
		seg[idx] = max(lhs, rhs);
		return seg[idx];
	}

	int get(int query_start, int query_end) {
		return get(query_start, query_end, 0, n - 1, 0);
	}

	int get(int query_start, int query_end, int st, int en, int idx) {
		if (query_start > en || query_end < st) {
			return -INF;
		}
		if (query_start <= st && en <= query_end) {
			return seg[idx];
		}
		int mid = (st + en) / 2;
		int lhs = get(query_start, query_end, st, mid, 2 * idx + 1);
		int rhs = get(query_start, query_end, mid + 1, en, 2 * idx + 2);
		return max(lhs, rhs);
	}
};

void solve() {
	int n, q;
	cin >> n >> q;
	string s;
	cin >> s;
	vt<int> a(n + 1);
	FOR(i, n) {
		a[i] = a[i - 1];
		if (s[i - 1] == '+') {
			a[i]++;
		} else {
			a[i]--;
		}
	}
	vt<int> b(n + 1);
	For(i, n + 1) {
		b[i] = -a[i];
	}
	max_segtree mx(n + 1, a);
	max_segtree mn(n + 1, b);
	while (q--) {
		int l, r;
		cin >> l >> r;
		int mini = -mn.get(0, l - 1);
		int maxi = mx.get(0, l - 1);
		if (r < n) {
			int tmini = -mn.get(r + 1, n) - a[r] + a[l - 1];
			int tmaxi = mx.get(r + 1, n) - a[r] + a[l - 1];
			amin(mini, tmini);
			amax(maxi, tmaxi);
		}
		cout << maxi - mini + 1 << '\n';
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
	cin >> t;
	FOR(tt, t) solve();
	return 0;
}