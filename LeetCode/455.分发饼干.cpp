/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */

// @lc code=start
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int gindex = 0;
        int sindex = 0;
        while(gindex != g.size() && sindex != s.size()){
            if(s[sindex] >= g[gindex]){
                gindex += 1;
                sindex += 1;
            } else{
                sindex += 1;
            }
        }
        return gindex;
    }
};
// @lc code=end

