/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return nums[0];
        }
        if(n == 2){
            return max(nums[0], nums[1]);
        }
        if(n == 3){
            return max(nums[0],max(nums[1], nums[2]));
        }
        vector<int> dp(n);
        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);
        for(int i=2;i<n-1;i++){
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }
        vector<int> dp2(n);
        dp2[1] = nums[1];
        dp2[2] = max(nums[1],nums[2]);
        for(int i=3;i<n;i++){
            dp2[i] = max(dp2[i-1], dp2[i-2] + nums[i]);
        }
        return max(dp[n-2], dp2[n-1]);
    }
};
// @lc code=end

