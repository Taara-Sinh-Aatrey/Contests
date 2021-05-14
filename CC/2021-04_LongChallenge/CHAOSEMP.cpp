#include<bits/stdc++.h>
using namespace std;

#define int long long


int Q, D;

const int INF = 1e18L;

void solve(int tt) {
    int q = 0;
    auto qry1 = [&](int x, int y) {
        q++;
        assert(q <= Q);
        cout << 1 << " " << x << " " << y << endl;
        string s = "";
        cin >> s;
        return s;
    };

    auto qry2 = [&](int x1, int y1, int x2, int y2) {
        q++;
        assert(q <= Q);
        cout << 2 << " " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
        string s;
        cin >> s;
        return s;
    };

    int lx = -1e18, hx = 1e18, ly = -1e18, hy = 1e18;

    while(lx <= hx && ly <= hy) {

        if(D == 1 && hx - lx <= 3 && hy - ly <= 3) {
            break;
        }

        int mx = lx + (hx - lx + 1) / 2, my = ly + (hy - ly + 1) / 2;
        auto s = qry1(mx, my);
        if(s == "O") {
            return;
        }
        if(s[0] == 'X') {
            lx = mx - 1, hx = mx + 1;
        }
        if(s[0] == 'N') {
            lx = mx;
            hx++;
        }
        if(s[0] == 'P') {
            hx = mx;
            lx--;
        }
        if(s[1] == 'Y') {
            ly = my - 1, hy = my + 1;
        }
        if(s[1] == 'N') {
            ly = my;
            hy += 1;
        }
        if(s[1] == 'P') {
            hy = my;
            ly -= 1;
        }
    }

    if(hx - lx == 3) {
        auto s = qry2(lx + 1, ly, hx, hy);
        if(s == "O") {
            return;
        }
        if(s == "IN") {
            lx += 1;
        } else {
            hx = lx + 1;
            lx -= 1;
        }
    }
    assert(hx - lx == 2);

    if(hy - ly == 3) {
        auto s = qry2(lx, ly + 1, hx, hy);
        if(s == "O") {
            return;
        }
        if(s == "IN") {
            ly += 1;
        } else {
            hy = ly + 1;
            ly -= 1;
        }
    }

    assert(hy - ly == 2);

    assert(qry2(lx, ly, hx, hy) == "O");

}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t >> Q >> D;

    for(int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
    

    return 0;
}

