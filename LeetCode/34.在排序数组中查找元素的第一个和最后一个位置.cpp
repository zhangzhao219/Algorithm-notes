/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
public:
    int lowerbound(vector<int>& nums, int target){
        int left = 0;
        int leftBorder = -2;
        int right = nums.size() - 1;
        while(left <= right){
            int mid = (right - left) / 2 + left;
            if(nums[mid] >= target){
                right = mid - 1;
                leftBorder = right;
            } else{
                left = mid + 1;
            }
        }
        return leftBorder;
    }
    int upperbound(vector<int>& nums, int target){
        int left = 0;
        int rightBorder = -2;
        int right = nums.size() - 1;
        while(left <= right){
            int mid = (right - left) / 2 + left;
            if(nums[mid] > target){
                right = mid - 1;
            } else{
                left = mid + 1;
                rightBorder = left;
            }
        }
        return rightBorder;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int leftBorder = lowerbound(nums, target);
        int rightBorder = upperbound(nums,target);
        if (leftBorder == -2 || rightBorder == -2){
            return vector<int>{-1,-1};
        }
        if (rightBorder - leftBorder > 1){
            return vector<int>{leftBorder + 1, rightBorder - 1};
        }
        return vector<int>{-1, -1};
    }
};
// @lc code=end

