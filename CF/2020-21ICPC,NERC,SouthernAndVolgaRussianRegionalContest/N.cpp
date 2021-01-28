#include <bits/stdc++.h>
using namespace std;

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
	ll c1, c2, c3;
	cin >> c1 >> c2 >> c3;
	ll a1, a2, a3, a4, a5;
	cin >> a1 >> a2 >> a3 >> a4 >> a5;
	c1 -= a1;
	c2 -= a2;
	c3 -= a3;
	if (c1 < 0 || c2 < 0 || c3 < 0) {
		cout << "NO\n"; return;
	}
	ll m1 = min(c1, a4);
	a4 -= m1;
	ll m2 = min(c2, a5);
	a5 -= m2;
	if (a4 + a5 <= c3) {
		cout << "YES\n";
	}
	else {
		cout << "NO\n";
	}
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
