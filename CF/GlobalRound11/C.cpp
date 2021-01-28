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
ll r, n;
vt<ar> a;

void solve(){
	cin >> r >> n;
	a = vt<ar>(n + 1);
	FOR(i, n){
		cin >> a[i][0] >> a[i][1] >> a[i][2];
	}
	set<array<ll, 2>> s;
	a[0] = {0, 1, 1};
	s.in({0, 0});
	FOR(i, n){
		for(auto it = s.rbegin(); it != s.rend(); it++){
			auto p = *it;
			ll val = p[0], j = p[1];
			if(a[j][0] + abs(a[i][1] - a[j][1]) + abs(a[i][2] - a[j][2]) <= a[i][0]){
				s.in({val + 1, i});
				break;
			}
		}
	}
	ll ans = (*s.rbegin())[0];
	if(ans == 0)
		ans++;
	cout << ans << '\n';
}

int main()
{
// #ifndef ONLINE_JUDGE
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
// #endif
    ll t = 1;
    // cin >> t;
    FOR(tt, t) solve();
    return 0;
}