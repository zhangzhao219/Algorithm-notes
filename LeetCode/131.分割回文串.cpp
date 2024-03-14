/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

// @lc code=start
class Solution {
public:
    vector<vector<string> > result;
    vector<string> path;
    bool judgepa(string s, int startIndex, int endIndex){
        while(startIndex < endIndex){
            if(s[startIndex] != s[endIndex]){
                return false;
            }
            startIndex += 1;
            endIndex -= 1;
        }
        return true;
    }
    void backtracking(string s, int startIndex){
        if(startIndex >= s.size()){
            result.push_back(path);
            return;
        }
        for(int i = startIndex;i<s.size();i++){
            if(judgepa(s,startIndex,i)){
                string str = s.substr(startIndex, i-startIndex+1);
                path.push_back(str);
            } else{
                continue;
            }
            backtracking(s,i+1);
            path.pop_back();
        }

    }
    vector<vector<string>> partition(string s) {
        backtracking(s,0);
        return result;
    }
};
// @lc code=end

