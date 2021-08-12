#include <bits/stdc++.h>
using namespace std;

#define int int64_t
const int mod = 1e9 + 7; const int INF = 1e18L + 5; const int N = 2e5 + 5;

int largestSubgrid(vector<vector<int>>& grid, int k){
    int n = grid.size();
    vector<vector<int>> prefix(n,vector<int>(n,0));
    
    auto find = [&] (int row, int col) {
        if(row < 0 || col < 0) {
            return int(0);
        }
        return prefix[row][col];
    };
    
    auto sum_r = [&] (int row1, int col1, int row2, int col2) {
        return find(row2,col2) - find(row1-1,col2) - find(row2,col1-1) + find(row1-1,col1-1);
    };

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            prefix[i][j] = find(i-1,j) + find(i,j-1) - find(i-1,j-1) + grid[i][j];
        }
    }
    
    int low = 0, high = n, ans = 0;
    while(low <= high){
        int mid = low + (high - low)/2;
        
        if(mid == 0) {
            return 0;
        }
        
        bool ruko = false;
        for(int i = mid - 1; i < n && !ruko; i++){
            for(int j = mid - 1; j < n && !ruko; j++){
                int ss = sum_r(i - mid + 1, j - mid + 1, i, j);
                if(ss > k){
                    ruko = true;
                }
            }
        }
        
        if(ruko){
            high = mid - 1;
        }
        else{
            ans = mid;
            low = mid + 1;
        }
    }
    
    return ans;
}

signed main() {
    
}