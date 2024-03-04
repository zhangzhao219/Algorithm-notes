/*
 * @lc app=leetcode.cn id=367 lang=cpp
 *
 * [367] 有效的完全平方数
 */

// @lc code=start
class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num == 1){
            return true;
        }
        int left = 0;
        int right = num;
        while(left < right){
            int mid = left + (right - left) / 2;
            if ((long long)mid * mid == num){
                return true;
            } else if ((long long)mid * mid < num){
                left = mid + 1;
            } else{
                right = mid;
            }
        }
        return false;
    }
};
// @lc code=end

