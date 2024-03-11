/*
 * @lc app=leetcode.cn id=1049 lang=cpp
 *
 * [1049] 最后一块石头的重量 II
 */

// @lc code=start
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int numsum = 0;
        for(int i=0;i<stones.size();i++){
            numsum += stones[i];
        }
        int target = numsum;
        numsum /= 2;
        vector<vector<int> > dp(stones.size(),vector<int>(numsum+1, 0));
        for(int i=0;i<=numsum;i++){
            if(i >= stones[0]){
                dp[0][i] = stones[0];
            }
        }
        for(int i=1;i<stones.size();i++){
            for(int j=0;j<=numsum;j++){
                if(j < stones[i]){
                    dp[i][j] = dp[i-1][j];
                } else{
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-stones[i]] + stones[i]);
                }
            }
        }
        return abs(target-2*dp[stones.size()-1][numsum]);
    }
};
// @lc code=end

