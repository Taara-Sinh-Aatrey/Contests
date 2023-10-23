int intime[N], outtime[N], nodesAtLevel[N], depth[N], nodeAt[2 * N], answer[N];
vector<vector<int>> g(N);
 
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
    int l, r, idx, d;
    int ord;
 
    inline void calcOrder() {
        ord = gilbertOrder(l, r, 21, 0);
    }
}q[N];
 
inline bool operator<(const Query &a, const Query &b) {
    return a.ord < b.ord;
}
 
int timer = 0;  
 
void dfs(int u) {
    nodeAt[timer] = u;
    intime[u] = timer++;
    for(int v: g[u]){
        depth[v] = 1 + depth[u];
        dfs(v);
    }
    nodeAt[timer] = u;
    outtime[u] = timer++;
}
 
void solve() {
 
    int n, m;
    cin >> n;
    for(int u = 1; u < n; u++) {
        int p;
        cin >> p;
        p--;
        g[p].emplace_back(u);
    }
 
    dfs(0);
 
    cin >> m;
 
    for(int i = 0; i < m; i++) {
        int u, d;
        cin >> u >> d;
        u--;
        q[i].l = intime[u];
        q[i].r = outtime[u];
        q[i].idx = i;
        q[i].d = d;
        q[i].calcOrder();
    }
 
    sort(q, q + m);
 
    int curL = q[0].l, curR = q[0].l - 1;
    int distinct = 0;
 
    auto add = [&](int x) {
        if(cnt[a[x]] == 0) {
            distinct++;
        }
        cnt[a[x]]++;
    };

    auto remove = [&](int x) {
        cnt[a[x]]--;
        if(cnt[a[x]] == 0) {
            distinct--;
        }
    };
 
    for(int i = 0; i < m; i++) {

        // make sure that add operation is completed before remove

        int l = q[i].l, r = q[i].r;
        while(curL > l) {
            curL--;
            add(curL);
        }
        while(curR < r) { 
            curR++;
            add(curR);
        }
        while(curL < l) {
            remove(curL);
            curL++;
        }
        while(curR > r) { 
            remove(curR);
            curR--;
        }
        answer[q[i].idx] = distinct;
    }

    for(int i = 0; i < m; i++) {
        cout << answer[i] << '\n';
    }
}
