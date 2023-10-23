/**
 *    author:  Taara Sinh Aatrey
 *    created: 06.07.2023 11:28:16
**/

#include "bits/stdc++.h"

using namespace std;

#ifdef AATREY_DEBUG
#include "debug.hpp"
#else
#define dbg(...)
#endif

#define int int64_t

class Solution {
public:
    int sumImbalanceNumbers(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            multiset<int> ms;
            ms.emplace(nums[i]);
            int cur = 0;
            for (int j = i + 1; j < n; j++) {
                auto nxt = ms.lower_bound(nums[j]);
                if (nxt != ms.end() && *nxt == nums[j]) {
                    ms.emplace(nums[j]);
                    continue;
                }
                if (nxt != ms.end()) {
                    cur += *nxt - nums[j] > 1;
                }
                if (nxt != ms.begin()) {
                    cur += nums[j] - *prev(nxt) > 1;
                }
                if (nxt != ms.end() && nxt != ms.begin()) {
                    cur -= *nxt - *prev(nxt) > 1;
                }
                ms.emplace(nums[j]);
                ans += cur;
            }
        }
        return ans;
    }
};

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // Write your code here
    return 0;
}