/*
 * @lc app=leetcode.cn id=85 lang=cpp
 *
 * [85] 最大矩形
 */

// @lc code=start
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int result = 0;
        vector<vector<int> > dp(m, vector<int>(n,0));
        if(matrix[0][0] == '1'){
            dp[0][0] = 1;
            result = max(result, dp[0][0]);
        }
        for(int i=1;i<m;i++){
            if(matrix[i][0] == '1'){
                dp[i][0] = dp[i-1][0] + 1;
                result = max(result, dp[i][0]);
            }
        }
        for(int j=1;j<n;j++){
            if(matrix[0][j] == '1'){
                dp[0][j] = dp[0][j-1] + 1;
                result = max(result, dp[0][j]);
            }
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][j] == '1'){
                    bool left = false;
                    bool up = false;
                    bool inner = false;
                    if(matrix[i-1][j] == '1'){
                        left = true;
                    }
                    if(matrix[i][j-1] == '1'){
                        up = true;
                    }
                    if(matrix[i-1][j-1] == '1'){
                        inner = true;
                    }
                    if(left == false && up == false){
                        dp[i][j] = 1;
                    } else if(left == true || up == true){
                        dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + 1;
                        if(inner == true){
                            if(left == true && up == true){
                                dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + 1;
                            } else{
                                dp[i][j] -= dp[i-1][j-1];
                            }
                        }
                    }
                    result = max(result, dp[i][j]);
                }
            }
        }
        return result;
    }
};
// @lc code=end

