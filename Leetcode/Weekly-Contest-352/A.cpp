class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            bool ok = nums[i] % 2 == 0 && nums[i] <= threshold;
            int j = i + 1;
            while (j < n && nums[j] <= threshold && nums[j] % 2 != nums[j - 1] % 2) {
                j++;
            }
            if (ok)
                ans = max(ans, j - i);
        }
        return ans;
    }
};