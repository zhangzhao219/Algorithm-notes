/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution {
private:
    vector<vector<int> > result;
public:
    void backtracking(vector<int>& nums, vector<int>& temp, int start){
        result.push_back(temp);
        if(start >= nums.size()){
            return;
        }
        for(int i=start;i<nums.size();i++){
            temp.push_back(nums[i]);
            backtracking(nums, temp, i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        backtracking(nums, temp, 0);
        return result;
    }
};
// @lc code=end

