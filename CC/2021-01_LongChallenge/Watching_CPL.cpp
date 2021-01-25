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
const ll mxN = 2e5 + 5;

ll n, k;
vt<ll> a;

void solve(){
	cin >> n >> k;
	a.resize(n);
	For(i, n){
		cin >> a[i];
		a[i] = min(a[i], k);
	}

	sort(a.rbegin(), a.rend());

	vt<pair<ll, ll>> dp(2 * k, {INF, -1});

	dp[0] = {0, -1};

	for(int i = 0; i < n; i++){
		for(int sum = 2 * k - a[i] - 1; sum >= 0; sum--){
			if(dp[sum + a[i]].first > dp[sum].first + 1){
				dp[sum + a[i]] = {dp[sum].first + 1, i};
			}
		}
	}

	auto fun = [&](ll sb){
		ll cur = dp[sb].first;
		vt<bool> seen(n, 0);
		while(sb > 0){
			ll idx = dp[sb].second;
			seen[idx] = 1;
			sb -= a[idx];
		}

		ll sc = 0;
		for(int i = 0; i < n && sc < k; i++){
			if(seen[i])
				continue;
			sc += a[i];
			cur++;
		}

		if(sc < k){
			return INF;
		}

		return cur;
    };

	ll ans = INF;
	for(ll i = k; i < 2 * k; i++){
		if(dp[i].second == -1)
			continue;
		ans = min(ans, fun(i));
	}

	if(ans >= INF)
		ans = -1;

	cout << ans << '\n';

}

int main()
{
    ios_base::sync_with_stdio(0);  cin.tie(0);
    ll t = 1;
    cin >> t;
    FOR(tt, t) solve();
    return 0;
}