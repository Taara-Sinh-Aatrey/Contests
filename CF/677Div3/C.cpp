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
	ll M = *max_element(all(a));
	ll ans = -2;
	For(i, n){
		if(a[i] == M){
			bool ok = false;
			if(i && a[i-1] != M){
				ok = true;
			}
			if(i + 1 < n && a[i + 1] != M){
				ok = true;
			}
			if(ok){
				ans = i;
				break;
			}
		}
	}
	cout << ++ans << '\n';
}

int main()
{
// #ifndef ONLINE_JUDGE
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
// #endif
    ios::sync_with_stdio(0);  cin.tie(0);
    ll t = 1;
    cin >> t;
    FOR(tt, t) solve();
    return 0;
}