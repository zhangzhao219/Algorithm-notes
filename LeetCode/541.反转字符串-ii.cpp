/*
 * @lc app=leetcode.cn id=541 lang=cpp
 *
 * [541] 反转字符串 II
 */

// @lc code=start
class Solution {
public:
    string reversesmallstr(string s){
        reverse(s.begin(), s.end()); 
        return s;
    }
    string reverseStr(string s, int k) {
        string result_str = "";
        while(s.size() >= 2 * k){
            result_str += reversesmallstr(s.substr(0,k));
            s.erase(0,k);
            result_str += s.substr(0,k);
            s.erase(0,k);
        }
        if (s.size() >= k){
            result_str += reversesmallstr(s.substr(0,k));
            s.erase(0,k);
            result_str += s;
        } else{
            result_str += reversesmallstr(s);
        }
        return result_str;
    }
};
// @lc code=end

