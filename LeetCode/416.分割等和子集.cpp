/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */

// @lc code=start
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int numsum = 0;
        for(int i=0;i<nums.size();i++){
            numsum += nums[i];
        }
        if(numsum % 2 != 0){
            return false;
        }
        int target = numsum / 2;
        vector<vector<int> > dp(nums.size(), vector<int>(target+1,0));
        for(int i=0;i<=target;i++){
            if(i >= nums[0]){
                dp[0][i] = nums[0];
            }
        }
        for(int i=1;i<nums.size();i++){
            for(int j=0;j<=target;j++){
                if(j < nums[i]){
                    dp[i][j] = dp[i-1][j];
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-nums[i]] + nums[i]);
                }
            }
        }
        return dp[nums.size()-1][target] == target;
    }
};
// @lc code=end

