/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int result = nums.size() + 1;
        int left = 0;
        int right = 0;
        int tempsum = 0;
        while(right < nums.size()){
            while(right < nums.size() && tempsum < target){
                tempsum += nums[right];
                right += 1;
            }
            while(tempsum >= target){
                tempsum -= nums[left];
                left += 1;
            }
            result = min(right - left + 1, result);
        }
        if (result == nums.size() + 1){
            return 0;
        }
        return result;
    }
};
// @lc code=end

