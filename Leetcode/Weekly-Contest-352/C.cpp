/**
 *    author:  Taara Sinh Aatrey
 *    created: 06.07.2023 11:11:09
**/

#include "bits/stdc++.h"

using namespace std;

#ifdef AATREY_DEBUG
#include "debug.hpp"
#else
#define dbg(...)
#endif

class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
    #define int int64_t
        int n = nums.size();
        int ans = 0;
        const int inf = 1e18L + 5;
        int mn = inf, mx = -inf;
        int j = -1;
        multiset<int> st;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (st.empty()) {
                j = i;
            }
            st.emplace(nums[i]);
            while (!(nums[i] - *st.begin() <= 2 && *st.rbegin() - nums[i] <= 2)) {
                st.erase(nums[j++]);
            }
            ans += i - j + 1;
        }
        return ans;
    #undef int       
    }
};

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // Write your code here
    return 0;
}