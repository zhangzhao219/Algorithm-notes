/*
 * @lc app=leetcode.cn id=459 lang=cpp
 *
 * [459] 重复的子字符串
 */

// @lc code=start
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int slen = s.size();
        if (slen == 1){
            return false;
        }
        for(int i=1;i<slen / 2+1;i++){
            if(slen % i != 0){
                continue;
            }
            string t = s.substr(0,i);
            bool flag = true;
            for(int index=i;index < slen-i+1;index += i){
                if(s.substr(index,i) != t){
                    flag = false;
                    break;
                }
            }
            if(flag){
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

