#include "bits/stdc++.h"
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;

const int inf = 1e9 + 5;

static char stdinBuffer[1024];
static char* stdinDataEnd = stdinBuffer + sizeof (stdinBuffer);
static const char* stdinPos = stdinDataEnd;

void readAhead(size_t amount)
{
    size_t remaining = stdinDataEnd - stdinPos;
    if (remaining < amount) {
       memmove(stdinBuffer, stdinPos, remaining);
       size_t sz = fread(stdinBuffer + remaining, 1, sizeof (stdinBuffer) - remaining, stdin);
       stdinPos = stdinBuffer;
       stdinDataEnd = stdinBuffer + remaining + sz;
       if (stdinDataEnd != stdinBuffer + sizeof (stdinBuffer))
         *stdinDataEnd = 0;
    }
}

void readInt(int &x) {
    readAhead(16);
    x = 0;
    while (*stdinPos >= '0' && *stdinPos <= '9') {
        x = x * 10 + *stdinPos - '0';
        ++stdinPos;
    }
    stdinPos++;
}

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    int m, n;
    readInt(m); readInt(n);
    vector<vector<int>> mat(n, vector<int>(m));
    vector<vector<int>> dp(1 << n, vector<int>(m, inf));
    int i = 0;
    for (auto &vec : mat) {
        int prev = 0;
        for (auto &ele : vec) {
            readInt(ele);
            ele += prev;
            prev = ele;
        }
        dp[1 << i] = vec;
        i++;
    }
    int mask = -1;
    int tot = (1 << n) - 1;
    for (auto &dp_mask : dp) {
        mask++;
        if (mask == 0 || mask == tot) continue;
        int counter_mask = tot ^ mask;
        for (int me = __builtin_ctz(counter_mask); counter_mask > 0; counter_mask ^= (1 << me), me = __builtin_ctz(counter_mask)) {
            auto& mat_me = mat[me];
            int mn = 0, j = -1;
            for (auto& dp_new_mask_j : dp[mask | 1 << me]) {
                j++;
                mn = min(mn, dp_mask[j] - mat_me[j]);
                dp_new_mask_j = min(dp_new_mask_j, mat_me[j] + mn);
            }
        }
    }
    cout << dp[tot][m - 1];    
    return 0;
}