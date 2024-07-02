/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */

// @lc code=start
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1){
            return s;
        }
        vector<queue<char> > vt(numRows);
        int nowindex = 0;
        int reverse = false;
        for(int i=0;i<s.size();i++){
            vt[nowindex].push(s[i]);
            if(nowindex == 0 && reverse == true){
                reverse = false;
                nowindex += 1;
            } else if (nowindex == numRows-1 && reverse == false){
                reverse = true;
                nowindex -= 1;
            } else {
                if(reverse == false){
                    nowindex += 1;
                } else{
                    nowindex -= 1;
                }
            }
        }
        string resultstring = "";
        for(int i=0;i<vt.size();i++){
            while(!vt[i].empty()){
                resultstring += vt[i].front();
                vt[i].pop();
            }
        }
        return resultstring;
    }
};
// @lc code=end

