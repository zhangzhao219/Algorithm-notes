/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

// @lc code=start
class Solution {
public:
    int robber(vector<int>& nums){
        int n = nums.size();
        if(n == 1){
            return nums[0];
        }
        if(n == 2){
            return max(nums[0], nums[1]);
        }
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for(int i=2;i<n;i++){
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }
        return dp[n-1];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return nums[0];
        }
        int result = 0;
        vector<int> nums1;
        for(int i=1;i<n;i++){
            nums1.push_back(nums[i]);
        }
        result = max(result, robber(nums1));
        vector<int> nums2;
        for(int i=0;i<n-1;i++){
            nums2.push_back(nums[i]);
        }
        result = max(result, robber(nums2));
        return result;
    }
};
// @lc code=end

