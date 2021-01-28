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
ll n, k;
string s;

void solve(){
	cin >> n >> k >> s;
	ll ans = 0;
	ll pre = 0, suf = 0;
	ll i = 0;
	while(i < n && s[i] != 'W'){
		i++;
		pre++;
	}
	vt<ll> inter;
	while(i < n){
		ans++;
		ll j = i + 1;
		while(j < n && s[j] != 'L'){
			ans += 2;
			j++;
		}
		ll cur = 0;
		while(j < n && s[j] != 'W'){
			j++;
			cur++;
		}
		if(j < n)
			inter.pb(cur);
		else
			suf = cur;
		i = j;
	}
	sort(all(inter));
	for(ll gap: inter){
		ll cur = min(gap, k);
		ans += 2 * cur;
		if(cur == gap){
			ans++;
		}
		k -= cur;
		if(k == 0)
			break;
	}
	ll cur = min(suf, k);
	k -= cur;
	ans += 2 * cur;

	cur = min(pre, k);
	k -= cur;
	ans += max(0ll, 2 * cur - 1);
	if(pre < n && cur){
		ans++;
	}
	cout << ans << '\n';
}

int main()
{
// #ifndef ONLINE_JUDGE
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
// #endif
    ll t = 1;
    cin >> t;
    FOR(tt, t) solve();
    return 0;
}