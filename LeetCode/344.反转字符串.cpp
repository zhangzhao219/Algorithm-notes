/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] 反转字符串
 */

// @lc code=start
class Solution {
public:
    void reverseString(vector<char>& s) {
        int slen = s.size();
        for(int left=0;left < slen/2;left++){
            char t = s[left];
            s[left] = s[slen-left-1];
            s[slen-left-1] = t;
        }

    }
};
// @lc code=end

