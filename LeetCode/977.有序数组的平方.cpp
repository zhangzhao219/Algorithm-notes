/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */

// @lc code=start
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result;
        stack<int> temp;
        int left = 0;
        int right = nums.size() - 1;
        while(left < right){
            int a = nums[left] * nums[left];
            int b = nums[right] * nums[right];
            if (a < b){
                temp.push(b);
                right--;
            } else{
                temp.push(a);
                left++;
            }
        }
        result.push_back(nums[left] * nums[left]);
        while(!temp.empty()){
            result.push_back(temp.top());
            temp.pop();
        }
        return result;
    }
};
// @lc code=end

