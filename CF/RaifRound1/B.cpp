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
#define sz(x) (int) (x).size()

const ll mod = 1e9L + 7;
const ll INF = 1e18L + 5;
const ll mxN = 3e5 + 1;
ll n;
vt<ll> adj[mxN], adj2[mxN], vis(mxN), vec;
ll cur;
string s;

void dfs(ll u){
	vis[u] = 1;
	for(ll v: adj2[u]){
		if(!vis[v])
			dfs(v);
	}
	vec.pb(u);
}

void dfs2(ll u){
	vis[u] = 1;
	cur++;
	for(ll v: adj[u]){
		if(!vis[v])
			dfs2(v);
	}
}

void solve(){
	cin >> n >> s;
	For(i, n){
		adj[i].clear();
		adj2[i].clear();
		vis[i] = 0;
	}
	vec.clear();

	For(i, n){
		if(s[i] == '>'){
			adj[i].pb((i + 1) % n);
			adj2[(i + 1) % n].pb(i);
		}else if(s[i] == '<'){
			adj[(i + 1) % n].pb(i);
			adj2[i].pb((i + 1) % n);
		}else{
			adj[i].pb((i + 1) % n);
			adj[(i + 1) % n].pb(i);
			adj2[i].pb((i + 1) % n);
			adj2[(i + 1) % n].pb(i);
		}
	}
	For(i, n){
		if(!vis[i]){
			dfs(i);
		}
	}
	reverse(all(vec));

	For(i, n){
		vis[i] = 0;
	}
	ll ans = 0;
	for(ll u: vec){
		if(!vis[u]){
			cur = 0;
			dfs2(u);
			if(cur > 1){
				ans += cur;
			}
		}
	}
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