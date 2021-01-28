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

#define ar array<ll, 2>
#define ll long long
#define in insert
#define pb push_back
#define vt vector
template <typename T> using mxpq = priority_queue<T>;
template <typename T> using mnpq = priority_queue<T, vt<T>, greater<T>>;
#define For(i, n) for(ll i = 0; i < n; i++)
#define Rev(i, n) for(ll i = n-1; i >= 0; i--)
#define FOR(i, n) for(ll i = 1; i <= n; i++)
#define REV(i, n) for(ll i = n; i >= 1; i--)
#define Rep(i,a,b) for(ll i = a; i <= b; i++)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int) (x).size()

const ll mod = 1e9L + 7;
const ll INF = 1e18L + 5;
const ll mxN = 2e5 + 1;

ll n, q;
vt<ll> a, tree, OR;

void dfs(ll idx, ll st, ll en){
	if(st == en){
		tree[idx] = a[st];
		OR[idx] = true;
		return;
	}
	ll mid = (st + en) / 2;
	dfs(2 * idx + 1, st, mid);
	dfs(2 * idx + 2, mid + 1, en);
	assert(OR[2 * idx + 1] == OR[2 * idx + 2]);
	OR[idx] = !OR[2 * idx + 1];
	if(OR[idx])
		tree[idx] = tree[2 * idx + 1] ^ tree[2 * idx + 2];
	else
		tree[idx] = tree[2 * idx + 1] | tree[2 * idx + 2];
}


void solve(){
	cin >> n >> q;
	a.resize((1 << n) + 1);
	OR.resize(1 << (n + 1));
	tree.resize(1 << (n + 1));
	FOR(i, 1 << n){
		cin >> a[i];
	}
	dfs(0, 1, 1 << n);
	while(q--){
		ll x, y;
		cin >> x >> y;
		ll idx = 0;
		ll st = 1, en = 1 << n;
		while(st != en){
			ll mid = (st + en) / 2;
			if(x <= mid){
				en = mid;
				idx = 2 * idx + 1;
			}else{
				st = mid + 1;
				idx = 2 * idx + 2;
			}
		}
		tree[idx] = y;
		while(idx > 0){
			ll o = idx + (idx & 1 ? 1 : -1);
			assert(OR[idx] == OR[o]);
			if(OR[idx])
				tree[(idx - 1) / 2] = tree[idx] | tree[o];
			else
				tree[(idx - 1) / 2] = tree[idx] ^ tree[o];
			idx = (idx - 1) / 2;
		}
		cout << tree[0] << '\n';
	}
}

int main()
{
    ios::sync_with_stdio(0);  cin.tie(0);
    ll t = 1;
    // cin >> t;
    FOR(tt, t) solve();
    return 0;
}