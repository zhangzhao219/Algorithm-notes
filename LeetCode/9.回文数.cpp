/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        int left = 0;
        int right = s.size() - 1;
        while(left < right){
            if(s[left] != s[right]){
                return false;
            }
            left += 1;
            right -= 1;
        }
        return true;
    }
};
// @lc code=end

