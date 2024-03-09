/*
 * @lc app=leetcode.cn id=1254 lang=cpp
 *
 * [1254] 统计封闭岛屿的数目
 */

// @lc code=start
class Solution {
private:
    vector<vector<bool> > isvisit;
public:
    void BFS(vector<vector<int>>& grid, int i, int j, int m, int n){
        queue<pair<int,int> > q;
        q.push({i,j});
        isvisit[i][j] = true;
        while(!q.empty()){
            pair<int,int> cur = q.front();
            q.pop();
            int x = cur.first;
            int y = cur.second;
            if(x-1 >= 0 && grid[x-1][y] == 0 && isvisit[x-1][y] == false){
                isvisit[x-1][y] = true;
                q.push({x-1,y});
            }
            if(x+1 < m && grid[x+1][y] == 0 && isvisit[x+1][y] == false){
                isvisit[x+1][y] = true;
                q.push({x+1,y});
            }
            if(y-1 >= 0 && grid[x][y-1] == 0 && isvisit[x][y-1] == false){
                isvisit[x][y-1] = true;
                q.push({x,y-1});
            }
            if(y+1 < n && grid[x][y+1] == 0 && isvisit[x][y+1] == false){
                isvisit[x][y+1] = true;
                q.push({x,y+1});
            }
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0;i<m;i++){
            isvisit.push_back(vector<bool>(n));
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i != 0 && j != 0 && i != m-1 && j != n-1){
                    continue;
                }
                if(grid[i][j] == 0){
                    BFS(grid,i,j,m,n);
                }
            }
        }
        int result = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 0 && isvisit[i][j] == false){
                    BFS(grid,i,j,m,n);
                    result += 1;
                }
            }
        }
        return result;
    }
};
// @lc code=end

