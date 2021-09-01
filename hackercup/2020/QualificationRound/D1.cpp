#include<bits/stdc++.h>
using namespace std;
#define ll long long

int n, m;
vector<long long> dp(1000001, 0);
vector<long long> arr(1000001, 0);

int main()
{
    ios::sync_with_stdio(0);   
    cin.tie(0);

    ll t;   
    cin >> t;
    for(int tt = 1; tt <= t; tt++)
    {
        cin >> n >> m;
        dp[1] = 0;
        for(int i = 1; i <= n; i++)
        {
            cin >> arr[i];
        }
        priority_queue<array<ll, 2>, vector<array<ll, 2>>, greater<array<ll, 2>>> q;
        q.push({0, 1});
        int i;
        for(i = 2; i <= n; i++)
        {
            while(true)
            {
                if(q.empty())
                    break;
                array<ll, 2> temp = q.top();
                if(temp[1] >= i-m)
                    break;
                q.pop();
            }
            if(q.empty())
                break;
            else
            {
                array<ll, 2> temp = q.top();
                dp[i] = temp[0];
            }
            if(arr[i] > 0)
            { 
                array<ll, 2> temp;
                temp[0] = dp[i] + arr[i];
                temp[1] = i;
                q.push(temp);
            }
        }      
        cout << "Case #" << tt << ": ";
        if(i > n) cout << dp[n] << endl;
        else cout << -1 << endl; 
    }
    
    return 0;
}