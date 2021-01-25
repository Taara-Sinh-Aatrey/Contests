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

ll n;
vt<ll> a;

ll qry(ll i, ll j){
	cout << "XOR " << i << " " << j << endl;
	ll ans;
	cin >> ans;
	return ans;
}

void solve(){
	cin >> n;
	ll a[n + 1], b[n + 1];
	map<ll, ll> mp;
	bool got_same = false;
	ll x, y;
	Rep(i, 2, n){
		b[i] = qry(1, i);
		if(mp.find(b[i]) != mp.end() && !got_same){
			got_same = true;
			x = mp[b[i]];
			y = i;
		}
		mp[b[i]] = i;
	}
	if(got_same){
		cout << "AND " << x << " " << y << endl;
		ll ele;
		cin >> ele;
		a[x] = a[y] = ele;
		assert(b[x] == b[y]);
		a[1] = b[x] ^ a[x];
		Rep(i, 2, n){
			a[i] = b[i] ^ a[1];
		}
	}else{
		// every number from 0 to n - 1 appears once
		ll i = 1, j, k = 2;
		for(j = 2; j <= n; j++){
			if(b[j] == (n - 1)){
				break;
			}
		}
		if(j == 2){
			k = 3;
		}
		ll aij = 0, aik, ajk;
		cout << "AND " << i << " " << k << endl;
		cin >> aik;
		cout << "AND " << j << " " << k << endl;
		cin >> ajk;

		ll sij = b[j] + 2 * aij;
		ll sjk = (b[j] ^ b[k]) + 2 * ajk;
		ll sik = b[k] + 2 * aik;

		a[i] = (sij - sjk + sik) / 2;

		Rep(i, 2, n){
			a[i] = b[i] ^ a[1];
		}
	}

	cout << "!";
	FOR(i, n){
		cout << " " << a[i];
	}
	cout << endl;
}

int main()
{
    ios::sync_with_stdio(0);  cin.tie(0);
    ll t = 1;
    // cin >> t;
    FOR(tt, t) solve();
    return 0;
}

