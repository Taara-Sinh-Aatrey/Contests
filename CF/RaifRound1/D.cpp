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
const ll mxN = 2e5 + 1;
ll n;
vt<ll> a;

void solve(){
	cin >> n;
	a = vt<ll>(n);
	For(i, n){
		cin >> a[i];
	}
	vt<pair<ll, ll>> vec;
	vt<ll> Sz[3];
	vt<ll> row(n, -1);
	Sz[0] = vt<ll>(n);
	bool ok = true;
	iota(all(Sz[0]), 0);
	Rev(i, n){
		ll cur = -1;
		if(a[i] == 0)
			continue;
		if(a[i] == 1){
			if(Sz[0].empty()){
				ok = false;
				break;
			}
			cur = Sz[0].back();
			Sz[0].pop_back();
			vec.pb({cur, i});
			Sz[1].pb(cur);
		}else if(a[i] == 2){
			if(Sz[1].empty()){
				ok = false;
				break;
			}
			cur = Sz[1].back();
			Sz[1].pop_back();
			vec.pb({cur, i});
			Sz[2].pb(cur);
		}else if(a[i] == 3){
			if(Sz[0].empty()){
				ok = false;
				break;
			}
			cur = Sz[0].back();
			Sz[0].pop_back();
			ll j = -1;
			for(ll k : {2, 1}){
				if(!Sz[k].empty()){
					j = Sz[k].back();
					Sz[k].pop_back();
					break;
				}
			}
			if(j == -1){
				ok = false;
				break;
			}
			j = row[j];
			vec.pb({cur, j});
			vec.pb({cur, i});
			Sz[2].pb(cur);
		}
		if(cur == -1){
			ok = false;
			break;
		}
		row[cur] = i;
	}
	if(!ok){
		cout << -1 << '\n';
		return;
	}
	cout << sz(vec) << '\n';
	for(auto p: vec){
		cout << p.first + 1 << " " << p.second + 1 << '\n';
	}
}

int main()
{
    ios::sync_with_stdio(0);  cin.tie(0);
    ll t = 1;
    FOR(tt, t) solve();
    return 0;
}