/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
private:
    vector<vector<int> > result;
public:
    void backtracking(vector<int>& nums, vector<bool>& visited, vector<int>& temp){
        if(temp.size() == nums.size()){
            result.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(visited[i] == true){
                continue;
            }
            visited[i] = true;
            temp.push_back(nums[i]);
            backtracking(nums, visited, temp);
            temp.pop_back();
            visited[i] = false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp;
        vector<bool> visited(nums.size(), false);
        backtracking(nums, visited, temp);
        return result;
    }
};
// @lc code=end

