/*
 * @lc app=leetcode.cn id=350 lang=cpp
 *
 * [350] 两个数组的交集 II
 */

// @lc code=start
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        unordered_map<int, int> mp1;
        unordered_map<int, int> mp2;
        for(int i=0;i<nums1.size();i++){
            mp1[nums1[i]] += 1;
        }
        for(int i=0;i<nums2.size();i++){
            mp2[nums2[i]] += 1;
        }
        for(auto it = mp1.begin();it != mp1.end(); it++){
            if(mp2.find(it->first) != mp2.end()){
                for(int i=0;i<min(mp2[it->first],it->second);i++){
                    result.push_back(it->first);
                }
            }
        }
        return result;
    }
};
// @lc code=end

