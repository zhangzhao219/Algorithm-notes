/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 */

// @lc code=start
class Solution {
public:
    vector<string> result;
    vector<string> temp;
    bool judgenum(string r){
        if(r.size() <= 0 || r.size() > 3){
            return false;
        }
        int num = stoi(r);
        if(num > 255){
            return false;
        }
        if(num != 0 && r[0] == '0'){
            return false;
        }
        if(num == 0 && r.size() != 1){
            return false;
        }
        return true;
    }
    void backtracking(string s, int startIndex){
        if(startIndex >= s.size() && temp.size() == 4){
            string r = "";
            for(int i=0;i<3;i++){
                r += temp[i];
                r += ".";
            }
            r += temp[3];
            result.push_back(r);
            return;
        } else if(temp.size() > 4 || startIndex >= s.size()){
            return;
        }
        for(int i=startIndex;i<s.size();i++){
            string r = s.substr(startIndex,i-startIndex+1);
            if(judgenum(r)){
                temp.push_back(r);
            } else{
                continue;
            }
            backtracking(s,i+1);
            temp.pop_back();
        }
    }
    vector<string> restoreIpAddresses(string s) {
        backtracking(s,0);
        return result;
    }
};
// @lc code=end

