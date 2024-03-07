/*
 * @lc app=leetcode.cn id=454 lang=cpp
 *
 * [454] 四数相加 II
 */

// @lc code=start
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map <int, int> mp;
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                mp[nums1[i] + nums2[j]] += 1;
            }
        }
        int count_result = 0;
        for(int i=0;i<nums3.size();i++){
            for(int j=0;j<nums4.size();j++){
                if(mp.find(0-nums3[i]-nums4[j]) != mp.end()){
                    count_result += mp[0-nums3[i]-nums4[j]];
                }
            }
        }
        return count_result;
    }
};
// @lc code=end

