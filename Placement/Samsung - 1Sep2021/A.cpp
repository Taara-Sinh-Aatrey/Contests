#include <bits/stdc++.h>
using namespace std;

#define int int64_t
const int INF = 1e18L + 5;

void solve() {
    
    int n, m, k, h;
    cin >> n >> m >> k >> h;
    
    vector<vector<vector<int>>> a(5, vector<vector<int>>(n, vector<int>(m, INF)));
    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> PQ[5];
    for(int i = 0; i < k; i++) {
        int r, c, w;
        cin >> r >> c >> w, --r, --c;
        PQ[w - 1].push({0, r, c});
        a[w - 1][r][c] = 0;
    }
    
    for(int i = 0; i < h; i++) {
        int r, c;
        cin >> r >> c, --r, --c;
        for(int w = 0; w < 5; w++) {
            a[w][r][c] = -1;
        }
    }
    
    
    for(int w = 1; w <= 5; w++) {
        
        auto& pq = PQ[w - 1];
        if(pq.empty()) continue;
        
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, -1, 0, 1};
        
        auto e = [&](int r, int c) {
            return 0 <= r && r < n && 0 <= c && c < m && a[w - 1][r][c] != -1;  
        };
        
        int ans = 0;    
        while(!pq.empty()) {
            auto [d, r, c] = pq.top();
            pq.pop();
            
            if(a[w - 1][r][c] > d) {
                continue;
            }
                        
            for(int dir = 0; dir < 4; dir++) {
                int nr = r + dr[dir];
                int nc = c  + dc[dir];
                
                if(e(nr, nc) && a[w - 1][r][c] + w < a[w - 1][nr][nc]) {
                    a[w - 1][nr][nc] = a[w - 1][r][c] + w;
                    pq.push({a[w - 1][nr][nc], nr, nc});
                }
            }    
        }
        
    }
    
    int ans = 0;
    for(int r = 0; r < n; r++) {
        for(int c = 0; c < m; c++) {
            if(a[0][r][c] == -1) continue;
            int mn = INF;
            for(int w = 0; w < 5; w++) {
                mn = min(mn, a[w][r][c]);
            }
            ans = max(ans, mn);
        }
    }
    cout << (ans < INF ? ans : -1) << '\n';
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        cout << "#" << tt << ": ";
        solve();
    }
    
    return 0;
}