/*
 * @lc app=leetcode.cn id=2570 lang=cpp
 *
 * [2570] 合并两个二维数组 - 求和法
 */

// @lc code=start
class Solution {
public:
    static bool cmp(const vector<int> &a, const vector<int> &b){
        return a[0] < b[0];
    }
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        unordered_map<int, int> mp;
        for(int i=0;i<nums1.size();i++){
            if(mp.find(nums1[i][0]) != mp.end()){
                mp[nums1[i][0]] += nums1[i][1];
            } else{
                mp[nums1[i][0]] = nums1[i][1];
            }
        }
        for(int i=0;i<nums2.size();i++){
            if(mp.find(nums2[i][0]) != mp.end()){
                mp[nums2[i][0]] += nums2[i][1];
            } else{
                mp[nums2[i][0]] = nums2[i][1];
            }
        }
        vector<vector<int> > result;
        for(auto it = mp.begin(); it != mp.end();it++){
            result.push_back(vector<int> {it->first, it->second});
        }
        sort(result.begin(), result.end(), cmp);
        return result;
    }
};
// @lc code=end

