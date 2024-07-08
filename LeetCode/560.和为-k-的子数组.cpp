/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为 K 的子数组
 */

// @lc code=start
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> pre(nums.size()+1,0);
        for(int i=1;i<=nums.size();i++){
            pre[i] = pre[i-1] + nums[i-1];
        }
        int ans = 0;
        for(int i=1;i<=nums.size();i++){
            int now = pre[i] - k;
            for(int j=0;j<i;j++){
                if(now == pre[j]){
                    ans += 1;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

