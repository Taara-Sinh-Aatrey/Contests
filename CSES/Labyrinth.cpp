#include "bits/stdc++.h"
// #define int int64_t
#define input(st,n,vec) for(int i = 0 ; i < n; i++){ cin >> vec[i];}
#define output(vec) for(int i = 0; i < vec.size(); i++){cout << vec[i] << " ";}
using namespace std;

struct info {
    int r, c;
    char dir;
};

vector<string> mat;
vector<vector<bool>> vis;
vector<vector<info>> par;


int32_t main()
{
    int h,w;
    cin >> h >> w;

    mat.resize(h, string(w, '?'));

    vis.resize(h, vector<bool>(w));

    queue<pair<int, int>> q;

    for(int i=0;i<h;i++){

        for(int j=0;j<w;j++){
            cin >> mat[i][j];
            if (mat[i][j] == 'A') {
                q.emplace(i, j);
                vis[i][j] = true;
            }

        }
    }

    const info init = {-1, -1, '?'};

    par.resize(h, vector<info>(w, init));

    auto is_valid = [&] (int r, int c) {
        return 0 <= r && r < h && 0 <= c && c < w && mat[r][c] != '#' && !vis[r][c];
    };

    const int dr[] = {-1, 0, 1, 0};
    const int dc[] = {0, 1, 0, -1};
    const char dd[] = {'U', 'R', 'D', 'L'};

    int R = -1, C = -1;

    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        if (mat[r][c] == 'B') {
            R = r, C = c;
            break;
        }

        for (int dir = 0; dir < 4; dir++) {
            int nr = r + dr[dir];
            int nc = c + dc[dir];
            if (is_valid(nr, nc)) {
                vis[nr][nc] = true;
                par[nr][nc] = {r, c, dd[dir]};
                q.emplace(nr, nc);
            }
        }
    }

    if (R == -1 && C == -1) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";

    string path = "";
    while (mat[R][C] != 'A') {
        auto [nr, nc, dir] = par[R][C];
        path += dir;
        tie(R, C) = make_tuple(nr, nc);
    }

    reverse(path.begin(), path.end());

    cout << path.size() << "\n" << path << '\n';


}