/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为 K 的子数组
 */

// @lc code=start
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pre(n+1,0);
        for(int i=1;i<=n;i++){
            pre[i] = nums[i-1] + pre[i-1];
        }
        for(int i=0;i<=n;i++){
            cout << pre[i] << " ";
        }
        cout << endl;
        unordered_map<int, int> cnt;
        int result = 0;
        for(int i=0; i<=n; i++){
            if (cnt.contains(pre[i] - k)){
                result += cnt[pre[i] - k];
            }
            cnt[pre[i]] += 1;
        }
        return result;
    }
};
// @lc code=end

