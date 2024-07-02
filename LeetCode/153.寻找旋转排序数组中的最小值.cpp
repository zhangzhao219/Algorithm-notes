/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
 */

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        while(left < right){
            if(nums[left] < nums[right]){
                return nums[left];
            }
            int mid = (right - left) / 2 + left;
            if(nums[right] > nums[mid]){
                right = mid;
            } else{
                left = mid + 1;
            }
        }
        return nums[left];
    }
};
// @lc code=end

