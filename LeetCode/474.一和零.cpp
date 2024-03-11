/*
 * @lc app=leetcode.cn id=474 lang=cpp
 *
 * [474] 一和零
 */

// @lc code=start
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int> > dp(m+1, vector<int>(n+1,0));
        for(int i=0;i<strs.size();i++){
            string s = strs[i];
            int zeronum = 0;
            int onenum = 0;
            for(int j=0;j<s.size();j++){
                if(s[j] == '0'){
                    zeronum += 1;
                } else{
                    onenum += 1;
                }
            }
            for(int x=m;x >= zeronum;x--){
                for(int y=n;y>=onenum;y--){
                    dp[x][y] = max(dp[x][y],dp[x-zeronum][y-onenum]+1);
                }
            }
        }
        return dp[m][n];
    }
};
// @lc code=end

