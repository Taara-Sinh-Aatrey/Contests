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

void solve(){
	cin >> n;
	vt<array<ll, 2>> d;
	ll xp = 0, xn = 0, yp = 0, yn = 0;
	For(i, n){
		ll x, y, u, v;
		cin >> x >> y >> u >> v;
		ll dx = u - x;
		ll dy = v - y;
		if(dx != 0 && dy != 0)
			d.pb({dx, dy});
		else{
			assert(dx != 0 || dy != 0);
			if(dx > 0)
				xp++;
			if(dx < 0)
				xn++;
			if(dy > 0)
				yp++;
			if(dy < 0)
				yn++;
		}
	}
	sort(all(d), [&](array<ll,2> x, array<ll, 2> y){
		if((x[0] * x[1] < 0) == (y[0] * y[1] < 0)){
			return abs(x[0] * y[1]) < abs(y[0] * x[1]);
		}
		return (x[0] * x[1] < 0) > (y[0] * y[1] < 0);
	});

	array<ll, 2> p = {0, 0};
	ll neg = 0, pos = 0, ans = 0;

	for(auto ele: d){
		assert(ele[0] != 0 && ele[1] != 0);
		if(ele[1] * p[0] == ele[0] * p[1] && (p[0] != 0 || p[1] != 0)){
			if(ele[0] < 0){
				neg++;
			}else{
				pos++;
			}
		}else{
			ans += pos * neg;
			pos = 0, neg = 0;
			if(ele[0] < 0){
				neg++;
			}else{
				pos++;
			}
		}
		p = ele;
	}
	ans += pos * neg;

	ans += xp * xn + yp * yn;

	cout << ans << '\n';
	
}

int main()
{
    ios::sync_with_stdio(0);  cin.tie(0);
    ll t = 1;
    cin >> t;
    FOR(tt, t) solve();
    return 0;
}