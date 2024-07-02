/*
 * @lc app=leetcode.cn id=994 lang=cpp
 *
 * [994] 腐烂的橘子
 */

// @lc code=start
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int minpath = 0;
        queue<pair<int, int> > q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 2){
                    visited[i][j] = true;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            minpath += 1;
            int s = q.size();
            for(int i=0;i<s;i++){
                pair<int, int> p = q.front();
                q.pop();
                int pi = p.first;
                int pj = p.second;
                if(pi-1 >= 0 && visited[pi-1][pj] == false && grid[pi-1][pj] == 1){
                    visited[pi-1][pj] = true;
                    grid[pi-1][pj] = 2;
                    q.push({pi-1,pj});
                }
                if(pj-1 >= 0 && visited[pi][pj-1] == false && grid[pi][pj-1] == 1){
                    visited[pi][pj-1] = true;
                    grid[pi][pj-1] = 2;
                    q.push({pi,pj-1});
                }
                if(pi+1 < m && visited[pi+1][pj] == false && grid[pi+1][pj] == 1){
                    visited[pi+1][pj] = true;
                    grid[pi+1][pj] = 2;
                    q.push({pi+1,pj});
                }
                if(pj+1 < n && visited[pi][pj+1] == false && grid[pi][pj+1] == 1){
                    visited[pi][pj+1] = true;
                    grid[pi][pj+1] = 2;
                    q.push({pi,pj+1});
                }
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }
        if(minpath == 0){
            return 0;
        }
        return minpath-1;
    }
};
// @lc code=end
