/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
class Solution {
public:
    void DFS(vector<vector<char>>& grid, vector<vector<bool> > & visited, int i, int j, int m, int n){
        if(i < 0 || i >= m || j < 0 || j >= n || visited[i][j] == true || grid[i][j] == '0'){
            return;
        }
        visited[i][j] = true;
        DFS(grid, visited, i-1, j, m, n);
        DFS(grid, visited, i+1, j, m, n);
        DFS(grid, visited, i, j-1, m, n);
        DFS(grid, visited, i, j+1, m, n);
    }
    int numIslands(vector<vector<char>>& grid) {
        int sum = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool> > visited(m, vector<bool>(n, false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(visited[i][j] == false && grid[i][j] == '1'){
                    DFS(grid, visited, i, j, m, n);
                    sum += 1;
                }
            }
        }
        return sum;

    }
};
// @lc code=end

