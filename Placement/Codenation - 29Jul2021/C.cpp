/**
 *    author:  Taara Sinh Aatrey
 *    created: 29.07.2021 17:16:14
**/

#include <bits/stdc++.h>
using namespace std;

template<typename A, typename B> istream& operator>>(istream &is, pair<A, B> &p) { return is >> p.first >> p.second;} template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> istream& operator>>(istream &is, T_container &v) { for (T& x : v) is >> x; return is;} bool debug;
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return debug ? os << '(' << p.first << ", " << p.second << ')' : os << p.first << " " << p.second;} template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { if(debug) { os << "{"; string sep; for (const T &x : v) os << sep << x, sep = ", "; os << '}'; } else { bool f = false; for (const T &x : v) { if(f) {os << " ";} os << x, f = true; } } return os;}
template <typename T, typename T1, typename... Tail> T amin(T& a, T1 b, Tail... c) { if(b < a) a = b; if constexpr (sizeof...(c) != 0) { amin(a, c...); } return a; } template <typename T, typename T1, typename... Tail> T amax(T& a, T1 b, Tail... c) { if(b > a) a = b; if constexpr (sizeof...(c) != 0) { amax(a, c...); } return a; }
void dbg_out() { cerr << endl; } template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef ONLINE_JUDGE
#define dbg(...)
#else
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]:", debug = true, dbg_out(__VA_ARGS__), debug = false
#endif

#define int int64_t
const int mod = 1e9 + 7; const int INF = 1e18L + 5; const int N = 1e6 + 5;

int intime[N], outtime[N], nodeAt[2 * N];
vector<vector<int>> g;
 
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
    int l, r, idx;
    int ord;
 
    inline void calcOrder() {
        ord = gilbertOrder(l, r, 21, 0);
    }
};
 
inline bool operator<(const Query &a, const Query &b) {
    return a.ord < b.ord;
}
 
int timer = 0;  
 
void dfs(int u, int par) {
    nodeAt[timer] = u;
    intime[u] = timer++;
    for(int v: g[u]) {
        if(v != par) {
            dfs(v, u);
        }
    }
    nodeAt[timer] = u;
    outtime[u] = timer++;
}

vector<int> solve(int n, vector<vector<int>>& b, vector<int>& c) {
    
    vector<int> ans(n);
    g.resize(n);
    
    for (auto &i : b) {
        g[i[0]].push_back(i[1]);
        g[i[1]].push_back(i[0]);
    }
    
    dfs(0, -1);
    
    Query q[n];

    for(int u = 0; u < n; u++) {
        q[u].l = intime[u];
        q[u].r = outtime[u];
        dbg(intime[u], outtime[u]);
        q[u].idx = u;
        q[u].calcOrder();
    }
 
    sort(q, q + n);
 
    int curL = q[0].l, curR = q[0].l - 1;
    multiset<int> st;
    for(int i = 0; i <= n; i++) {
        st.insert(i);
    }
 
    auto add = [&](int x) {
        x = nodeAt[x];
        auto it = st.find(c[x]);
        if(it != st.end()) {
            st.erase(it);
        }
    };

    auto remove = [&](int x) {
        x = nodeAt[x];
        st.insert(c[x]);
    };
 
    for(int i = 0; i < n; i++) {

        // make sure that add operation is completed before remove

        int l = q[i].l, r = q[i].r;
        while(curL < l) {
            remove(curL);
            curL++;
        }
        while(curR > r) { 
            remove(curR);
            curR--;
        }
        while(curL > l) {
            curL--;
            add(curL);
        }
        while(curR < r) { 
            curR++;
            add(curR);
        }
        dbg(l, r, st);
        ans[q[i].idx] = *st.begin();
    }
    
    return ans;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<vector<int>> b(n - 1, vector<int>(2));
    cin >> b;
    vector<int> c(n);
    cin >> c;
        
    cout << solve(n, b, c) << endl;
    
    return 0;
}