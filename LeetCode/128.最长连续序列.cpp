/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */

// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, bool> mp;
        if(nums.size() == 0){
            return 0;
        }
        for(int i=0;i<nums.size();i++){
            mp[nums[i]] = true;
        }
        int maxcount = 0;
        for(int i=0;i<nums.size();i++){
            int tempcount = 0;
            int num = nums[i];
            if(mp.find(num-1) != mp.end()){
                continue;
            }
            while(mp.find(num) != mp.end()){
                num += 1;
                tempcount += 1;
            }
            maxcount = max(maxcount, tempcount);
        }
        return maxcount;
    }
};
// @lc code=end

