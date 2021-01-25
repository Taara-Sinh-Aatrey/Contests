#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define in insert
#define pb emplace_back
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vi>
#define For(i,a,b) for(int i=a;i<=b;i++)
#define Rev(i,a,b) for(ll i=a;i>=b;i--)
#define Rbl(x,a) for(auto &x : a)
#define FIO ios::sync_with_stdio(0);   cin.tie(0);
#define F first
#define S second
#define pii pair<int,int>
#define mp make_pair
#define vpii vector<pii>
#define mod 998244353
#define INF 1e9
// cin >> s1 >> s2;
// cout << s1 << " " << s2;
// cout << s1 << "\n" << s2;
// int len = s.length;


void solve()
{   
    int t,c1,c2,c3,a1,a2,a3,a4,a5,r1,r2,r3 ;
    cin >> c1 >> c2 >> c3 ;
    cin >> a1 >> a2 >> a3 >> a4 >> a5 ;
    if(a1<=c1)
    	r1 = c1 - a1 ;
    else
    	{
    		cout<< "NO" << endl ;
    		return;
    	}		
    if(a2<=c2)
    	r2 = c2 - a2 ;
    else
    	{
    		cout<< "NO" << endl ;
    		return;
    	}		
    if(a3<=c3)
    	r3 = c3 - a3 ;
    else
    	{
    		cout<< "NO" << endl ;
    		return;
    	}	
    if(a4>r1+r3)
    {
    	cout<< "NO" << endl ;
    	return;
    }    	
    if(a5>r2+r3)
    {
    	cout<< "NO" << endl ;
    	return;
    }    	
    if(a4+a5<=r1+r2+r3)
        cout<< "YES" << endl ;
    else
        cout << "NO" << endl ;

}	


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;
    
    cin >> t ;
    for(int i = 1 ; i<=t ; i++)
    {
    	solve();
    }
    
}