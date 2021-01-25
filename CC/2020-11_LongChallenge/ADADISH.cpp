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

ll n;
vt<ll> a;

void solve(){
	cin >> n;
	a.resize(n);
	ll sum = 0;
	For(i, n){
		cin >> a[i];
		sum += a[i];
	}
	ll ans = INF;
	for(ll i = 0; i < (1 << n); i++){
		ll s = 0;
		for(ll j = 0; j < n; j++){
			if((i & (1 << j)) == 0)
				continue;
			s += a[j];
		}
		ans = min(ans, max(s, sum - s));
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