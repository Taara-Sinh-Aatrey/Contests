#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int H, W, X;
        cin >> H >> W >> X;

        vector<vector<int>> a(H, vector<int>(W));
        for(int i = 0; i < H; i++) {
            for(int j = 0; j < W; j++) {
                cin >> a[i][j];
            }
        }
        {
            int x;
            for(int i = 0; i < H; i++) {
                for(int j = 0; j < W; j++) {
                    cin >> x;
                    a[i][j] -= x;
                }
            }
        }

        for(int i = 0; i < H; i++) {
            for(int j = 0; j < W; j++) {
                if(i + X <= H) {
                    for(int k = X - 1; k >= 0; k--) {
                        a[i + k][j] -= a[i][j];
                    }
                } else if(j + X <= W) {
                    for(int k = X - 1; k >= 0; k--) {
                        a[i][j + k] -= a[i][j];
                    }
                }
            }
        }

        bool ok = true;
        for(int i = 0; i < H; i++) {
            for(int j = 0; j < W; j++) {
                ok = ok & (a[i][j] == 0);
            }
        }

        cout << (ok ? "Yes" : "No") << '\n';
    }
    

    return 0;
}