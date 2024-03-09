/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */

// @lc code=start
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int> > dp(m+1, vector<int>(n+1));
        if(obstacleGrid[0][0] == 1){
            return 0;
        }
        for(int i=0;i<m;i++){
            dp[i][0] = 0;
        }
        for(int j=0;j<n;j++){
            dp[0][j] = 0;
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(i == 1 && j == 1){
                    dp[i][j] = 1;
                    continue;
                }
                if(obstacleGrid[i-1][j-1] == 1){
                    dp[i][j] = 0;
                } else{
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        return dp[m][n];
    }
};
// @lc code=end

