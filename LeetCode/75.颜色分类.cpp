/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */

// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0;
        for(int right = 0;right < nums.size();right++){
            if(nums[right] == 0){
                swap(nums[left], nums[right]);
                left += 1;
            }
        }
        left = nums.size() - 1;
        for(int right = nums.size()-1;right >= 0; right--){
            if(nums[right] == 2){
                swap(nums[left], nums[right]);
                left -= 1;
            }
        }
    }
};
// @lc code=end

