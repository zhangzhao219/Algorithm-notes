/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 反转字符串中的单词
 */

// @lc code=start
class Solution {
public:
    string reverse_word(string s){
        reverse(s.begin(), s.end());
        return s;
    }
    string reverseWords(string s) {
        string result_str = "";
        int left = 0;
        while(left < s.size()){
            while(left < s.size() && s[left] == ' '){
                left += 1;
            }
            int right = left;
            while(right < s.size() && s[right] != ' '){
                right += 1;
            }
            if(left == right){
                break;
            }
            result_str = result_str + reverse_word(s.substr(left,right-left)) + " ";
            left = right;
        }
        string result_str2 = result_str.substr(0,result_str.size()-1);

        return reverse_word(result_str2);
    }
};
// @lc code=end

