/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */

// @lc code=start
class Solution {
public:
    int numSquares(int n) {
        vector<int> nums;
        for(int i=1;i<=n;i++){
            if(i * i <= n){
                nums.push_back(i*i);
            } else{
                break;
            }
        }
        int m = nums.size();
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        for(int i=0;i<m;i++){
            for(int j=nums[i];j<=n;j++){
                if(dp[j-nums[i]] == INT_MAX){
                    continue;
                }
                dp[j] = min(dp[j],dp[j-nums[i]]+1);
            }
        }
        return dp[n];
    }
};
// @lc code=end

