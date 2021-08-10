#include <bits/stdc++.h>
using namespace std;

#define ll long long

long long solve(int N, vector<int> A, int M) {
    
    ll lo = *max_element(A.begin(), A.end()), hi = 1e18;
    
    ll ans = 1e18;
    
    while(lo <= hi) {
        ll mid = (lo + hi) / 2;
        
        int p = 1;
        int cur = A[0];
        
        for(int i = 1; i < N; i++) {
            if(cur + A[i] <= mid) {
                cur += A[i];
            }
            else {
                p++;
                cur = A[i];
            }
        }
        
        if(p > M) {
            lo = mid + 1;
        }
        else {
            ans = mid;
            hi = mid - 1;
        }
    }
    
    return ans;
    
}

signed main()
{
    cout << solve(4, {2, 8, 7, 10}, 3) << endl;
    
    return 0;
}