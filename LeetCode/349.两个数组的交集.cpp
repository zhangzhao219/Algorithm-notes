/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */

// @lc code=start
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        unordered_map<int, bool> mp1;
        unordered_map<int, bool> mp2;
        for(int i=0;i<nums1.size();i++){
            mp1[nums1[i]] = true;
        }
        for(int i=0;i<nums2.size();i++){
            mp2[nums2[i]] = true;
        }
        for(auto it = mp1.begin();it != mp1.end(); it++){
            if(mp2.find(it->first) != mp2.end()){
                result.push_back(it->first);
            }
        }
        return result;
    }
};
// @lc code=end

