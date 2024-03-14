/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int> > result;
    vector<int> temp;
    void backtracking(vector<int>& nums, vector<bool> used){
        if(temp.size() == nums.size()){
            result.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if((i > 0 && nums[i] == nums[i-1] && used[i-1] == false) || used[i] == true){
                continue;
            }
            used[i] = true;
            temp.push_back(nums[i]);
            backtracking(nums, used);
            temp.pop_back();
            used[i] = false;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());
        backtracking(nums, used);
        return result;
    }
};
// @lc code=end

