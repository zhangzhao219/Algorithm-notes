// #给定不同面额的硬币 coins 和一个总金额 amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。
//#如果没有任何一种硬币组合能组成总金额，返回-1。

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount+1,INT_MAX);
        dp[0] = 0;
        for(int i=0;i<n;i++){
            for(int j=coins[i];j<=amount;j++){
                if (dp[j - coins[i]] != INT_MAX) {
                    dp[j] = min(dp[j], dp[j-coins[i]]+1);
                }
            }
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};