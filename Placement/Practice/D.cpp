/**
 *    author:  Taara Sinh Aatrey
 *    created: 16.08.2022 02:05:13
**/

#include "bits/stdc++.h"

using namespace std;

#ifdef AATREY_DEBUG
#include "debug.hpp"
#else
#define dbg(...)
#endif

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    int N;
    cin >> s >> N;
    int mn_prefix_sum = 0;
    int total_score = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            total_score++;
        }
        else {
            total_score--;
        }
        mn_prefix_sum = min(mn_prefix_sum, total_score);
    }

    // now we need to have the score of the X (which is the prefix of S) at least equal to max(0, -mn_prefix_sum)
    // now let's create a dp where dp[i][j] will store the number of valid RBS of length `i`isuch that their score is `j`

    vector<vector<int>> dp(N + 1, vector<int>(N + 1, 0));
    dp[0][0] = 1;
    for (int len = 1; len <= N - s.size(); len++) {
        for (int score = 0; score <= N; score++) {
            if (score > 0)
                dp[len][score] += dp[len - 1][score - 1];
            if (score < N)
                dp[len][score] += dp[len - 1][score + 1];
        }
    }

    vector<vector<int>> dp2(N + 1, vector<int>(N + 1, 0));
    // now let's considering putting S after having a prefix of `pref_len`

    for (int pref_len = 0; pref_len <= N - s.size(); pref_len++) {
        for (int score = max<int>(0, -mn_prefix_sum); score <= N; score++) {
            dp2[pref_len + s.size()] [score + total_score] = dp[pref_len][score];
        }
    }

    // now let's considering putting suffix

    for (int len = s.size() + 1; len <= N; len++) {
        for (int score = 0; score <= N; score++) {
            if (score > 0)
                dp2[len][score] += dp2[len - 1][score - 1];
            if (score < N)
                dp2[len][score] += dp2[len - 1][score + 1];
        }
    }
    
    cout << dp2[N][0] << '\n';
    
    return 0;
}