/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        int result = 0;
        int leftMax = 0;
        int rightMax = 0;
        int left = 0;
        int right = height.size() - 1;
        while(left < right){
            leftMax = max(leftMax, height[left]);
            rightMax = max(rightMax, height[right]);
            if(height[left] < height[right]){
                result += leftMax - height[left];
                left += 1;
            } else{
                result += rightMax - height[right];
                right -= 1;
            }
        }
        return result;
    }
};
// @lc code=end

