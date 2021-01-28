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
const ll N = 1e5 + 1;

ll n, times, s;
ll a[N];
ll nxt[N];
ll highest[1 << 18], max_dp[1 << 18];

ll construct_seg_tree(ll seg[], ll arr[], ll st/* start index*/, ll en /*end index*/, ll idx /*current index of seg tree*/){
	if(st == en){
		seg[idx] = st;
		return st;
	}
	ll mid = (st + en) / 2;
	ll lmax = construct_seg_tree(seg, arr, st, mid, 2 * idx + 1);
	ll rmax = construct_seg_tree(seg, arr, mid + 1, en, 2 * idx + 2);
	ll ret = rmax;
	if(arr[lmax] > arr[rmax]){
		ret = lmax;
	}
	seg[idx] = ret;
	return ret;
}

ll qry(ll seg[], ll arr[], ll l, ll r, ll st, ll en, ll idx){
	if(l > en || r < st){
		return n;
	}
	if(l <= st && en <= r){
		// dbg(l, r, st, en, seg[idx]);
		return seg[idx];
	}
	ll mid = (st + en) / 2;
	ll lmax = qry(seg, arr, l, r, st, mid, 2 * idx + 1);
	ll rmax = qry(seg, arr, l, r, mid + 1, en, 2 * idx + 2);
	ll ret = rmax;
	if(arr[lmax] > arr[rmax]){
		ret = lmax;
	}
	// dbg(l, r, st, en, ret);
	return ret;
}

void solve1(){
	ll dp[n + 1];
	dp[n] = 0;
	a[n] = 0;
	stack<ll> st;
	construct_seg_tree(highest, a, 0, n - 1, 0);
	For(i, n){
		while(!st.empty() && a[st.top()] < a[i]){
			nxt[st.top()] = i;
			st.pop();
		}
		st.push(i);
	}
	while(!st.empty()){
		nxt[st.top()] = n;
		st.pop();
	}
	Rev(i, n){
		dp[i] = 1 + dp[nxt[i]];
	}

	// For(i, n){
	// 	cout << dp[i] << ' ';
	// }
	// cout << '\n';

	construct_seg_tree(max_dp, dp, 0, n - 1, 0);

	ll last = 0;
	For(i, times){
		ll l, r;
		cin >> l >> r;
		l = (l + s * last - 1) % n;
		r = (r + s * last - 1) % n;
		if(l > r){
			swap(l, r);
		}
		ll ans = 1;
		while(l <= r){
			ll h = qry(highest, a, l, r, 0, n - 1, 0);
			// dbg(l, h, a[h]);
			ll z = qry(max_dp, dp, l, h, 0, n - 1, 0);
			ll val = dp[z] - dp[h] + 1;
			// dbg(z, dp[z], h, dp[h], val);
			ans = max(ans, val);
			l = h + 1;
		}
		cout << ans << '\n';
		last = ans;
	}
}

void solve0(){
	ll dp[n + 1][n + 1];
	for(int i = 0; i < n; i++){
		dp[i][i] = 1;
		int cur = a[i];
		for(int j = i + 1; j < n; j++){
			dp[i][j] = dp[i][j - 1];
			if(a[j] > cur){
				dp[i][j]++;
				cur = a[j];
			}
		}
	}
	for(int j = 0; j < n; j++){
		for(int i = j - 1; i >= 0; i--){
			dp[i][j] = max(dp[i][j], dp[i + 1][j]);
		}
	}
	ll last = 0;
	while(times--){
		ll l, r;
		cin >> l >> r;
		l = (l + s * last - 1) % n;
		r = (r + s * last - 1) % n;
		if(l > r){
			swap(l, r);
		}
		last = dp[l][r];
		cout << last << '\n';
	}
}

int main()
{
    ios::sync_with_stdio(0);  cin.tie(0);
	cin >> n >> times >> s;
	For(i, n){
		cin >> a[i];
	}
    if(n <= 0){
    	solve0();
    }else{
    	solve1();
    }
    return 0;
}



// #include<bits/stdc++.h>
// using namespace std;

// int main()
// {
//     ios::sync_with_stdio(0);  cin.tie(0);

// 	int n, q, s;
// 	cin >> n >> q >> s;

// 	// input array
// 	vector<int> a(n + 1);
// 	for(int i = 1; i <= n; i++){
// 		cin >> a[i];
// 	}

// 	// 2D dp where dp[i][j] represents maximum satisfaction for range [i, j]
// 	int dp[n + 1][n + 1];

// 	for(int i = 1; i <= n; i++){
// 		// base case
// 		dp[i][i] = 1;

// 		// max element so far
// 		int maxi = a[i];

// 		// right parameter j from i + 1 to n for a fixed i
// 		for(int j = i + 1; j <= n; j++){
// 			dp[i][j] = dp[i][j - 1];
// 			if(a[j] > maxi){
// 				// adding one value
// 				dp[i][j]++;

// 				// updating max value
// 				maxi = a[j];
// 			}
// 		}
// 	}

// 	// updating dp[i][j] to be max of (dp[i][j], dp[i + 1][j], dp[i + 2][j], ......., dp[j - 1][j], dp[j][j])
// 	for(int j = 1; j <= n; j++){
// 		for(int i = j - 1; i > 0; i--){
// 			dp[i][j] = max(dp[i][j], dp[i + 1][j]);
// 		}
// 	}

// 	// last value required to update the l and r for the next query
// 	int last = 0;
// 	for(int _ = 0, u, v; _ < q; _++){
// 		// u and v 
// 		cin >> u >> v;

// 		// updating u and v using last query's result
// 		u = (u + s * last - 1) % n + 1;
// 		v = (v + s * last - 1) % n + 1;

// 		// making u smaller than v
// 		if(u > v){
// 			swap(u, v);
// 		}

// 		// answer of current query
// 		last = dp[u][v];

// 		// writing the answer
// 		cout << last << '\n';
// 	}
//     return 0;
// }