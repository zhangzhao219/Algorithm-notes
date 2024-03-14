/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
class Solution {
private:
    vector<vector<int> > result;
    vector<int> temp;
public:
    void backtracking(int start, int end, int k){
        if(temp.size() == k){
            result.push_back(temp);
            return;
        }
        for(int i=start;i<=end;i++){
            temp.push_back(i);
            backtracking(i+1,end,k);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        
        backtracking(1,n,k);
        return result;
    }
};
// @lc code=end

