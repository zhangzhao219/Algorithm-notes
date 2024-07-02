/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */

// @lc code=start
class Solution {
public:
    int minDistance(string word1, string word2) {
        int s1 = word1.size();
        int s2 = word2.size();
        vector<vector<int> > dp(s1+1, vector<int>(s2+1,0));
        for(int i=0;i<=s1;i++){
            dp[i][0] = i;
        }
        for(int j=0;j<=s2;j++){
            dp[0][j] = j;
        }
        for(int i=1;i<=s1;i++){
            for(int j=1;j<=s2;j++){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                } else{
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
                }
            }
        }
        return dp[s1][s2];
    }
};
// @lc code=end

