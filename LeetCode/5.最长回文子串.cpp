/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        string result = "";
        int longresult = 1;
        result += s[0];
        int l = s.size();
        for(int i=0;i<l-1;i++){
            int start = i;
            int end = i + 1;
            while(start >= 0 && end < l && s[start] == s[end]){
                start--;
                end++;
            }
            start++;
            end--;
            if(end-start+1 > longresult){
                longresult = end-start+1;
                result = s.substr(start,longresult);
            }
        }
        for(int i=1;i<l-1;i++){
            int start = i - 1;
            int end = i + 1;
            while(start >= 0 && end < l && s[start] == s[end]){
                start--;
                end++;
            }
            start++;
            end--;
            if(end-start+1 > longresult){
                longresult = end-start+1;
                result = s.substr(start,longresult);
            }
        }
        return result;
    }
};
// @lc code=end

