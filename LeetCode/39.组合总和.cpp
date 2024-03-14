/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution {
private:
    vector<vector<int> > result;
    vector<int> temp;
public:
    void backtracking(vector<int>& candidates, int target, int start, int end){
        int countsum = 0;
        for(int i=0;i<temp.size();i++){
            countsum += temp[i];
        }
        if(countsum == target){
            result.push_back(temp);
            return;
        } else if(countsum > target){
            return;
        }
        for(int i=start;i<=end;i++){
            temp.push_back(candidates[i]);
            backtracking(candidates,target,i,candidates.size()-1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtracking(candidates, target,0,candidates.size()-1);
        return result;
    }
};
// @lc code=end

