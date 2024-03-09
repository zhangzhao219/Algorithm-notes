/*
 * @lc app=leetcode.cn id=827 lang=cpp
 *
 * [827] 最大人工岛
 */

// @lc code=start
class Solution {
private:
    int numindex = 2;
    unordered_map<int, int> mp;
public:
    void BFS(vector<vector<int>>& grid, int i, int j, int n, int numindex){
        queue<pair<int, int> > q;
        q.push({i,j});
        int nowcount = 1;
        grid[i][j] = numindex;
        while(!q.empty()){
            pair<int, int> cur = q.front();
            q.pop();
            int x = cur.first;
            int y = cur.second;
            if(x-1 >= 0 && grid[x-1][y] == 1){
                q.push({x-1,y});
                nowcount += 1;
                grid[x-1][y] = numindex;
            }
            if(y-1 >= 0 && grid[x][y-1] == 1){
                q.push({x,y-1});
                nowcount += 1;
                grid[x][y-1] = numindex;
            }
            if(x+1 < n && grid[x+1][y] == 1){
                q.push({x+1,y});
                nowcount += 1;
                grid[x+1][y] = numindex;
            }
            if(y+1 < n && grid[x][y+1] == 1){
                q.push({x,y+1});
                nowcount += 1;
                grid[x][y+1] = numindex;
            }
        }
        mp[numindex] = nowcount;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    BFS(grid,i,j,n,numindex);
                    numindex += 1;
                }
            }
        }
        mp[0] = 0;
        int maxarea = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int area = 0;
                if(grid[i][j] == 0){
                    area += 1;
                }
                unordered_map<int,bool> mp2;
                mp2[grid[i][j]] = true;
                area += mp[grid[i][j]];
                if(i-1 >= 0 && mp2.find(grid[i-1][j]) == mp2.end()){
                    mp2[grid[i-1][j]] = true;
                    area += mp[grid[i-1][j]];
                }
                if(j-1 >= 0 && mp2.find(grid[i][j-1]) == mp2.end()){
                    mp2[grid[i][j-1]] = true;
                    area += mp[grid[i][j-1]];
                }
                if(i+1 < n && mp2.find(grid[i+1][j]) == mp2.end()){
                    mp2[grid[i+1][j]] = true;
                    area += mp[grid[i+1][j]];
                }
                if(j+1 < n && mp2.find(grid[i][j+1]) == mp2.end()){
                    mp2[grid[i][j+1]] = true;
                    area += mp[grid[i][j+1]];
                }
                maxarea = max(maxarea, area);
            }
        }
        return maxarea;
    }
};
// @lc code=end

