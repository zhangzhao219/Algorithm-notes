/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        unordered_map<int, int> mp;
        for(int i=0;i<nums.size();i++){
            if(mp.find(target - nums[i]) == mp.end()){
                mp[nums[i]] = i;
                continue;
            }
            result.push_back(mp[target - nums[i]]);
            result.push_back(i);
            break;
        }
        return result;
    }
};
// @lc code=end

