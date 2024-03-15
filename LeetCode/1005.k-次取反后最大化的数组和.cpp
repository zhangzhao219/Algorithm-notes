/*
 * @lc app=leetcode.cn id=1005 lang=cpp
 *
 * [1005] K 次取反后最大化的数组和
 */

// @lc code=start
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        int maxsum = 0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size() && k > 0;i++,k--){
            if(nums[i] < 0){
                nums[i] = -nums[i];
            } else{
                break;
            }
        }
        for(int i=0;i<nums.size();i++){
            maxsum += nums[i];
        }
        if(k == 0 || k % 2 == 0){
            return maxsum;
        }
        int minvalue = nums[0];
        for(int i=0;i<nums.size();i++){
            minvalue = min(minvalue, nums[i]);
        }
        return maxsum - 2 * minvalue;
    }
};
// @lc code=end

