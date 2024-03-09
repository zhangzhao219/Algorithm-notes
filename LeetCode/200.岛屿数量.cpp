/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
class Solution {
private:
    vector<vector<bool> > isvisit;
    int sumcount = 0;
public:
    void DFS(vector<vector<char>>& grid, int i, int j, int m, int n){
        if(i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == '0' || isvisit[i][j] == true){
            return;
        }
        isvisit[i][j] = true;
        DFS(grid,i-1,j,m,n);
        DFS(grid,i,j-1,m,n);
        DFS(grid,i+1,j,m,n);
        DFS(grid,i,j+1,m,n);
    }
    void BFS(vector<vector<char>>& grid, int i, int j, int m, int n){
        queue<pair<int, int> > q;
        q.push({i,j});
        isvisit[i][j] = true;
        while(!q.empty()){
            pair<int, int> cur = q.front();
            q.pop();
            int x = cur.first;
            int y = cur.second;
            if(x-1 >= 0 && grid[x-1][y] == '1' && isvisit[x-1][y] == false){
                q.push({x-1,y});
                isvisit[x-1][y] = true;
            }
            if(x+1 < m && grid[x+1][y] == '1' && isvisit[x+1][y] == false){
                q.push({x+1,y});
                isvisit[x+1][y] = true;
            }
            if(y-1 >= 0 && grid[x][y-1] == '1' && isvisit[x][y-1] == false){
                q.push({x,y-1});
                isvisit[x][y-1] = true;
            }
            if(y+1 < n && grid[x][y+1] == '1' && isvisit[x][y+1] == false){
                q.push({x,y+1});
                isvisit[x][y+1] = true;
            }
        }
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0;i<m;i++){
            isvisit.push_back(vector<bool>(n));
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(isvisit[i][j] == true || grid[i][j] == '0'){
                    continue;
                }
                BFS(grid, i,j,m,n);
                sumcount += 1;
            }
        }
        return sumcount;
    }
};
// @lc code=end

