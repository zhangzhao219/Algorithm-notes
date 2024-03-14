/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
public:
    vector<vector<int> > result;
    vector<int> temp;
    void backtracking(vector<int>& nums, int startIndex, vector<bool> used){
        if(temp.size() == nums.size()){
            result.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(used[i] == true){
                continue;
            }
            used[i] = true;
            temp.push_back(nums[i]);
            backtracking(nums,i+1, used);
            temp.pop_back();
            used[i] = false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        backtracking(nums,0, used);
        return result;
    }
};
// @lc code=end

