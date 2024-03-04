/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0;
        for(int right = 0;right < nums.size();right++){
            if(nums[right] != 0){
                nums[left] = nums[right];
                left += 1;
            }
        }
        for(;left < nums.size();left += 1){
            nums[left] = 0;
        }
    }
};
// @lc code=end

