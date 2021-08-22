/**
 *    author:  Taara Sinh Aatrey
 *    created: 18.08.2021 11:36:45
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
const int mod = 1e9 + 7; const int INF = 1e18L + 5; const int N = 2e5 + 5;

class fenwick {
public:
    int n;
    vector<int> tree;
    // original array should follow 0 based indexing
    fenwick() {

    }

    fenwick(int _n) {
        n = _n;
        tree.resize(n + 1, 0);
    }

    fenwick(vector<int>& arr) {
        n = arr.size();
        tree.resize(n + 1, 0);
        for(int i = 0; i < n; i++) {
            modify(i, arr[i]);
        }
    }

    void modify(int idx, int val) {
        idx += 1;
        while(idx <= n) {
            tree[idx] += val;
            idx += idx & (-idx);
        }
    } 

    int get(int idx) {
        idx += 1;
        int ret = 0;
        while(idx > 0) {
            ret += tree[idx];
            idx -= idx & (-idx);
        }
        return ret;
    }
};

void solve() {
    
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    cin >> a;
    a.emplace_back(INF);
    
    a.insert(a.begin(), 0);
    vector<int> pref(n + 2);
    for(int i = 1; i <= n + 1; i++) {
        pref[i] = pref[i - 1] + a[i];
    }
    
    vector<vector<pair<int, int>>> Q(n + 1);
    vector<int> ans(q);
    for(int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        Q[l].emplace_back(r, i);        
    }
    
    fenwick cont(n + 1);
    vector<int> cnt(n + 1);
    deque<int> dq{n + 1};
    for(int i = n; i >= 1; i--)  {
        while(!dq.empty() && a[dq.front()] <= a[i]) {
            cont.modify(dq.front(), -cnt[dq.front()]);
            cnt[dq.front()] = 0;
            dq.pop_front();
        }
        
        int j = dq.front();
        dq.push_front(i);
        cnt[i] = (j - 1 - i) * a[i] - (pref[j - 1] - pref[i]);
        cont.modify(i, cnt[i]);
        
        for(auto& [j, idx] : Q[i]) {
            int k = upper_bound(dq.begin(), dq.end(), j) - dq.begin() - 1;
            ans[idx] = cont.get(dq[k] - 1) + (j - dq[k]) * a[dq[k]] - (pref[j] - pref[dq[k]]); 
        }
        
    }
    
    for(int i = 0; i < q; i++) {
        cout << ans[i] << '\n';
    }
    
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;

    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
    
    return 0;
}