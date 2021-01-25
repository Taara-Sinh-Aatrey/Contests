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
	vt<ll> pref(n, 0);
	int one = -1;
	For(i, n){
		cin >> a[i];
		if(a[i] == 1)
			one = i;
		if(i > 0)
			pref[i] = pref[i - 1];
		if(i < n - 1)
			pref[i] += a[i] - a[i] % 2;
		else
			pref[i] += a[i] - (a[i] + 1) % 2;
		pref[i] %= mod;
	}


	ll _;
	cin >> _;
	while(_--){
		ll turns;
		cin >> turns;
		ll rem = turns % n, q = (turns / n) % mod;
		ll ans;
		if(one == 0){
			ans = q + (rem > 1 || q == 0);
			ans %= mod;
		}else if(one == n - 1){
			ans = pref[n - 1] * q;
			ans %= mod;
			if(rem){
				ans += pref[rem - 1];
				if(a[rem - 1] & 1)
					ans++;
			}else if(a[n - 1] % 2 == 0){
				ans++;
			}
			ans %= mod;
		}else if(one >= 0){
			ans = (pref[n - 1] + (a[one - 1] % 2 == 1 ? 1: -1)) * q;
			ans %= mod;
			if(rem){
				if(rem - 1 <= one){
					ans += pref[rem - 1];
				}else{
					ans += (pref[rem - 1] + (a[one - 1] % 2 == 1 ? 1: -1));
				}
				if(a[rem - 1] & 1)
					ans++;
			}else if(a[n - 1] % 2 == 0){
				ans++;
			}
			ans %= mod;
		}else{
			ans = pref[n - 1] * q;
			ans %= mod;
			if(rem){
				ans += pref[rem - 1];
				if(a[rem - 1] & 1)
					ans++;
			}else if(a[n - 1] % 2 == 0){
				ans++;
			}
			ans %= mod;
		}
		cout << ans << '\n';
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
