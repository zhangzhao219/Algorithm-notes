/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
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
            if (i > start && candidates[i] == candidates[i - 1]) {
                continue;
            }
            temp.push_back(candidates[i]);
            backtracking(candidates,target,i+1,candidates.size()-1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target,0,candidates.size()-1);
        return result;
    }
};
// @lc code=end

