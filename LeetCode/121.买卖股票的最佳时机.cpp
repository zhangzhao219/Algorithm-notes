/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprice = INT_MAX, maxprofit = 0;
        for(int i=0;i<prices.size();i++){
            maxprofit = max(maxprofit, prices[i] - minprice);
            minprice = min(prices[i], minprice);
        }
        return maxprofit;
    }
};
// @lc code=end

