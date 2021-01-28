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
const ll mxN = 1e5 + 5;
ll n;
vt<ll> indices[mxN];

void solve(){
	cin >> n;
	For(i, n){
		ll num;
		cin >> num;
		indices[num].pb(i);
	}
	ll ans = n + 2;
	vt<ar> g;
	for(ll cand = 1; cand <= n + 1; cand++){
		if(cand == 1){
			for(ll ind: indices[1]){
				g.pb({ind, ind});
			}
			if(g.size() == n){
				ans = 1;
				break;
			}
		}else{
			bool ok = true;
			map<ll, ll> L, H;
			vt<ar> g1;
			for(auto p: g){
				ll low = p[0], high = p[1];
				auto z = lower_bound(all(indices[cand]), low);
				if(z == indices[cand].end() || *z > high){
					ok = false;
					if(z != indices[cand].end())
						L[*z] = low;
					if(z != indices[cand].begin()){
						z = prev(z);
						if(H.find(*z) == H.end()){
							H[*z] = high;
						}
					}
				}else{
					g1.pb(p);
				}
			}
			if(ok){
				ans = cand;
				break;
			}
			if(cand == n + 1){
				break;
			}
			for(auto p: L){
				g1.pb({p.second, p.first});
			}
			for(auto p: H){
				g1.pb({p.first, p.second});
			}
			g = g1;
		}
	}
	cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(0);  cin.tie(0);
    solve();
    return 0;
}