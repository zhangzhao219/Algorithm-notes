/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start
class Solution {
public:
    static bool cmp(int a, int b){
        return a > b;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]] += 1;
        }
        vector<int> temp;
        for(auto it = mp.begin(); it != mp.end();it++){
            temp.push_back(it->second);
        }
        sort(temp.begin(), temp.end(), cmp);
        int sign = temp[k-1];
        vector<int> result;
        for(auto it = mp.begin(); it != mp.end();it++){
            if(it->second >= sign){
                result.push_back(it->first);
            }
        }
        return result;
    }
};
// @lc code=end

