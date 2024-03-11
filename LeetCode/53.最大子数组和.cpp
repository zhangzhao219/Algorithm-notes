/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,0);
        dp[0] = nums[0];
        int result = dp[0];
        for(int i=1;i<n;i++){
            dp[i] = max(nums[i], dp[i-1] + nums[i]);
            result = max(result,dp[i]);
        }
        return result;
    }
};
// @lc code=end
