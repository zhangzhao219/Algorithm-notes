/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
public:
    int searchbegin(vector<int>& nums, int target){
        int left = 0;
        int right = nums.size();
        while(left < right){
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target){
                right = mid;
            } else{
                left = mid + 1;
            }
        }
        if ((left < nums.size()) && (nums[left] == target)){
            return left;
        }
        return -1;
    }
    int searchend(vector<int>& nums, int target){
        int left = 0;
        int right = nums.size();
        while(left < right){
            int mid = left + (right - left) / 2;
            if (nums[mid] <= target){
                left = mid + 1;
            } else{
                right = mid;
            }
        }
        if ((right-1 >= 0) && (nums[right-1] == target)){
            return right-1;
        }
        return -1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result = {-1,-1};
        result[0] = searchbegin(nums, target);
        result[1] = searchend(nums, target);
        return result;
    }
};
// @lc code=end

