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

#define int int64_t
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
vt<ll> a, dp;

class max_segtree{
public:
	vt<int> seg;
    vt<int> arr;
    int n;

    max_segtree(int _n) : n(_n){
		int p = 1;
		while(p < n){
			p *= 2;
		}
		p *= 2;
		seg.resize(p, 0);
	}

    max_segtree(int _n, vt<int>& _arr) : max_segtree(_n) {
    	arr = _arr;
        build(0, n - 1, 0);
    }

    int build(int st, int en , int idx){
        if(st == en){
            seg[idx] = arr[st];
            return seg[idx];
        }
        int mid = (st + en) / 2;
        int lhs = build(st, mid, 2 * idx + 1);
        int rhs = build(mid + 1, en, 2 * idx + 2);
        seg[idx] = max(lhs, rhs);
        return seg[idx];
    }

    int get(int query_start, int query_end){
        return get(query_start, query_end, 0, n - 1, 0);
    }

    int get(int query_start, int query_end, int st, int en, int idx){
        if(query_start > en || query_end < st){
            return -INF;
        }
        if(query_start <= st && en <= query_end){
            return seg[idx];
        }
        int mid = (st + en) / 2;
        int lhs = get(query_start, query_end, st, mid, 2 * idx + 1);
        int rhs = get(query_start, query_end, mid + 1, en, 2 * idx + 2);
        return max(lhs, rhs);
    }

    void upd(int ind, int val){
		upd(ind, val, 0, n - 1, 0);
	}

	int upd(int ind, int val, int st, int en, int idx){
		if(st > ind || en < ind){
			return seg[idx];
		}
		if(st == en){
			seg[idx] = max(seg[idx], val);
			return seg[idx];
		}
		int mid  = (st + en) / 2;
		int lhs = upd(ind, val, st, mid, 2 * idx + 1);
		int rhs = upd(ind, val, mid + 1, en, 2 * idx + 2);
		seg[idx] = max(lhs, rhs);
		return seg[idx];
	}
};

void solve(){
	cin >> n;
	a.resize(n);
	dp = vt<ll>(n, 0);
	For(i, n){
		cin >> a[i];
		a[i]--;
	}

	max_segtree st(n);

	set<pair<ll, ll>> s;
	s.emplace(0, 0);

	for(int i = 0; i < n; i++){
		dp[i] = 1 + st.get(0, a[i]);
		st.upd(a[i], dp[i]);
		while(!s.empty() && s.begin()->first <= a[i]){
			st.upd(s.begin()->first, s.begin()->second + 1);
			s.erase(s.begin());
		}
		s.emplace(a[i], dp[i]);
	}
	// dbg(dp);
	cout << *max_element(all(dp)) << '\n';	
}

signed main()
{
#ifdef LOCAL
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif
    ios::sync_with_stdio(0);  cin.tie(0);
    ll t = 1;
    cin >> t;
    FOR(tt, t) solve();
    return 0;
}