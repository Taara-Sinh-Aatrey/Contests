#include<bits/stdc++.h>
using namespace std;

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

ll n, W;

void solve(){
	cin >> n >> W;
	vt<ar> vec;
	ll w = (W + 1) / 2;
	For(i, n){
		ll x;
		cin >> x;
		if(x <= W){
			vec.pb({x, i + 1});
		}
	}
	vt<ll> print;
	sort(vec.rbegin(), vec.rend());
	ll cur = 0;
	for(auto p: vec){
		cur += p[0];
		print.pb(p[1]);
		if(cur >= w){
			assert(cur <= W);
			break;
		}
	}
	if(w <= cur && cur <= W){
		cout << sz(print) << '\n';
		for(auto ele: print){
			cout << ele << " ";
		}
		cout << '\n';
	}else{
		cout << -1 << '\n';
	}
}

int main()
{
    ios::sync_with_stdio(0);  cin.tie(0);
    ll t = 1;
    cin >> t;
    FOR(tt, t) solve();
    return 0;
}