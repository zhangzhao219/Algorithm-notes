/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int> > result;
    vector<int> temp;
    void backtracking(vector<int> nums, int startIndex){
        result.push_back(temp);
        for(int i=startIndex;i<nums.size();i++){
            if(i > startIndex && nums[i] == nums[i-1]){
                continue;
            }
            temp.push_back(nums[i]);
            backtracking(nums, i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        backtracking(nums,0);
        return result;
    }
};
// @lc code=end

