#include<bits/stdc++.h>
using namespace std;

template <typename A, typename B>
string to_string(pair<A, B> p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);

string to_string(const string& s) {
	return '"' + s + '"';
}

string to_string(const char* s) {
	return to_string((string) s);
}

string to_string(bool b) {
	return (b ? "true" : "false");
}

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
	for (const auto &x : v) {
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

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
	return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
	return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
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

#define ar array<ll, 2>
#define pll pair<ll, ll>
#define ll long long
#define in insert
#define pb push_back
#define vt vector
#define For(i, n) for(ll i = 0; i < n; i++)
#define Rev(i, n) for(ll i = n-1; i >= 0; i--)
#define FOR(i, n) for(ll i = 1; i <= n; i++)
#define REV(i, n) for(ll i = n; i >= 1; i--)
#define Rep(i,a,b) for(ll i = a; i <= b; i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define sz(x) (int) (x).size()

template <typename T> using mxpq = priority_queue<T>;
template <typename T> using mnpq = priority_queue<T, vt<T>, greater<T>>;
template<typename T1, typename T2>
istream& operator>>(istream& in, pair<T1, T2> &a) {in >> a.first >> a.second; return in;}
template<typename T1, typename T2>
ostream& operator<<(ostream& out, pair<T1, T2> a) {out << a.first << " " << a.second; return out;}
template<class A, size_t S>
istream& operator>>(istream& in, array<A, S>& a) {for(A &x: a) in >> x; return in;}
template<class A, size_t S>
ostream& operator<<(ostream& out, array<A, S>& a) {bool f = false; for(A &x: a){if(f) {out << " ";} out << x; f = true;} return out;}
template<typename T>
istream& operator>>(istream& in, vt<T>& a) {for(T &x: a) in >> x; return in;}
template <typename T>
ostream& operator<<(ostream& out, vt<T>& a) {bool f = false; for(T x: a){ if(f){ out << " ";} out << x; f = true;} out << '\n'; return out;}
template<class A, size_t S>
istream& operator>>(istream& in, vt<array<A, S>>& a) {for(array<A, S> &x: a) in >> x; return in;}
template<class A, size_t S>
ostream& operator<<(ostream& out, vt<array<A, S>>& a) {bool f = false; for(array<A, S> &x: a){ if(f){ out << " ";} out << x; f = true;} out << '\n'; return out;}
template <typename T> void out(T a[], size_t n) {For(i, n){ if(i > 0){ cout << " ";} cout << a[i];} cout << '\n';}
template <typename T> void in(T a[], size_t n) {For(i, n) cin >> a[i]; }
void out(bool ok, bool cap = true) {if(cap) cout << (ok ? "YES" : "NO") << '\n'; else cout << (ok ? "Yes" : "No") << '\n';}
template<typename T, typename T1>
T amax(T &a, T1 b) {if (b > a) a = b; return a;}
template<typename T, typename T1>
T amin(T &a, T1 b) {if (b < a) a = b; return a;}

const ll mod = 1e9L + 7;
const ll INF = 1e18L + 5;
const ll mxN = 2e5 + 5;

ll n;
vt<ll> a;

void solve(){
	cin >> n;
	a = vt<ll>(n);
	cin >> a;
}

int main()
{
#ifdef LOCAL
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);  cin.tie(0);
    ll t = 1;
    // cin >> t;
    FOR(tt, t) solve();
    return 0;
}