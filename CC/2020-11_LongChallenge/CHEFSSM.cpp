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

const ll mod = 998244353;
const ll INF = 1e18L + 5;
const ll mxN = 2e5 + 1;

ll n;
vt<ll> a;

ll Pow(ll a, ll b){
    ll res = 1ll;
    assert(b >= 0);
    while(b){
        if(b&1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

void solve(){
	cin >> n;
	a.resize(n);
	ll maxi = INF;
	ll den = 1ll;
	For(i, n){
		cin >> a[i];
		maxi = min(maxi, a[i] / 2);
		den = (den * (a[i] + 1) % mod) % mod;
	}
	ll ans = 0;
	FOR(val, maxi){
		ll tot = 1ll, grt = 1ll;
		For(i, n){
			tot = (tot * (a[i] + 1 - 2 * val)) % mod;
			grt = (grt * (a[i] + (val == maxi && a[i] % 2 == 0 ? 2 : 1) - 2 * (val + 1))) % mod;
		}
		ll cur = (tot - grt + mod) % mod;
		cur = (cur * val) % mod;
		ans = (ans + cur) % mod;
	}
	ans = (ans * Pow(den, mod - 2)) % mod;
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