/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1);
        if(n == 1){
            return nums[0];
        }
        if(n == 2){
            return max(nums[0], nums[1]);
        }
        dp[1] = nums[0];
        dp[2] = max(nums[0], nums[1]);
        for(int i=3;i<=n;i++){
            dp[i] = max(dp[i-1], dp[i-2] + nums[i-1]);
        }
        return dp[n];
    }
};
// @lc code=end

