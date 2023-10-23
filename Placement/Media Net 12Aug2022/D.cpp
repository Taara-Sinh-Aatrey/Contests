/**
 *    author:  Taara Sinh Aatrey
 *    created: 16.08.2022 12:49:43
**/

#include "bits/stdc++.h"

using namespace std;

#ifdef AATREY_DEBUG
#include "debug.hpp"
#else
#define dbg(...)
#endif

const int inf = 1e9 + 5;

void construct(vector<pair<int, int>> &dp, vector<map<char, int>> &freq, int mask, vector<string> &ans) {
    if (mask == 0)
        return;
    for (char ch = 'a'; ch <= 'z'; ch++) {
        int min_freq = inf;
        for (int i = 0; i < 4; i++) {
            if (mask >> i & 1) {
                min_freq = min(min_freq, freq[i][ch]);
            }
        }
        for (int i = 0; i < 4; i++) {
            if (mask >> i & 1) {
                freq[i][ch] -= min_freq;
                ans[i] += string(min_freq, ch);
            }
        }
    }
    int submask = dp[mask].second;
    int submask2 = mask & (~submask);
    if (submask == 0 || submask2 == 0)
        return;
    construct(dp, freq, submask, ans);
    construct(dp, freq, submask2, ans);
}

void solve() {
    vector<string> s(4);
    vector<map<char, int>> freq(4);
    for (int i = 0; i < 4; i++) {
        cin >> s[i];
        for (auto &ch : s[i])
            freq[i][ch]++;
    }
    vector<pair<int, int>> dp(1 << 4);
    dp[0].first = 0;
    for (int mask = 1; mask < (1 << 4); mask++) {
        dp[mask] = {0, mask};
        for (int i = 0; i < 4; i++) {
            if (mask >> i & 1) {
                dp[mask].first += s[i].size();
            }
        }
        int common = 0;
        for (char ch = 'a'; ch <= 'z'; ch++) {
            int min_freq = inf;
            for (int i = 0; i < 4; i++) {
                if (mask >> i & 1) {
                    min_freq = min(min_freq, freq[i][ch]);
                }
            }
            common += min_freq;
        }
        int submask = mask & (mask - 1);
        while (submask > 0) {
            int submask2 = mask & (~submask);
            int cur = (dp[submask].first - common) + (dp[submask2].first - common) + common;
            if (cur < dp[mask].first) {
                dp[mask] = {cur, submask};
            }
            submask = (submask - 1) & mask;
        }
    }
    cout << dp[15].first << '\n';
    vector<string> ans(4);
    construct(dp, freq, 15, ans);
    for (int i = 0; i < 4; i++) {
        cout << ans[i] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // Write your code here
    return 0;
}
