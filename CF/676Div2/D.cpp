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
ll x, y;
ll c[7];

void solve(){
	cin >> x >> y;
	FOR(i, 6) cin >> c[i];
	ll ans;
	if((x >= 0) == (y >= 0)){
		if(x >= 0){
			ll m = min(x, y);
			ll M = max(x, y);
			ans = min(m * min(c[1], c[6] + c[2]) + (x - m) * c[6] + (y - m) * c[2], M * min(c[1], c[6] + c[2]) + (M - x) * c[3] + (M - y) * c[5]);
		}else{
			x = -x;
			y = -y;
			ll m = min(x, y);
			ll M = max(x, y);
			ans = min(m * min(c[4], c[3] + c[5]) + (x - m) * c[3] + (y - m) * c[5], M * min(c[4], c[3] + c[5]) + (M - x) * c[6] + (M - y) * c[2]);
		}
	}else{
		if(x >= 0){
			assert(y < 0);
			y = -y;
			ans = x * c[6] + y * c[5];
			ans = min(ans, x * c[1] + (x + y) * c[5]);
			ans = min(ans, y * c[4] + (x + y) * c[6]);
		}else{
			assert(y >= 0);
			x = -x;
			ans = x * c[3] + y * c[2];
			ans = min(ans, x * c[4] + (x + y) * c[2]);
			ans = min(ans, y * c[1] + (x + y) * c[3]);
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