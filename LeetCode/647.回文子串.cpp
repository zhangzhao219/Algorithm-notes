/*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] 回文子串
 */

// @lc code=start
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int result = 0;
        vector<vector<bool> > dp(n, vector<bool>(n,false));
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                if(s[i] == s[j]){
                    if(j-i <= 1){
                        result += 1;
                        dp[i][j] = true;
                    } else if(dp[i+1][j-1]){
                        result += 1;
                        dp[i][j] = true;
                    }
                }
            }
        }
        return result;
    }
};
// @lc code=end

