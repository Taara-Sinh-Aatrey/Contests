#include<bits/stdc++.h>
using namespace std;

#define ar array<ll, 3>
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
#define sz(x) (int) (x).size()

const ll mod = 1e9L + 7;
const ll INF = 1e18L + 5;
const ll mxN = 2e5 + 1;
ll n;
vt<ll> g[mxN], a;

ar dfs(ll u, ll p = -1){
	if(g[u].empty()){
		return {a[u], a[u], 1};
	}
	ll cnt = 0, sum = 0, maxi = 0;
	for(ll v: g[u]){
		if(v != p){
			ar x = dfs(v, u);
			cnt += x[2];
			sum += x[0];
			maxi = max(maxi, x[1]);
		}
	}
	ll req = maxi * cnt - sum;
	ll temp = min(req, a[u]);
	req -= temp;
	a[u] -= temp;
	maxi = maxi + (a[u] + cnt - 1) / cnt;
	ar ret = {sum + a[u] + temp, maxi, cnt};
	return ret;
}

void solve(){
	cin >> n;
	a = vt<ll>(n + 1);
	Rep(i, 2, n){
		cin >> a[i];
		g[a[i]].pb(i);
	}
	FOR(i, n){
		cin >> a[i];
	}
	ar res = dfs(1);
	cout << res[1] << '\n';
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif
    ios::sync_with_stdio(0);  cin.tie(0);
    solve();
    return 0;
}