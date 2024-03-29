/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int left = 0;
        for(int right = 1;right < nums.size();right++){
            if (nums[right] != nums[left]){
                nums[++left] = nums[right];
            }
        }
        return left + 1;
    }
};
// @lc code=end

