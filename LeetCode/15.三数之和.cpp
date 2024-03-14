/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > result;
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size();i++){
            int j = i + 1;
            int k = nums.size() - 1;
            if(i != 0 && nums[i] == nums[i-1]){
                continue;
            }
            while(j < k){
                if(nums[i] + nums[j] + nums[k] == 0){
                    result.push_back(vector<int>{nums[i], nums[j], nums[k]});
                    while(j < k && nums[j] == nums[j+1]){
                        j++;
                    }
                    while(j < k && nums[k] == nums[k-1]){
                        k--;
                    }
                    j++;
                    k--;
                } else if(nums[i] + nums[j] + nums[k] > 0){
                    k--;
                } else{
                    j++;
                }
            }
        }
        return result;
    }
};
// @lc code=end

