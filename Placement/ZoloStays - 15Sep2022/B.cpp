#include "bits/stdc++.h"
using namespace std;

int main() {
#define int int64_t
    int n, k;
    cin >> n >> k;
    k = min(k, n);
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<vector<int>> dp(n + 1);
    dp[0] = {0};
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1];
        dp[i].emplace_back(0);
        for (int j = 0; j < i; j++) {
            dp[i][j + 1] = max(dp[i][j + 1], dp[i - 1][j] | a[i]);                   
        }
    }
    cout << *max_element(dp.back().begin(), dp.back().begin() + k + 1) << '\n';
    return 0;
#undef int
}

// #include <bits/stdc++.h>
// using namespace std;

// int64_t dp[1001][1001];

// void solve()
// {
// #define int int64_t

//     int n,k;
//     cin>>n>>k;
//     k = min(k,n);
//     vector<int>arr(n);
//     for(int &i : arr)
//         cin>>i;

//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<=k;j++)
//         {
//             if(i == 0 && j == 1)
//                 dp[i][j] = arr[i];
//             else
//                 dp[i][j] = 0;
//         }
//     }

//     for(int i=1; i<n;i++)
//     {
//         dp[i][0] = 0;
//         for(int j = 1; j<=(i+1);j++)
//         {
//             dp[i][j] = max(dp[i - 1][j], dp[i-1][j-1] | arr[i]);
//         }
//     }
//     int maxi = *max_element(dp[n-1], dp[n-1]+k+1); 
//     cout << maxi << endl;

// #undef int
// }


// int main()
// {

//     solve();

//     return 0;
// }