/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子数组
 */

// @lc code=start
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        double maxF = nums[0], minF = nums[0], ans = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            double mx = maxF, mn = minF;
            maxF = max(mx * nums[i], max(static_cast<double>(nums[i]), mn * nums[i]));
            minF = min(mn * nums[i], min(static_cast<double>(nums[i]), mx * nums[i]));
            ans = max(maxF, ans);
        }
        return static_cast<int>(ans);
    }
};
// @lc code=end
