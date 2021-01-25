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
const ll M = 5e5 + 5;

ll n, m;


ll Pow(ll a, ll b){
    ll res = 1ll;
    assert(b >= 0);
    while(b){
        if(b&1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}


void solve(){
	cin >> n >> m;
	vt<ll> s1(m + 1);
	set<pair<ll, ll>> s2;
	vt<ll> s;
	FOR(dd, n){
		ll k;
		cin >> k;
		ll x, y;
		if(k == 1){
			cin >> x;
			if(s1[x]){
				continue;
			}else{
				s.pb(dd);
				s1[x] = 1;
				pair<ll, ll> se = {x, 0};
				auto it = s2.lower_bound(se);
				auto it1 = it;
				vt<pair<ll, ll>> temp;
				while(it != s2.end() && it->first == x){
					temp.pb({it->second, it->first});
					s1[it->second] = 1;
					it++;
				}
				s2.erase(it1, it);
				for(auto p: temp){
					auto it = s2.find(p);
					if(it != s2.end()){
						s2.erase(it);
					}
				}
			}
		}else{
			cin >> x >> y;
			if(s1[x] == 1 && s1[y] == 1){
				continue;
			}
			auto it = s2.lower_bound({x, y});
			if(it != s2.end() && *it == make_pair(x, y)){
				continue;
			}
			s.pb(dd);
			if(s1[x] == 1 || s1[y] == 1){
				s1[x] = 1;
				s1[y] = 1;
				continue;
			}
			if(x > y){
				swap(x, y);
			}
			pair<ll, ll> se = {x, 0};
			it = s2.lower_bound(se);
			vt<ll> temp1;
			while(it != s2.end() && it->first == x){
				temp1.pb(it->second);
				it++;
			}

			vt<ll> temp2;
			se = {y, 0};
			it = s2.lower_bound(se);
			while(it != s2.end() && it->first == y){
				temp2.pb(it->second);
				it++;
			}

			s2.insert({x, y});
			s2.insert({y, x});

			for(ll z: temp1){
				s2.insert({x, z});
				s2.insert({z, x});
			}

			for(ll z: temp2){
				s2.insert({y, z});
				s2.insert({z, y});
			}
		}
	}
	ll w2 = sz(s2);
	assert(w2 % 2 == 0);
	w2 /= 2;

	ll w1 = 0;
	FOR(i, m){
		if(s1[i] == 1){
			w1++;
		}
	}
	cout << Pow(2, w1 + w2) << ' ' << sz(s) << '\n';
	for(ll ele: s){
		cout << ele << " ";
	}
	cout << '\n';
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