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

ll n;
vt<ll> a;

class min_segtree{
public:
	ll seg[1 << 19];
	vt<ll> arr;
	ll n;

	min_segtree(ll _n, vt<ll> _arr){
		n = _n;
		arr = _arr;
		build(0, n - 1, 0);
	}

	min_segtree(){
	}

	ll build(ll st, ll en , ll idx){
		if(st == en){
			seg[idx] = arr[st];
			return seg[idx];
		}
		ll mid = (st + en) / 2;
		ll lhs = build(st, mid, 2 * idx + 1);
		ll rhs = build(mid + 1, en, 2 * idx + 2);
		seg[idx] = min(lhs, rhs);
		return seg[idx];
	}

	ll get(ll query_start, ll query_end){
		return get(query_start, query_end, 0, n - 1, 0);
	}

	ll get(ll query_start, ll query_end, ll st, ll en, ll idx){
		if(query_start > en || query_end < st){
			return INF;
		}
		if(query_start <= st && en <= query_end){
			return seg[idx];
		}
		ll mid = (st + en) / 2;
		ll lhs = get(query_start, query_end, st, mid, 2 * idx + 1);
		ll rhs = get(query_start, query_end, mid + 1, en, 2 * idx + 2);
		return min(lhs, rhs);
	}
};

void solve(){
	cin >> n;
	a.resize(n);
	For(i, n){
		cin >> a[i];
	}
	min_segtree st(n, a);
	vt<ll> dp(n, 0);
	Rev(i, n){
		dp[i] = a[i];
		if(i + 1 < n){
			dp[i] = max(dp[i], -dp[i + 1]);
		}
		dp[i] = -dp[i];
	}
	ll maxi = 0;
	For(i, n - 1){
		maxi = max(maxi, a[i]);
		ll j = i + 1;
		ll k = lower_bound(dp.begin() + j + 1, dp.end(), -maxi) - dp.begin();
		if(k >= n || dp[k] != -maxi){
			continue;
		}
		if(k + 1 < n && dp[k + 1] == -maxi && a[k] == maxi){
			k++;
		}
		if(k >= n){
			continue;
		}
		if(st.get(j, k - 1) == maxi){
			cout << "YES\n" << j << " " << k - j << " " << n - k << '\n';
			return;
		}
	}
	cout << "NO\n";
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif
    ios::sync_with_stdio(0);  cin.tie(0);
    ll t = 1;
    cin >> t;
    FOR(tt, t) solve();
    return 0;
}