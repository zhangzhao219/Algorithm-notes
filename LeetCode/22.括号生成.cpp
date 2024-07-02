/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution {
private:
    vector<string> result;
    vector<char> temp;
public:
    void backtracking(int n, int left){
        if(temp.size() == 2 * n && left == 0){
            string res = "";
            for(int i=0;i<temp.size();i++){
                res += temp[i];
            }
            result.push_back(res);
            return;
        }
        if(temp.size() == 2*n){
            return;
        }
        if(left > n){
            return;
        }
        if(left == 0){
            temp.push_back('(');
            backtracking(n, 1);
            temp.pop_back();
        } else{
            temp.push_back('(');
            backtracking(n, left+1);
            temp.pop_back();
            temp.push_back(')');
            backtracking(n, left-1);
            temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        backtracking(n,0);
        return result;
    }
};
// @lc code=end

