/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int sign = -1;
        for(int i=n-1;i>0;i--){
            if(nums[i-1] < nums[i]){
                sign = i-1;
                break;
            }
        }
        if(sign == -1){
            reverse(nums.begin(),nums.end());
            return;
        }
        int sign2 = 0;
        for(int i=n-1;i>0;i--){
            if(nums[i] > nums[sign]){
                sign2 = i;
                break;
            }
        }
        swap(nums[sign], nums[sign2]);
        reverse(nums.begin()+sign+1,nums.end());
        return;
    }
};
// @lc code=end

