/**
 *    author:  Taara Sinh Aatrey
 *    created: 21.08.2022 17:38:56
**/

#include "bits/stdc++.h"

using namespace std;

#ifdef AATREY_DEBUG
#include "debug.hpp"
#else
#define dbg(...)
#endif

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    for (int row = 0; row < h; row++) {
        cin >> s[row];
    }
    set<pair<int, int>> vis;
    int r = 0, c = 0;
    while (!vis.count({r, c})) {
        vis.emplace(r, c);
        char &ch = s[r][c];
        int pr = r, pc = c;
        if (ch == 'U') {
            r--;
        }
        else if (ch == 'D') {
            r++;
        }
        else if (ch == 'L') {
            c--;
        }
        else {
            c++;
        }
        if (r < 0 || r >= h || c < 0 || c >= w) {
            cout << pr+1 << " " << pc+1;
            return 0;
        }
    }
    cout << -1 << '\n';
    return 0;
}