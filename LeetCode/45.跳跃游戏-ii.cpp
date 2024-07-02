/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int result = n+1;
        vector<int> dp(n+1,n+1);
        dp[0] = 0;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(j + nums[j] >= i){
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }
        return dp[n-1];
    }
};
// @lc code=end

