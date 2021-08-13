#include <bits/stdc++.h>
using namespace std;

#define int int64_t
const int mod = 1e9 + 7; const int INF = 1e18L + 5; const int N = 2e5 + 5;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    
    int dr[] = {-2, -2, 2, 2, -1, -1, 1, 1};
    int dc[] = {-1, 1, -1, 1, -2, 2, -2, 2};

    vector<vector<int>> d(n, vector<int>(n, INF));
    queue<pair<int, int>> q;
    q.emplace(r1, c1);
    d[r1][c1] = 0;

    auto e = [&](int r, int c) {
        return 0 <= r && r < n && 0 <= c && c < n;  
    };

    while(!q.empty()) {
        auto [r, c] = q.front();
        q.pop();
        
        for(int dir = 0; dir < 8; dir++) {
            int nr = r + dr[dir];
            int nc = c  + dc[dir];
            
            if(e(nr, nc) && d[r][c] + 1 < d[nr][nc]) {
                q.emplace(nr, nc);
                d[nr][nc] = d[r][c] + 1;
            }
        }    
    }
    
    cout << (d[r2][c2] >= INF ? -1 : d[r2][c2]) << '\n';
    
    return 0;
}