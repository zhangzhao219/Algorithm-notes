/*
 * @lc app=leetcode.cn id=463 lang=cpp
 *
 * [463] 岛屿的周长
 */

// @lc code=start
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int result = 0;
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    result += 4;
                    if(i-1 >= 0 && grid[i-1][j] == 1){
                        result -= 1;
                    }
                    if(j-1 >= 0 && grid[i][j-1] == 1){
                        result -= 1;
                    }
                    if(i+1 < m && grid[i+1][j] == 1){
                        result -= 1;
                    }
                    if(j+1 < n && grid[i][j+1] == 1){
                        result -= 1;
                    }
                }
            }
        }
        return result;
    }
};
// @lc code=end

