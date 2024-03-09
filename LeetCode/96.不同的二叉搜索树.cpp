/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */

// @lc code=start
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1);
        dp[0] = 1;
        dp[1] = 1;
        for(int i=2;i<=n;i++){
            for(int j=i;j>=1;j--){
                dp[i] = dp[i] + dp[j-1] * dp[i-j];
            }
        }
        return dp[n];
    }
};
// @lc code=end

