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
	ll sum = accumulate(all(a), 0);
	if(sum == 0){
		cout << "NO\n";
	}else if(sum > 0){
		sort(all(a));
		reverse(all(a));
		cout << "YES\n";
		For(i, n){
			cout << a[i] << ' ';
		}
		cout << '\n';
	}else{
		sort(all(a));
		cout << "YES\n";
		For(i, n){
			cout << a[i] << ' ';
		}
		cout << '\n';
	}
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