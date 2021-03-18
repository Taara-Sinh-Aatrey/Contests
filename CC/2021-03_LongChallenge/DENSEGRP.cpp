#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n, m, x, y;
        cin >> n >> m >> x >> y;

        map<pair<int, int>, vector<pair<int, int>>> g;
        queue<pair<pair<int, int>, int>> qu;

        {
            int a, b, c, d;
            while(m--) {
                cin >> a >> b >> c >> d;
                if(a <= x && x <= b) {
                    qu.push({{c, d}, 1});
                } else {
                    g[{a, b}].emplace_back(c, d);
                }
            }
        }

        if(x == y) {
            cout << 0 << '\n';
            continue;
        }

        bool reached = false;

        while(!qu.empty()) {
            auto [u, dist] = qu.front();
            qu.pop();
            if(u.first <= y && y <= u.second) {
                cout << dist << '\n';
                reached = true;
                break;
            }
            vector<pair<int, int>> done;
            for(auto it = g.begin(); it != g.end(); it++) {
                auto& [a, b] = it->first;
                if(a > u.second) break;
                if(b < u.first) continue;
                done.emplace_back(a, b);
                for(auto& [c, d] : it->second) {
                    qu.push({{c, d}, dist + 1});
                }
            }
            for(auto& aa : done) {
                g.erase(aa);
            }
        }

        if(!reached) {
            cout << -1 << '\n';
        }
    }

    return 0;
}

/*
905 908
117 127
2
*/