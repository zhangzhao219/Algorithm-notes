/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start
class Solution {
public:
    int myAtoi(string s) {
        int res = 0;
        bool havenumsign = false;
        bool negativesign = false;
        bool fakebigsign = false;
        for(int i=0;i<s.size();i++){
            if(s[i] == ' ' && havenumsign == false){
                continue;
            }
            if(s[i] == '-' && havenumsign == false){
                negativesign = true;
                havenumsign = true;
                continue;
            }
            if(s[i] == '+' && havenumsign == false){
                havenumsign = true;
                continue;
            }
            if(s[i] >= '0' && s[i] <= '9'){
                havenumsign = true;
                if(res > (INT_MAX - s[i] + '0') / 10){
                    res = INT_MAX;
                    fakebigsign = true;
                    break;
                }
                res = res * 10 - '0' + s[i];
                continue;
            }
            if(havenumsign == true){
                break;
            }
            break;
        }
        if (negativesign){
            if(res == INT_MAX && fakebigsign){
                return INT_MIN;
            }
            return -res;
        }
        return res;
    }
};
// @lc code=end

