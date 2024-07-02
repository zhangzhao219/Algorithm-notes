/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution {
private:
    vector<vector<int>> result;
    vector<int> temp;
public:
    void backtracking(vector<int>& candidates, int target, int nowsum, int start){
        if(nowsum > target){
            return;
        }
        if(nowsum == target){
            result.push_back(temp);
            return;
        }
        for(int i=start;i<candidates.size();i++){
            temp.push_back(candidates[i]);
            backtracking(candidates, target, nowsum+candidates[i], i);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtracking(candidates, target, 0, 0);
        return result;
    }
};
// @lc code=end

