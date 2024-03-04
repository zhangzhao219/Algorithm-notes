/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int> > res(n, vector<int>(n));
        int num = 1;
        int x = 0;
        int y = -1;
        while(num <= n * n){
            while(num <= n*n && y+1 < n && res[x][y+1] == 0){
                y += 1;
                res[x][y] = num;
                num += 1;
                
            }
            while(num <= n*n && x+1 < n && res[x+1][y] == 0){
                x += 1;
                res[x][y] = num;
                num += 1;
            }
            while(num <= n*n && y-1 >= 0 && res[x][y-1] == 0){
                y -= 1;
                res[x][y] = num;
                num += 1;
            }
            while(num <= n*n && x-1 >= 0 && res[x-1][y] == 0){
                x -= 1;
                res[x][y] = num;
                num += 1;
            }
        }
        return res;
    }
};
// @lc code=end

