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

#define CERR cout
// #define CERR cerr

void debug_out() { CERR << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
	CERR << " " << to_string(H);
	debug_out(T...);
}

#ifndef ONLINE_JUDGE
#define dbg(...) CERR << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define dbg(...) 42
#endif
#define ar array<ll, 3>
#define ll long long
#define in insert
#define pb push_back
#define vt vector
#define P_Q(x) priority_queue<x>
#define p_q(x) priority_queue<x, vector<x>, greater<x>>
#define For(i, n) for(ll i = 0; i < n; i++)
#define Rev(i, n) for(ll i = n-1; i >= 0; i--)
#define FOR(i, n) for(ll i = 1; i <= n; i++)
#define REV(i, n) for(ll i = n; i >= 1; i--)
#define Rep(i,a,b) for(ll i = a; i <= b; i++)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int) (x).size()

const ll mod = 1e9L + 7;
const ll INF = 1e18L + 5;
const ll mxN = 1e5 + 1;
ll n, a, b;
string s;
vt<ll> p(mxN), rnk(mxN);

ll find(ll u){
	return p[u] == u ? u : p[u] = find(p[u]);
}

void merge(ll u, ll v){
	u = find(u);
	v = find(v);
	if(rnk[u] < rnk[v]){
		p[u] = v;
	}else if(rnk[u] > rnk[v]){
		p[v] = u;
	}else{
		p[v] = u;
		rnk[v]++;
	}
}

void solve(){
	cin >> a >> b >> s;
	ll i = 0;
	ll pre = -1;
	vt<ar> edges;
	n = s.length();
	ll cnt = 0;
	while(i < n){
		while(i < n && s[i] == '0'){
			i++;
		}
		if(i == n){
			break;
		}
		cnt++;
		if(cnt > 1){
			edges.pb({(i - pre - 1) * b, cnt - 1, cnt});
		}
		edges.pb({a, 0, cnt});
		while(i < n && s[i] == '1'){
			i++;
		}
		pre = i - 1;
	}

	For(i, cnt + 1){
		p[i] = i;
		rnk[i] = 0;
	}

	sort(all(edges));
	dbg(edges);

	ll ans = 0;

	for(auto edge: edges){
		ll u = edge[1], v = edge[2];
		u = find(u);
		v = find(v);
		if(u == v){
			continue;
		}
		dbg(u, v);
		merge(u, v);
		ans += edge[0];
	}

	cout << ans << '\n';
	
}

int main()
{
// #ifndef ONLINE_JUDGE
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
// #endif
    ios::sync_with_stdio(0);  cin.tie(0);
    ll t = 1;
    cin >> t;
    FOR(tt, t) solve();
    return 0;
}