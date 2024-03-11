/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 买卖股票的最佳时机含冷冻期
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int> > dp(n,vector<int>(4,0));
        // 持有
        // 不持有不是今天卖的
        // 不持有是今天卖的
        // 冷冻期
        dp[0][0] = -prices[0];
        for(int i=1;i<n;i++){
            dp[i][0] = max(dp[i-1][0], max(dp[i-1][1], dp[i-1][3]) - prices[i]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][3]);
            dp[i][2] = dp[i-1][0] + prices[i];
            dp[i][3] = dp[i-1][2];
        }
        return max(dp[n-1][1], max(dp[n-1][2],dp[n-1][3]));
    }
};
// @lc code=end

