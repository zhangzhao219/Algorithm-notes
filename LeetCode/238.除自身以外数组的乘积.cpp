/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 */

// @lc code=start
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> pre(nums.size()+1,1);
        vector<int> back(nums.size()+1,1);
        for(int i=0;i<nums.size();i++){
            pre[i+1] = nums[i] * pre[i];
        }
        for(int i=nums.size();i>0;i--){
            back[i-1] = nums[i-1] * back[i];
        }
        vector<int> result(nums.size(),0);
        for(int i=0;i<nums.size()+1;i++){
            cout << pre[i] << " " << back[i] << endl;
        }
        for(int i=0;i<nums.size();i++){
            result[i] = pre[i] * back[i+1];
        }
        return result;
    }
};
// @lc code=end

