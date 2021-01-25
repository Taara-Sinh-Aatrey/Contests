#include<bits/stdc++.h>
using namespace std;

#define ar array<ll, 2>
#define ll long long
#define in insert
#define pb push_back
#define vt vector
#define P_Q(x) priority_queue<x>
#define p_q(x) priority_queue<x, vector<x>, greater<x>>
#define For(i, n) for(ll i = 0; i < n; i++)
#define Rev(i, n) for(ll i = n-1; i >= 0; i--)
#define FOR(i, n) for(ll i = 1; i <= n; i++)
#define REV(i, n) for(ll i = n; i >= 1; i--)
#define Rep(i,a,b) for(ll i = a; i <= b; i++)
#define all(x) (x).begin(),(x).end()

const ll mod = 1e9L + 7;
const ll INF = 1e18L + 5;
const ll mxN = 1e5 + 1;
ll n;
vt<ll> child[mxN], dp(mxN), sz(mxN);
ll node;

void dfs(ll u){
	sz[u] = 1;
	dp[u] = 0;
	for(ll v: child[u]){
		dfs(v);
		sz[u] += sz[v];
		dp[u] = max(dp[u], dp[v]);
	}
	dp[u] += sz[u];
}

void solve(){
	cin >> n;
	FOR(i, n){
		child[i].clear();
	}
	FOR(i, n - 1){
		ll p;
		cin >> p;
		child[p].pb(i + 1);
	}
	dfs(1);
	cout << dp[1] << '\n';
}

int main()
{
    ios::sync_with_stdio(0);  cin.tie(0);
    ll t = 1;
    cin >> t;
    FOR(tt, t) solve();
    return 0;
}