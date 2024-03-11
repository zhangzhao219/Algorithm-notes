/*
 * @lc app=leetcode.cn id=188 lang=cpp
 *
 * [188] 买卖股票的最佳时机 IV
 */

// @lc code=start
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int> > dp(n,vector<int>(k*2,0));
        for(int i=0;i<k*2;i+=2){
            dp[0][i] = -prices[0];
        }
        for(int i=1;i<n;i++){
            dp[i][0] = max(dp[i-1][0], - prices[i]);
            for(int j=1;j<2*k;j++){
                if(j % 2 == 0){
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-1] - prices[i]);
                } else{
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-1] + prices[i]);
                }
            }
        }
        int maxprofit = 0;
        for(int i=0;i<2*k;i++){
            maxprofit = max(maxprofit, dp[n-1][i]);
        }
        return maxprofit;
    }
};
// @lc code=end

