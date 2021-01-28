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

ll n, m;

void solve(ll tt){
	cin >> n >> m;
	ll a[n][m];
	For(i, n){
		string s;
		cin >> s;
		For(j, m){
			a[i][j] = s[j] - '0';
		}
	}
	vt<vt<ll>> print;
	For(i, n - 1){
		For(j, m){
			if(i == n - 2 && j >= m - 2)
				break;
			vt<ll> vec;
			if(j + 1 == m){
				if(a[i][j]){
					vec.pb(i); vec.pb(j);
					vec.pb(i + 1); vec.pb(j);
					vec.pb(i + 1); vec.pb(j - 1);
					print.pb(vec);
					for(int i = 0; i + 1 < sz(vec); i += 2){
						a[vec[i]][vec[i + 1]] = 1 - a[vec[i]][vec[i + 1]];
					}
				}
				continue;
			}
			for(int x: {i, i + 1}){
				if(a[x][j]){
					vec.pb(x);
					vec.pb(j);
				}
			}
			if(vec.empty()){
				continue;
			}
			for(int x: {i, i + 1}){
				vec.pb(x);
				vec.pb(j + 1);
				if(sz(vec) == 6){
					break;
				}
			}
			print.pb(vec);
			for(int i = 0; i + 1 < sz(vec); i += 2){
				a[vec[i]][vec[i + 1]] = 1 - a[vec[i]][vec[i + 1]];
			}
		}
	}
	vt<ar> one, zero;
	for(int i: {n - 2, n - 1}){
		for(int j: {m - 2, m - 1}){
			if(a[i][j]){
				one.pb({i, j});
			}else{
				zero.pb({i, j});
			}
		}
	}
	if(sz(one) == 1){
		print.pb({one[0][0], one[0][1], zero[0][0], zero[0][1], zero[1][0], zero[1][1]});
		print.pb({one[0][0], one[0][1], zero[1][0], zero[1][1], zero[2][0], zero[2][1]});
		print.pb({one[0][0], one[0][1], zero[2][0], zero[2][1], zero[0][0], zero[0][1]});
	}else if(sz(one) == 2){
		print.pb({one[0][0], one[0][1], zero[1][0], zero[1][1], zero[0][0], zero[0][1]});
		print.pb({one[1][0], one[1][1], zero[1][0], zero[1][1], zero[0][0], zero[0][1]});
	}else if(sz(one) == 3){
		print.pb({one[0][0], one[0][1], one[1][0], one[1][1], one[2][0], one[2][1]});
	}else if(sz(one) == 4){
		print.pb({one[0][0], one[0][1], one[1][0], one[1][1], one[2][0], one[2][1]});
		auto x = one.back();
		one.pop_back();
		zero = one;
		one.clear();
		one.pb(x);
		print.pb({one[0][0], one[0][1], zero[0][0], zero[0][1], zero[1][0], zero[1][1]});
		print.pb({one[0][0], one[0][1], zero[1][0], zero[1][1], zero[2][0], zero[2][1]});
		print.pb({one[0][0], one[0][1], zero[2][0], zero[2][1], zero[0][0], zero[0][1]});
	}
	cout << sz(print) << '\n';
	for(auto p: print){
		// assert(sz(p) == 6);
		for(auto ele: p){
			cout << ele + 1 << " ";
		}
		cout << '\n';
	}
}

int main()
{
    ios::sync_with_stdio(0);  cin.tie(0);
    ll t = 1;
    cin >> t;
    FOR(tt, t) solve(tt);
    return 0;
}