/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */

// @lc code=start
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,n+1);
        for(int i=1;i<=n;i++){
            if(i*i < n){
                dp[i*i] = 1;
            } else if(i*i == n){
                return 1;
            } else{
                break;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=i;j>=1;j--){
                dp[i] = min(dp[i], dp[i-j]+ dp[j]);
            }
        }
        return dp[n];
    }
};
// @lc code=end
