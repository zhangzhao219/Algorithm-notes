/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int result = 0;
        int left = 0;
        int right = height.size()-1;
        while(left < right){
            result = max(result, (right - left) * min(height[left], height[right]));
            cout << left << " " << right << " " << endl;
            if(height[left] < height[right]){
                left += 1;
            } else{
                right -= 1;
            }
        }
        return result;
    }
};
// @lc code=end
