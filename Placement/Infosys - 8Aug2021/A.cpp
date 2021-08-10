#include <bits/stdc++.h>
using namespace std;

#define int int64_t
const int mod = 1e9 + 7; const int INF = 1e18L + 5; const int N = 1e6 + 5;

class segtree {
public:
    struct node {
        int mn = INF;

        void apply(int l, int r, int v) {
            mn = v;
        }
    };

    node unite(const node &a, const node &b) const {
        node res;
        res.mn = min(a.mn, b.mn);
        return res;
    }

    inline void push(int x, int l, int r) {
    }

    inline void pull(int x, int z) {
        tree[x] = unite(tree[x + 1], tree[z]);
    }

    int n;
    vector<node> tree;

    void build(int x, int l, int r) {
        if (l == r) {
            return;
        }
        int y = (l + r) >> 1;
        int z = x + ((y - l + 1) << 1);
        build(x + 1, l, y);
        build(z, y + 1, r);
        pull(x, z);
    }
    
    template <typename M>
    void build(int x, int l, int r, const vector<M> &v) {
        if (l == r) {
            tree[x].apply(l, r, v[l]);
            return;
        }
        int y = (l + r) >> 1;
        int z = x + ((y - l + 1) << 1);
        build(x + 1, l, y, v);
        build(z, y + 1, r, v);
        pull(x, z);
    }

    node get(int x, int l, int r, int ll, int rr) {
        if (ll <= l && r <= rr) {
            return tree[x];
        }
        int y = (l + r) >> 1;
        int z = x + ((y - l + 1) << 1);
        push(x, l, r);
        node res{};
        if (rr <= y) {
            res = get(x + 1, l, y, ll, rr);
        } 
        else {
            if (ll > y) {
                res = get(z, y + 1, r, ll, rr);
            } 
            else {
                res = unite(get(x + 1, l, y, ll, rr), get(z, y + 1, r, ll, rr));
            }
        }
        pull(x, z);
        return res;
    }

    template <typename M>
    void modify(int x, int l, int r, int ll, int rr, const M& v) {
        if (ll <= l && r <= rr) {
            tree[x].apply(l, r, v);
            return;
        }
        int y = (l + r) >> 1;
        int z = x + ((y - l + 1) << 1);
        push(x, l, r);
        if (ll <= y) {
            modify(x + 1, l, y, ll, rr, v);
        }
        if (rr > y) {
            modify(z, y + 1, r, ll, rr, v);
        }
        pull(x, z);
    }


    segtree(int _n) : n(_n) {
        assert(n > 0);
        tree.resize(2 * n - 1);
        build(0, 0, n - 1);
    }
    
    template <typename M>
    segtree(const vector<M> &v) {
        n = v.size();
        assert(n > 0);
        tree.resize(2 * n - 1);
        build(0, 0, n - 1, v);
    }

    node get(int ll, int rr) {
        assert(0 <= ll && ll <= rr && rr <= n - 1);
        return get(0, 0, n - 1, ll, rr);
    }

    template <typename M>
    void modify(int ll, int rr, const M& v) {
        assert(0 <= ll && ll <= rr && rr <= n - 1);
        modify(0, 0, n - 1, ll, rr, v);
    }
};

class fenwick {
public:
    int n;
    vector<int> tree;
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

vector<int> spf(N, 0);
vector<bool> prime(N, true);
vector<int> primes;
void sieve() {
    prime[0] = prime[1] = false;
    for(int i = 2; i < N; i++) {
        if(prime[i]) {
            spf[i] = i;
            primes.push_back(i);
        }
        int prod;
        for(int j = 0; j < (int) primes.size() && primes[j] <= spf[i] && (prod = primes[j] * i) < N; j++) {
            spf[prod] = primes[j];
            prime[prod] = false;
        }
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    sieve();

    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    
    sort(a.begin(), a.end());
    segtree st(n);
        
    fenwick f(n);
    
    vector<int> ans(n);
    
    int sum = 0;
    
    int ii = 0;
    while(ii < n) {
        
        int jj = ii;
        while(jj < n && a[jj].first == a[ii].first) {
            jj++;
        }
        
        for(int iii = ii; iii < jj; iii++) {
            int val = a[iii].first, i = a[iii].second;
            
            int lo = max<int>(0, i - k);
            int hi = min<int>(n - 1, i + k);
            
            int mn = min<int>(st.get(lo, hi).mn + 1, f.get(hi) > (lo > 0 ? f.get(lo - 1) : 0) ? 1 : INF);
                    
            ans[i] = mn;         
        }
        
        for(int iii = ii; iii < jj; iii++) {
            int val = a[iii].first, i = a[iii].second;
            
            st.modify(i, i, ans[i]);
            if(prime[val]) {
                f.modify(i, 1);
            }
                        
            sum += ans[i] >= INF ? 0 : ans[i];
        }
        
        ii = jj;
    }
    
    cout << (sum % mod) << '\n';
    
    return 0;
}