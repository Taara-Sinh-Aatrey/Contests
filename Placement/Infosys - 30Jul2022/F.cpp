#include "bits/stdc++.h"
using namespace std;

class fenwick {
public:
    int n;
    vector<int> tree;

    fenwick(int _n) : n(_n) {
        tree.resize(n + 1, 0);
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


int solve(int n, int q, vector<vector<int>> qry) {
#define int int64_t
    const int mod = 1e9 + 7;
    set<pair<int, int>> st;
    st.emplace(1, n);
    multiset<pair<int, int>> ms;
    ms.emplace(n, 1);
    vector<int> cnt(n, 0);
    map<int, int> pos;
    int ans = 0;
    fenwick f(n + 1);
    auto Insert = [&] (int start, int end) {
        if (start > end) {
            return;
        }
        st.emplace(start, end);
        ms.emplace(end - start + 1, start);
    };
    for (int i = 0; i < q; i++) {
        int l = qry[i][0], r = qry[i][1];
        if (r == -1) {
            cnt[l]++;
            if (cnt[l] % 2 == 1) {
                auto [len, start] = *ms.rbegin();
                ms.erase(prev(ms.end()));
                int end = start + len - 1;
                int median = start + len / 2;
                f.modify(median, 1);
                pos[l] = median;
                st.erase({start, end});
                Insert(start, median - 1);
                Insert(median + 1, end);
            }
            else {
                int x = pos[l];
                f.modify(x, -1);
                int start = x, end = x;
                auto it = st.lower_bound({start, end});
                if (it != st.end() && it->first == x + 1) {
                    end = it->second;
                    ms.erase({it->second - it->first + 1, it->first});
                    st.erase(it);
                }
                it = st.lower_bound({start, end});
                if (it != st.begin()) {
                    it = prev(it);
                    if (it->second == x - 1) {
                        start = it->first;
                        ms.erase({it->second - it->first + 1, it->first});
                        st.erase(it);
                    }
                }
                Insert(start, end);
            }
        }
        else {
            ans += f.get(r) - f.get(l - 1);
            if (ans >= mod) {
                ans -= mod;
            }
        }
    }
    return ans;
#undef int
}

int main() {
    cout << solve(7, 3, {{1, -1}, {2, 5}, {4, 4}}) << endl;
    cout << solve(7, 4, {{1, -1}, {2, 5}, {1, -1}, {4, 4}}) << endl;
    cout << solve(6, 10, {{1, -1}, {2, -1}, {3, -1}, {4, -1}, {5, -1}, {2, 4}, {2, -1}, {2, 4}, {1, -1}, {2, 4}}) << endl;
    return 0;
}