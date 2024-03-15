/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<bool> judge(nums.size(),false);
        judge[0] = true;
        for(int i=0;i<nums.size();i++){
            if(judge[i] == true){
                for(int j=i;j<=i+nums[i];j++){
                    if(j < nums.size()){
                        judge[j] = true;
                        if(judge[nums.size()-1] == true){
                            return true;
                        }
                    }
                }
            }
        }
        return judge[nums.size()-1];
    }
};
// @lc code=end

