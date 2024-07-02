/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

// @lc code=start
class Solution {
private:
    vector<vector<string>> result;
    vector<string> temp;
public:
    bool judge(string t){
        int start = 0;
        int end = t.size() - 1;
        while(start < end){
            if(t[start] != t[end]){
                return false;
            }
            start += 1;
            end -= 1;
        }
        return true;
    }
    void backtracking(string s, int start){
        if(start == s.size()){
            result.push_back(temp);
            return;
        }
        for(int i=1; i<=s.size()-start;i++){
            string t = s.substr(start,i);
            if(judge(t)){
                temp.push_back(t);
                backtracking(s,start+i);
                temp.pop_back();
            }
        }
    }
    vector<vector<string> > partition(string s) {
        backtracking(s,0);
        return result;
    }
};
// @lc code=end

