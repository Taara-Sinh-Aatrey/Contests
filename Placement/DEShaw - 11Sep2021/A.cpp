#include "bits/stdc++.h"
using namespace std;

string reachTheEnd(vector<string> grid, int k) {
    int n = grid.size(), m = grid[0].size();
    
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, -1, 0, 1};
    
    vector<vector<int>> d(n, vector<int>(m, k + 1));
    queue<pair<int, int>> q;
    q.emplace(0, 0);
    d[0][0] = 0;
    
    auto e = [&](int r, int c) {
        return 0 <= r && r < n && 0 <= c && c < m && grid[r][c] == '.';  
    };
    
    while(!q.empty()) {
        auto [r, c] = q.front();
        q.pop();
        
        for(int dir = 0; dir < 4; dir++) {
            int nr = r + dr[dir];
            int nc = c  + dc[dir];
            
            if(e(nr, nc) && d[r][c] + 1 < d[nr][nc]) {
                q.emplace(nr, nc);
                d[nr][nc] = d[r][c] + 1;
            }
        }    
    }
    
    return (d[n - 1][m - 1] <= k ? "Yes" : "No");
}

signed main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cout << reachTheEnd({"..##", "#.##", "#..."}, 5) << endl;

    return 0;
}