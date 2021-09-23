#include "bits/stdc++.h"
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        cout << "#" << tt << " ";
        int n;
        cin >> n;
        vector<vector<int>> a(n, vector<int>(n, 0));
        for (int it = 0; it < 2; it++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    int x;
                    cin >> x;
                    a[i][j] ^= x;
                }
            }
        }
        vector<vector<int>> init(n, vector<int>(n, 0));
        int N = n * n;
        const int dr[] = {-1, 0, 1, 0};
        const int dc[] = {0, 1, 0, -1};
        int ans = N;
        for (int mask = 0; mask < 1 << N; mask++) {
            auto b = a;
            for (int i = 0; i < N; i++) {
                if(!(mask >> i & 1)) continue;
                int r = i / n, c = i % n;
                b[r][c] ^= 1;
                for (int dir = 0; dir < 4; dir++) {
                    int nr = r + dr[dir]; 
                    int nc = c + dc[dir]; 
                    if(nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
                    b[nr][nc] ^= 1;
                }
            }
            if (b == init) {
                ans = min<int>(ans, __builtin_popcount(mask));
            }
        }
        cout << ans << '\n';
    }
    return 0;
}