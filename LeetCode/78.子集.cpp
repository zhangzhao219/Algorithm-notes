/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution {
public:
    vector<vector<int> > result;
    vector<int> temp;
    void backtracking(vector<int> nums, int startIndex, int maxIndex){
        if(temp.size() == maxIndex){
            result.push_back(temp);
            return;
        }
        for(int i=startIndex;i<nums.size();i++){
            temp.push_back(nums[i]);
            backtracking(nums, i+1, maxIndex);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        for(int i=0;i<=nums.size();i++){
            backtracking(nums,0,i);
        }
        return result;
    }
};
// @lc code=end

