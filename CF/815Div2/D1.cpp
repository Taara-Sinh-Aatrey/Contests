/**
 *    author:  Taara Sinh Aatrey
 *    created: 19.08.2022 13:58:09
**/

#include "bits/stdc++.h"

using namespace std;

#ifdef AATREY_DEBUG
#include "debug.hpp"
#else
#define dbg(...)
#endif

const int lg = 31;

class binary_trie {
public:
    
    vector<vector<int>> child;
    vector<vector<int>> val;
    
    binary_trie() {
        child.emplace_back(2, -1);
        val.emplace_back(2, 0);
    }
   
    void add(int num, int idx, int value) {
        int cur = 0;
        int Xor = num ^ idx;
        for (int i = lg - 1; i >= 0; i--) {
            int ch = Xor >> i & 1;
            if (child[cur][ch] == -1) {
                child[cur][ch] = child.size();
                child.emplace_back(2, -1);
                val.emplace_back(2, 0);
            }
            cur = child[cur][ch];
            val[cur][idx >> i & 1] = max(val[cur][idx >> i & 1], value);
        }
    }
    
    int get_max(int num, int idx) {
        int cur = 0;
        int Xor = num ^ idx;
        int ret = 0;
        for (int i = lg - 1; i >= 0; i--) {
            int ch = Xor >> i & 1;
            if (child[cur][ch ^ 1] != -1) {
                int opp_child = child[cur][ch ^ 1];
                ret = max(ret, val[opp_child][(idx >> i & 1) ^ (ch ^ 1)]);
            }
            if (child[cur][ch] == -1) break;
            cur = child[cur][ch];
        }
        return ret;
    }
    
};

/*
a[i] ^ j < a[j] ^ i
a[i] ^ i != a[j] ^ j for highest bits
and after that
0 0         1 0   -> good
1 1         0 1   -> good
1 0         1 1   -> good
0 1         0 0   -> good
0 1         1 1   -> bad
0 0         0 1   -> bad
1 1         1 0   -> bad
1 0         0 0   -> bad

*/

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        int n;
        cin >> n;
        binary_trie trie;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            int len = trie.get_max(x, i);
            ans = max(ans, len + 1);
            trie.add(x, i, len + 1);
        }
        cout << ans << '\n';
    }
    return 0;
}