/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int i = 0;
        int j = n - 1;
        while(i <= m-1 && j >= 0){
            if(matrix[i][j] == target){
                return true;
            } else if(matrix[i][j] < target){
                i += 1;
            } else{
                j -= 1;
            }
        }
        return false;
    }
};
// @lc code=end

