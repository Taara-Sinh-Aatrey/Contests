#include "bits/stdc++.h"
using namespace std;

#define int int64_t

const char MIN_CHAR = 'a';

class trie {
public:
    vector<vector<int>> child;
    vector<int> val;
    const int alphabet = 26;
    
    int create_node() {
        child.emplace_back(alphabet, -1);
        val.emplace_back(0);
        return child.size() - 1;
    }
    
    trie() {
        create_node();
    }
   
    void add(string s, int value = 1) {
        int cur = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            int ch = s[i] - MIN_CHAR;
            if (child[cur][ch] == -1) child[cur][ch] = create_node();
            cur = child[cur][ch];
        }
        val[cur] = value;
    }
};

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int d;
    cin >> d;
    trie tr;
    for (int i = 0; i < d; i++) {
        string s;
        cin >> s;
        tr.add(s);
    }
    int n, m;
    cin >> n >> m;
    vector<vector<char>> s(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> s[i][j];
        }
    }
    vector<set<int>> dp(1 << n);
    dp[0] = {0};
    for (int mask = 0; mask < 1 << n; mask++) {
        for (int i = 0; i < n; i++) {
            if (mask >> i & 1) continue;
            int new_mask = mask | (1 << i);
            for (auto &node : dp[mask]) {
                dp[new_mask].emplace(node);
                for (int j = 0; j < m; j++) {
                    int new_node = tr.child[node][s[i][j] - MIN_CHAR];
                    if (new_node != -1) {
                        dp[new_mask].emplace(new_node);
                    }
                }
            }
        }
    }
    int ans = 0;
    for (auto &node : dp[(1 << n) - 1]) {
        ans += tr.val[node];
    }
    cout << ans << '\n';
    return 0;
}

/*
int remaining_mask = ((1 << mask) - 1) & ~mask;
        
        for (int submask = remaining_mask; submask > 0; submask = (submask - 1) & mask) {
            int temp = submask;
            for (int bit = msb(temp); temp > 0; temp ^= 1LL << msb(temp), bit = msb(temp)) {
                // process bit
            }
                
        }
*/