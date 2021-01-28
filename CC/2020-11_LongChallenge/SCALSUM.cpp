#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector
#define For(i, n) for(ll i = 0; i < n; i++)

const ll mod = (1ll << 32);
const ll N = 3e5 + 1;
const ll lvl = 19;

ll n, queries, a[N], depth[N], p[lvl][N], pre[N], answer[N];
vt<ll> g[N];
ll intime[N], outtime[N], nodeAt[2 * N];
vt<bool> vis(N, 0);
vt<ll> lt(N, -1), rt(N, -1);

inline ll hilbertOrder(ll x, ll y, ll pow, ll rotate) {
	if (pow == 0) {
		return 0;
	}
	ll hpow = 1 << (pow-1);
	ll seg = (x < hpow) ? (
		(y < hpow) ? 0 : 3
	) : (
		(y < hpow) ? 1 : 2
	);
	seg = (seg + rotate) & 3;
	const ll rotateDelta[4] = {3, 0, 0, 1};
	ll nx = x & (x ^ hpow), ny = y & (y ^ hpow);
	ll nrot = (rotate + rotateDelta[seg]) & 3;
	ll subSquareSize = 1ll << (2 * pow - 2);
	ll ans = seg * subSquareSize;
	ll add = hilbertOrder(nx, ny, pow-1, nrot);
	ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
	return ans;
}
 
struct Query {
	ll l, r, idx, lc;
	ll ord;
 
	inline void calcOrder() {
		ord = hilbertOrder(l, r, 21, 0);
	}
}q[N];
 
inline bool operator<(const Query &a, const Query &b) {
	return a.ord < b.ord;
}

ll timer = 0;  

void dfs(ll u, ll par){
	nodeAt[timer] = u;
	intime[u] = timer++;
	for(ll v: g[u]){
		if(v != par){
			pre[v] = pre[u] + (a[v] * a[v]) % mod;
			if(pre[v] > mod){
				pre[v] -= mod;
			}
			depth[v] = 1 + depth[u];
			p[0][v] = u;
			dfs(v, u);
		}
	}
	nodeAt[timer] = u;
	outtime[u] = timer++;
}

void compute_parent(){
	for(int i = 1; i < lvl; i++){
		For(node, n){
			if(p[i - 1][node] != -1){
				p[i][node] = p[i - 1][p[i - 1][node]];
			}
		}
	}
}

ll find_lca(ll u, ll v){
	if (depth[u] > depth[v]){ 
		swap(u, v);
	}

	ll diff = depth[v] - depth[u];
	for (int i = lvl - 1; i >= 0; i--)
		if (diff >= (1 << i)) 
			v = p[i][v];

	if (u == v) 
		return u;

	for (int i = lvl - 1; i >= 0; i--){
		if (p[i][u] != p[i][v]){
			u = p[i][u];
			v = p[i][v];
		}
	}
	return p[0][u];
}

int main()
{
	cin >> n >> queries;
	For(i, n){
		cin >> a[i];
	}
	For(i, n - 1){
		ll u, v;
		cin >> u >> v;
		u--; v--;
		g[u].emplace_back(v);
		g[v].emplace_back(u);
	}

	p[0][0] = -1;
	pre[0] = (a[0] * a[0]) % mod;
	dfs(0, -1);
	compute_parent();

	For(i, queries){
		ll u, v;
		cin >> u >> v;
		u--; v--;
		ll lca = find_lca(u, v);
		if(intime[u] > intime[v]){
			swap(u, v);
		}
		assert(u != v);
		q[i].l = outtime[u];
		q[i].r = intime[v];
		q[i].idx = i;
		q[i].lc = lca;
		q[i].calcOrder();
	}

	sort(q, q + queries);

	ll curL = q[0].l, curR = q[0].l - 1;
	ll ans = 0;

	auto fun = [&](ll x){
		x = nodeAt[x];
		bool visited = vis[x];
		ll d = depth[x], y;
		if(vis[x]){
			if(lt[d] == x){
				lt[d] = -1;
				y = rt[d];
			}else{
				rt[d] = -1;
				y = lt[d];
			}
			if(y != -1){
				ans -= (a[x] * a[y]) % mod;
				if(ans < 0){
					ans += mod;
				}
			}
		}else{
			if(lt[d] == -1){
				lt[d] = x;
				y = rt[d];
			}else{
				rt[d] = x;
				y = lt[d];
			}
			if(y != -1){
				ans += (a[x] * a[y]) % mod;
				if(ans >= mod){
					ans -= mod;
				}
			}
		}
		vis[x] = !vis[x];
	};

	For(i, queries){
		ll l = q[i].l, r = q[i].r, lca = q[i].lc;
		while(curL < l) fun(curL++);
		while(curL > l) fun(--curL);
		while(curR < r) fun(++curR);
		while(curR > r) fun(curR--);
		answer[q[i].idx] = (ans + pre[lca]) % mod;
	}

	For(i, queries){
		cout << answer[i] << '\n';
	}
    return 0;
}