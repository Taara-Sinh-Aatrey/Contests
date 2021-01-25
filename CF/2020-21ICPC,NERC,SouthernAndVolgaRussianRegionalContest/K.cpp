#include <bits/stdc++.h>
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

#define output cout

void debug_out() { output << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
	output << " " << to_string(H);
	debug_out(T...);
}

#ifndef ONLINE_JUDGE
#define dbg(...) output << "[" << #__VA_ARGS__ << "] :", debug_out(__VA_ARGS__)
#else
#define dbg(...) 42
#endif

#define ll int64_t // long long(x) cannot be done but int64_t(x) can be
#define ull unsigned long long
#define lld long double
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define vt vector
#define vll vt<ll>
#define pll pair<ll,ll>
#define vpll vt<pll>
#define vvll vt<vll>
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(), v.rend()
#define FOR(i,n) for(ll i=0;i<n;i++)
#define ffo(i,a,b) for(ll i=a;i<=b;i++)
#define rfo(i,a,b) for(ll i=a;i>=b;i--)
#define space cout<<"\n\n";
#define endl '\n' // comment this line in interactive prob
template <typename T> using mxpq = priority_queue<T>;
template <typename T> using mnpq = priority_queue<T, vt<T>, greater<T>>;
#define fps(x,y) fixed<<setprecision(y)<<x
#define merg(a,b,c) set_union(a.begin(),a.end(),b.begin(),b.end(),inserter(c,c.begin()))
#define mmss(arr,v) memset(arr,v,sizeof(arr))

const ll mod = 1e9 + 7;
const ll N = 1e6 + 6;
const ll maxN = 1e4 + 5;
const ll MAX_SIZE = 2e6 + 6;
const ll INF = 0x3f3f3f3f3f3f3f3fll;
const double PI = 3.14159265359;

int dx[4] = { -1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
// up, right, down, left
//int dx[] = {+1,-1,+0,+0,-1,-1,+1,+1}; // Eight Directions
//int dy[] = {+0,+0,+1,-1,+1,-1,-1,+1}; // Eight Directions
//int dx[]= {-2,-2,-1,1,-1,1,2,2}; // Knight moves
//int dy[]= {1,-1,-2,-2,2,2,-1,1}; // Knight moves
// For taking a line input: string s = ""; while(s.length() == 0) getline(cin, s);
// For calculating inverse modulo, raise to the power mod-2.
// For (a^b)%mod, where b is large, replace b by b%(mod-1).

ll powerM(ll x, ll y, ll M = mod) { // default argument
	ll v = 1; x = x % M; while (y > 0) {if (y & 1)v = (v * x) % M; y = y >> 1; x = (x * x) % M;} return v;
}

ll power(ll x, ll y) {
	ll v = 1; while (y > 0) {if (y & 1)v = v * x; y = y >> 1; x = x * x;} return v;
}

int largest_bit(long long x) { // based on 0-indexing
	return x == 0 ? -1 : 63 - __builtin_clzll(x);
}

void solve() {
	string str;
	cin >> str;
	ll a = 0;
	ll b = 0;
	ll m, n;
	for (int i = 0; i < (int) str.length(); i++) {
		// i th move get blocked
		ll bx = a, by = b;
		if (str[i] == 'L')
		{
			bx--;
		}
		if (str[i] == 'R')
		{
			bx++;
		}
		if (str[i] == 'U')
		{
			by++;
		}
		if (str[i] == 'D')
		{
			by--;
		}
		//
		// dbg(bx, by);
		m = 0, n = 0;
		for (int j = 0; j < (int)str.length(); j++)
		{
			//
			if (str[j] == 'L')
			{
				m--;
				if (m == bx && n == by) {
					++m;
				}
			}
			if (str[j] == 'R')
			{
				m++;
				if (m == bx && n == by) {
					--m;
				}
			}
			if (str[j] == 'U')
			{
				n++;
				if (m == bx && n == by) {
					--n;
				}
			}
			if (str[j] == 'D')
			{
				n--;
				if (m == bx && n == by) {
					++n;
				}
			}
		}
		// dbg(i, m, n);
		if (m == 0 && n == 0)
		{
			cout << bx << " " << by << endl;
			return;
		}

		//
		//
		if (str[i] == 'L')
		{
			a--;
		}
		if (str[i] == 'R')
		{
			a++;
		}
		if (str[i] == 'U')
		{
			b++;
		}
		if (str[i] == 'D')
		{
			b--;
		}
	}
	//
	if (a == 0 && b == 0) {
		cout << "500001 500001\n";
		return;
	}
	cout << 0 << " " << 0 << endl;
}

int main()
{
#ifdef LOCAL
	freopen("in1.txt", "r", stdin);
	freopen("out1.txt", "w", stdout);
#endif
	FIO;
	int testcases = 1;
	cin >> testcases;
	for (int caseno = 1; caseno <= testcases; ++caseno) {
		solve();
	}
	return 0;
}

// cerr << "[Execution : " << (1.0 * clock()) / CLOCKS_PER_SEC << "s]\n";
