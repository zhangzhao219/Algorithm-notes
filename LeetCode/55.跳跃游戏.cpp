/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int result = 0;
        for(int i=0;i<nums.size();i++){
            if (i <= result){
                result = max(result, i + nums[i]);
                if(result >= n - 1){
                    return true;
                }
            }
        }
        return false;
    }
};
// @lc code=end

