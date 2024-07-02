/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for(int start = 0; start < nums.size()-2;start += 1){
            if(start > 0 && nums[start] == nums[start - 1]){
                continue;
            }
            int left = start + 1;
            int right = nums.size() - 1;
            while(left < right){
                int res = nums[start] + nums[left] + nums[right];
                if(res == 0){
                    result.push_back(vector<int> {nums[start], nums[left], nums[right]});
                    while(left < right && nums[right] == nums[right-1]){
                        right -= 1;
                    }
                    while(left < right && nums[left] == nums[left + 1]){
                        left += 1;
                    }
                    left += 1;
                    right -= 1;
                } else if (res < 0){
                    left += 1;
                } else{
                    right -= 1;
                }
            }
        }
        return result;
    }
};
// @lc code=end

