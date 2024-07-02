/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int x = 0;
        int y = n-1;
        while(x < m && y >= 0){
            if (matrix[x][y] == target){
                return true;
            }
            if(target < matrix[x][y]){
                y -= 1;
            }
            else{
                x += 1;
            }
        }
        return false;
    }
};
// @lc code=end

