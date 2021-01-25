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

void solve(){
	cin >> n;
	ll num = 1, den = 1;
	For(i, n/2){
		num *= (n - i);
		den *= (i + 1);
	}
	ll ans = num / den;
	ans *= (2 * den / n) * (2 * den / n);
	ans /= 2;
	cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(0);  cin.tie(0);
    solve();
    return 0;
}