/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount+1, amount+1);
        dp[0] = 0;
        for(int i=0;i<n;i++){
            for(int j=coins[i];j<=amount;j++){
                dp[j] = min(dp[j], dp[j-coins[i]]+1);
            }
        }
        if(dp[amount] == amount+1){
            return -1;
        }
        return dp[amount];
    }
};
// @lc code=end

