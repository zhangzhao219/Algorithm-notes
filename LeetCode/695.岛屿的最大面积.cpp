/*
 * @lc app=leetcode.cn id=695 lang=cpp
 *
 * [695] 岛屿的最大面积
 */

// @lc code=start
class Solution {
private:
    vector<vector<bool> > isvisit;
    int result = 0;
public:
    void BFS(vector<vector<int>>& grid, int i, int j, int m, int n, int nowsum){
        queue<pair<int,int> > q;
        q.push({i,j});
        isvisit[i][j] = true;
        while(!q.empty()){
            pair<int,int> cur = q.front();
            nowsum += 1;
            q.pop();
            int x = cur.first;
            int y = cur.second;
            if(x-1 >= 0 && grid[x-1][y] == 1 && isvisit[x-1][y] == false){
                isvisit[x-1][y] = true;
                q.push({x-1,y});
            }
            if(x+1 < m && grid[x+1][y] == 1 && isvisit[x+1][y] == false){
                isvisit[x+1][y] = true;
                q.push({x+1,y});
            }
            if(y-1 >= 0 && grid[x][y-1] == 1 && isvisit[x][y-1] == false){
                isvisit[x][y-1] = true;
                q.push({x,y-1});
            }
            if(y+1 < n && grid[x][y+1] == 1 && isvisit[x][y+1] == false){
                isvisit[x][y+1] = true;
                q.push({x,y+1});
            }
        }
        result = max(result,nowsum);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0;i<m;i++){
            isvisit.push_back(vector<bool>(n));
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1 && isvisit[i][j] == false){
                    BFS(grid,i,j,m,n,0);
                }
            }
        }
        return result;
    }
};
// @lc code=end

