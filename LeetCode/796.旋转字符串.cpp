/*
 * @lc app=leetcode.cn id=796 lang=cpp
 *
 * [796] 旋转字符串
 */

// @lc code=start
class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()){
            return false;
        }
        for(int left = 0;left < s.size();left++){
            string comp = s.substr(1,s.size()-1) + s.substr(0,1);
            s = comp;
            if(s == goal){
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

