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
	vt<ll> d(n + 1, 0);
	d[0] = 1;
	ll i = 1;
	ll lvl = 0;
	while(i < n){
		ll j = i + 1;
		while(j < n && a[j] > a[j - 1]){
			j++;
		}
		d[lvl + 1] += j - i;
		d[lvl]--;
		if(d[lvl] == 0){
			lvl++;
		}
		i = j;
	}
	if(d[lvl + 1])
		lvl++;
	cout << lvl << '\n';
}

int main()
{
    ios::sync_with_stdio(0);  cin.tie(0);
    ll t = 1;
    cin >> t;
    FOR(tt, t) solve();
    return 0;
}