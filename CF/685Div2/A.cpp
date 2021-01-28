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

const ll INF = 1e18L + 5;
const ll mxN = 2e5 + 1;
const ll mod = 1e9L + 7;

ll n;
vt<ll> a;
// vt<ll> primes;
// vt<ll> prime(100000), lpf(100000);

ll factorize(ll num){
	ll org = num;
	vector<ll> vec;
	ll y = -1;
	while(num % 2 == 0 && num != 2){
		return 2;
	}
	for(ll x = 3; x * x <= num; x += 2){
		ll cnt = 0;
		if((num % x) == 0){
			return x;
		}
	}
	if(num > 2 && num != org){
		return num;
	}
	return -1;
}

void solve(){
	cin >> n;
	queue<ar> q;
    q.push({n, 0});
    map<ll, ll> mp;
    if(n == 1){
    	cout << 0 << '\n';
    	return;
    }
    mp[n] = 0;
    while(!q.empty()){
    	auto ele = q.front();
    	dbg(n, ele);
    	q.pop();
    	ll y = factorize(ele[0]);
    	if(y != -1 && mp.find(y) == mp.end()){
    		q.push({y, ele[1] + 1});
    	}
    	// for(ll x: vec){
    	// 	assert(x != ele[0]);
    	// 	ll y = ele[0] / x;
    	// 	if(y == 1){
    	// 		cout << ele[1] + 1 << '\n';
    	// 		return;
    	// 	}
    	// 	if(mp.find(y) == mp.end() || mp[y] > ele[1] + 1){
    	// 		q.push({y, ele[1] + 1});
    	// 		mp[y] = 1 + ele[1];
    	// 	}
    	// }
    	y = ele[0] - 1;
    	if(y == 1){
			cout << ele[1] + 1 << '\n';
			return;
		}
    	if(mp.find(y) == mp.end()){
			q.push({y, ele[1] + 1});
		}
    }
}

int main()
{
    ios::sync_with_stdio(0);  cin.tie(0);
    ll t = 1;
    cin >> t;
    // prime[2] = 1;
    // for(ll int i = 2; i * i <= 1000000000; i++){
    // 	if(!prime[i])
    // 		continue;
    // 	primes.pb(i);
    // 	for(int j = 2 * i; j * j <= 1000000000; j++){
    // 		prime[j] = 0;
    // 	}
    // }

    FOR(tt, t) solve();
    return 0;
}