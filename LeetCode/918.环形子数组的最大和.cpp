/*
 * @lc app=leetcode.cn id=918 lang=cpp
 *
 * [918] 环形子数组的最大和
 */

// @lc code=start
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        vector<int> dp(nums.size(),0);
        vector<int> leftMax(nums.size(),0);
        dp[0] = nums[0];
        int maxlength = dp[0];
        int leftSum = dp[0];
        leftMax[0] = dp[0];
        for(int i=1;i<nums.size();i++){
            dp[i] = max(dp[i-1] + nums[i], nums[i]);
            maxlength = max(maxlength, dp[i]);
            leftSum += nums[i];
            leftMax[i] = max(leftMax[i-1], leftSum);
        }
        int rightSum = 0;
        for(int j=nums.size()-1;j>0;j--){
            rightSum += nums[j];
            maxlength = max(maxlength, rightSum + leftMax[j-1]);
        }
        return maxlength;
    }
};
// @lc code=end

