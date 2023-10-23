/**
 *    author:  Taara Sinh Aatrey
 *    created: 21.08.2022 18:37:55
**/

#include "bits/stdc++.h"

using namespace std;

#ifdef AATREY_DEBUG
#include "debug.hpp"
#else
#define dbg(...)
#endif

#define int int64_t
 
inline int gilbertOrder(int x, int y, int pow, int rotate) {
    if (pow == 0) {
        return 0;
    }
    int hpow = 1 << (pow-1);
    int seg = (x < hpow) ? (
        (y < hpow) ? 0 : 3
    ) : (
        (y < hpow) ? 1 : 2
    );
    seg = (seg + rotate) & 3;
    const int rotateDelta[4] = {3, 0, 0, 1};
    int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
    int nrot = (rotate + rotateDelta[seg]) & 3;
    int subSquareSize = 1LL << (2 * pow - 2);
    int ans = seg * subSquareSize;
    int add = gilbertOrder(nx, ny, pow-1, nrot);
    ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
    return ans;
}
 
struct Query {
    int ty, l, r, idx;
    vector<int> rep;
    int ord;
 
    inline void calcOrder() {
        ord = gilbertOrder(l, r, 21, 0);
    }
};
 
inline bool operator<(const Query &a, const Query &b) {
    return a.ord < b.ord;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<Query> Q(q);
    vector<int> answer(q);
    for(int i = 0; i < q; i++) {
        int ty, l, r;
        cin >> ty >> l >> r, --l, --r;
        int s, t, u;
        if (ty == 2) {
            cin >> s >> t >> u;
        }
        Q[i].l = l;
        Q[i].r = r;
        Q[i].idx = i;
        Q[i].ty = ty;
        Q[i].rep = {s, t, u};
        Q[i].calcOrder();
    }
 
    sort(Q.begin(), Q.end());
 
    int curL = Q[0].l, curR = Q[0].l - 1;
    vector<vector<int>> prs(3, vector<int>(3));
    vector<int> cnt(3, 0);
    
    auto add = [&] (int x, bool is_left) {
        for (int y = 0; y < 3; y++) {
            if (x == y) continue;
            if (is_left) {
                prs[x][y] += cnt[y];
            }
            else {
                prs[y][x] += cnt[y];
            }
        }
        cnt[x]++;
    };

    auto remove = [&] (int x, bool is_left) {
        for (int y = 0; y < 3; y++) {
            if (x == y) continue;
            if (is_left) {
                prs[x][y] -= cnt[y];
            }
            else {
                prs[y][x] -= cnt[y];
            }
        }
        cnt[x]--;
    };
 
    for(int i = 0; i < q; i++) {

        // make sure that add operation is completed before remove

        int l = Q[i].l, r = Q[i].r, ty = Q[i].ty;
        while (curL > l) {
            curL--;
            add(a[curL], true);
        }
        while (curR < r) { 
            curR++;
            add(a[curR], false);
        }
        while (curL < l) {
            remove(a[curL], true);
            curL++;
        }
        while (curR > r) { 
            remove(a[curR], false);
            curR--;
        }
        if (ty == 2) {
            vector<vector<int>> nprs(3, vector<int>(3));
            vector<int> ncnt(3, 0);
            for (int x = 0; x < 3; x++) {
                ncnt[Q[i].rep[x]] = cnt[x];
                for (int y = 0; y < 3; y++) {
                    nprs[Q[i].rep[x]][Q[i].rep[y]] = prs[x][y];
                }
            }
            swap(prs, nprs);
            swap(cnt, ncnt);
        }
        dbg(l, r);
        dbg(cnt);
        dbg(prs);
        answer[Q[i].idx] = prs[1][0] + prs[2][0] + prs[2][1];
    }

    for (int i = 0; i < q; i++) {
        if (Q[i].ty == 1)
            cout << answer[i] << '\n';
    }
    
    return 0;
}