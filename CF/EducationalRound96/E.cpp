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
string s;

vt<ll> BIT;

void upd(ll ind, ll val, ll N){
	while(ind <= N){
		BIT[ind] += val;
		ind += ind & (-ind);
	}
}

ll get(ll ind){
	ll ret = 0;
	while(ind > 0){
		ret += BIT[ind];
		ind -= ind & (-ind);
	}
	return ret;
}

void solve(){
	cin >> n >> s;
	string t = s;
	reverse(all(t));
	vt<vt<ll>> src(26);
	For(i, n){
		src[s[i] - 'a'].pb(i);
	}
	ll ans = 0;
	BIT = vt<ll>(n + 1, 0);
	for(ll i = n - 1; i >= 0; i--){
		ll j = src[t[i] - 'a'].back();
		src[t[i] - 'a'].pop_back();
		ll offset = get(j + 1);
		assert(j - offset <= i);
		ans += i - (j - offset);
		upd(j + 1, 1, n);
	}
	cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(0);  cin.tie(0);
    ll t = 1;
    solve();
    return 0;
}