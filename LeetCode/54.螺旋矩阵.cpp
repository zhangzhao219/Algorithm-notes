/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> res(m*n);
        vector<vector<bool> > judge(m, vector<bool>(n));
        int x = 0;
        int y = -1;
        int index = 0;
        while(index < m * n){
            while(index < m * n && y+1 < n && judge[x][y+1] == false){
                y += 1;
                judge[x][y] = true;
                res[index] = matrix[x][y];
                index += 1;
            }
            while(index < m * n && x+1 < m && judge[x+1][y] == false){
                x += 1;
                judge[x][y] = true;
                res[index] = matrix[x][y];
                index += 1;
            }
            while(index < m * n && y-1 >= 0 && judge[x][y-1] == false){
                y -= 1;
                judge[x][y] = true;
                res[index] = matrix[x][y];
                index += 1;
            }
            while(index < m * n && x-1 >= 0 && judge[x-1][y] == false){
                x -= 1;
                judge[x][y] = true;
                res[index] = matrix[x][y];
                index += 1;
            }
        }
        return res;
    }
};
// @lc code=end

