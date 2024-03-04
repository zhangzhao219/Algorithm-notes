/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int left = 0;
        for(int right = 0;right < nums.size(); right += 1){
            if (nums[right] != val){
                nums[left] = nums[right];
                left += 1;
            }
        }
        return left;
    }
};
// @lc code=end

