/*
 * @lc app=leetcode.cn id=844 lang=cpp
 *
 * [844] 比较含退格的字符串
 */

// @lc code=start
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int slen = s.length() - 1;
        int tlen = t.length() - 1;
        int sskip = 0;
        int tskip = 0;
        while(slen >= 0 || tlen >= 0){
            while(slen >= 0){
                if (s[slen] == '#'){
                    sskip += 1;
                    slen -= 1;
                } else if (sskip > 0){
                    sskip -= 1;
                    slen -= 1;
                } else{
                    break;
                }
            }
            while(tlen >= 0){
                if (t[tlen] == '#'){
                    tskip += 1;
                    tlen -= 1;
                } else if (tskip > 0){
                    tskip -= 1;
                    tlen -= 1;
                } else{
                    break;
                }
            }
            if (slen >= 0 && tlen >= 0){
                if (s[slen] != t[tlen]){
                    return false;
                }
            } else if (slen >= 0 || tlen >= 0){
                return false;
            }
            slen -= 1;
            tlen -= 1;

        }
        return true;
    }
};
// @lc code=end

