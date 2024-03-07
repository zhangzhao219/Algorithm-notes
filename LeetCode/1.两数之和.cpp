/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result(2);
        unordered_map<int, int> mp;
        for(int i=0;i<nums.size();i++){
            if(mp.find(target-nums[i]) != mp.end()){
                result[0] = i;
                result[1] = mp[target-nums[i]];
            } else{
                mp[nums[i]] = i;
            }
        }
        return result;
    }
};
// @lc code=end

