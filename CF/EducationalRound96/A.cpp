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
	for(ll k = 0; k * 7 <= n; k++){
		for(ll j = 0; k * 7 + j * 5 <= n; j++){
			ll rem = n - k * 7 - j * 5;
			if(rem % 3 == 0){
				cout << rem / 3 << " " << j << " " << k << '\n';
				return;
			}
		}
	}
	cout << -1 << '\n';
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