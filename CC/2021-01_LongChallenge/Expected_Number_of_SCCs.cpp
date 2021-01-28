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

const ll mod = 998244353;
const ll INF = 1e18L + 5;
const ll mxN = 1e5 + 5;

ll m, n, k;
vt<ll> a, fac(mxN, 1);

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

ll NCR(ll N, ll R){
	if(R > N){
		return 0;
	}
	return fac[N] * Pow(fac[R] * fac[N - R] % mod, mod - 2) % mod;
}

void solve(){
	cin >> m >> n >> k;
	if(m == 1){
		if(n == 1){
			cout << 1 << '\n';
			return;
		}
		ll ans = 0, p = k;
		Rep(i, 1, n){
			ans += i * NCR(n - 1, i - 1) % mod * p % mod;
			ans %= mod;
			p = p * (k - 1) % mod;
		}
		cout << ans * Pow(Pow(k, n), mod - 2) % mod << '\n';
		return;
	}

	ll same = k, diff = 2 * k % mod * (k - 1) % mod, same_cnt = k, diff_cnt = k * (k - 1) % mod;

	for(ll i = 1; i < n; i++){
		ll nsame = (same + diff) * k % mod + same_cnt * (k - 1) % mod + diff_cnt * (k - 2) % mod;
		nsame %= mod;
		ll nsame_cnt = (same_cnt + diff_cnt) * k % mod;
		ll ndiff = (same + diff) % mod * k % mod * (k - 1) % mod + 2 * (same_cnt + diff_cnt) % mod * Pow(k - 1, 2) % mod;
		ndiff %= mod;
		ll ndiff_cnt = (same_cnt + diff_cnt) % mod * k % mod * (k - 1) % mod;

		same = nsame, diff = ndiff, same_cnt = nsame_cnt, diff_cnt = ndiff_cnt;
	}
	cout << (same + diff) % mod * Pow(Pow(k, 2 * n), mod - 2) % mod << '\n';

}

int main()
{
    ios_base::sync_with_stdio(0);  cin.tie(0);

    Rep(i, 2, mxN - 1){
		fac[i] = (fac[i - 1] * i) % mod;
	}
    solve();
    return 0;
}