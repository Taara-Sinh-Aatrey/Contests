/**
 *    author:  Taara Sinh Aatrey
 *    created: 11.09.2022 21:24:13
**/

#include "bits/stdc++.h"

using namespace std;

#ifdef AATREY_DEBUG
#include "debug.hpp"
#else
#define dbg(...)
#endif

#define int int64_t

struct pt {
    double x, y;
};

int orientation(pt a, pt b, pt c) {
    double v = a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y);
    if (v < 0) return -1; // clockwise
    if (v > 0) return +1; // counter-clockwise
    return 0;
}

bool cw(pt a, pt b, pt c, bool include_collinear) {
    int o = orientation(a, b, c);
    return o < 0 || (include_collinear && o == 0);
}
bool collinear(pt a, pt b, pt c) { return orientation(a, b, c) == 0; }

void convex_hull(vector<pt>& a, bool include_collinear = false) {
    pt p0 = *min_element(a.begin(), a.end(), [](pt a, pt b) {
        return make_pair(a.y, a.x) < make_pair(b.y, b.x);
    });
    sort(a.begin(), a.end(), [&p0](const pt& a, const pt& b) {
        int o = orientation(p0, a, b);
        if (o == 0)
            return (p0.x-a.x)*(p0.x-a.x) + (p0.y-a.y)*(p0.y-a.y)
                < (p0.x-b.x)*(p0.x-b.x) + (p0.y-b.y)*(p0.y-b.y);
        return o < 0;
    });
    if (include_collinear) {
        int i = (int)a.size()-1;
        while (i >= 0 && collinear(p0, a[i], a.back())) i--;
        if (a.size() >= i + 2 && i >= -1) {
            int low = i + 1;
            int high = (int) a.size() - 1;
            while (low < high) {
                swap(a[low++], a[high]);
            }
        }
    }

    vector<pt> st;
    for (int i = 0; i < (int)a.size(); i++) {
        while (st.size() > 1 && !cw(st[st.size()-2], st.back(), a[i], include_collinear))
            st.pop_back();
        st.push_back(a[i]);
    }

    a = st;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        cout << "Case #" << tt << ": ";
        int n, k, d;
        cin >> n >> k >> d;
        vector<pt> pts(n);
        for (int i = 0; i < n; i++) {
            cin >> pts[i].x >> pts[i].y;
        }
        convex_hull(pts, false);
        sort(pts.begin(), pts.end(), [&] (auto &a, auto &b) {
            return a.x < b.x;
        });
        n = pts.size();
        const int inf = 1e9 + 5;
        // for (int i = 0; i < n; i++) {
        //     cout << pts[i].x << " " << pts[i].y << endl;
        // }
        vector<int> dp(n, inf);
        dp[0] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                int dx = pts[i].x - pts[j].x;
                int dy = abs(pts[j].y - pts[i].y);
                if (dx > d) break;
                int dis = dx * dx + dy * dy;
                if (dis > d * d) continue;
                // dbg(i, pts[i].x, pts[i].y, j, dis, dp[j] + max(k, dis));
                dp[i] = min(dp[i], dp[j] + max(k, dis));
            }
            // dbg(i, dp[i]);
        }
        cout << (dp.back() < inf ? dp.back() : -1) << '\n';
    }
    return 0;
}