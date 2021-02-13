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

const int mod = 998244353;
const int INF = 1e18L + 5;
const int N = 2e5 + 5;

int fac[N], inv[N];

int Pow(int a, int b){
    int res = 1;
    while(b > 0) {
        if(b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int NCR(int n, int r) {
	if(r > n) {
		return 0;
	}
	return fac[n] * inv[r] % mod * inv[n - r] % mod;
}

// Code of fft taken from https://cp-algorithms.com/algebra/fft.html
// And modified as per my use 

void fft(vector<int> & a, bool invert) {
    int n = a.size();
    // assert((n & (n - 1)) == 0);
    // in other words n is power of 2
    // We write mod = c. 2^k + 1
    // So this fft function works only if input size <= 2 ^ k
    // for mod = 998244353, k = 23, so input size can be as large as 8e6
    // assert((mod - 1) % n == 0);
    // root is nth root of unity under primitive field of mod
    // root = g ^ (mod - 1) / n, for mod = 998244353, g = 3 works well
    int root = Pow(3, (mod - 1) / n);
    int inv = Pow(root, mod - 2);
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j)
            swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        int wlen = invert ? inv : root;
        for (int i = len; i < n; i <<= 1)
            wlen = wlen * wlen % mod;

        for (int i = 0; i < n; i += len) {
            int w = 1;
            for (int j = 0; j < len / 2; j++) {
                int u = a[i+j], v = a[i+j+len/2] * w % mod;
                a[i+j] = u + v < mod ? u + v : u + v - mod;
                a[i+j+len/2] = u - v >= 0 ? u - v : u - v + mod;
                w = w * wlen % mod;
            }
        }
    }

    if (invert) {
        int n_1 = Pow(n, mod - 2);
        for (int & x : a) {
            x = x * n_1 % mod;
        }
    }
}

void multiply(vector<int> const& a, vector<int> const& b, vector<int> &c) {
    // c = a * b
    vector<int> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < (int) a.size() + (int) b.size()) 
        n <<= 1;
    fa.resize(n);
    fb.resize(n);
    c.resize(n);

    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++)
        c[i] = fa[i] * fb[i] % mod;
    fft(c, true);
}
    
void solve() {
	int n;
	cin >> n;
	vt<int> cnt(30, 0);
	vt<int> ans(n + 1, 0);

	fac[0] = 1; inv[0] = 1;

	for(int i = 1; i <= n; i++) {

		fac[i] = (i * fac[i - 1]) % mod;
		inv[i] = Pow(fac[i], mod - 2);

		int num;
		cin >> num;
		for(int j = 0; j < 30; j++) {
			if(num >> j & 1) {
				cnt[j]++;
			}
		}
	}

	for(int bit = 0; bit < 30; bit++) {
		int x = cnt[bit];
		int y = n - x;
		if(x == 0) {
			continue;
		}

		int prod = Pow(2, bit);
		vt<int> a(x + x % 2, prod), b(y + 1);

		for(int i = 1; i <= x; i += 2) {
			a[i - 1] = 0;
			a[i] = a[i] * NCR(x, i) % mod;
		}
		for(int i = 0; i <= y; i++) {
			b[i] = NCR(y, i);
		}

		vt<int> c;
		multiply(a, b, c);
		int z = x + x % 2 + y;
		for(int i = 0; i < z; i++) {
			ans[i] += c[i];
		}
	}

	for(int i = 1; i <= n; i++) {
		ans[i] = (ans[i] + ans[i - 1]) % mod;
	}

	int q;
	cin >> q;
	while(q--) {
		int m;
		cin >> m;
		cout << ans[m] << '\n';
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
/*
    Things to keep in mind :-
    x | (x + 1) sets lowest unset bit of x
    x & (x - 1) unsets lowest set bit of x
*/

