/*
 * @lc app=leetcode.cn id=417 lang=cpp
 *
 * [417] 太平洋大西洋水流问题
 */

// @lc code=start
class Solution {
private:
    vector<vector<bool> > visit_p;
    vector<vector<bool> > visit_a;
public:
    void BFS(vector<vector<int> >& heights, vector<vector<bool> >& visit, int i, int j, int m, int n){
        visit[i][j] = true;
        queue<pair<int, int> > q;
        q.push({i,j});
        while(!q.empty()){
            pair<int, int> cur = q.front();
            q.pop();
            int x = cur.first;
            int y = cur.second;
            if(x-1 >= 0 && visit[x-1][y] == false && heights[x-1][y] >= heights[x][y]){
                visit[x-1][y] = true;
                q.push({x-1,y});
            }
            if(x+1 < m && visit[x+1][y] == false && heights[x+1][y] >= heights[x][y]){
                visit[x+1][y] = true;
                q.push({x+1,y});
            }
            if(y-1 >= 0 && visit[x][y-1] == false && heights[x][y-1] >= heights[x][y]){
                visit[x][y-1] = true;
                q.push({x,y-1});
            }
            if(y+1 < n && visit[x][y+1] == false && heights[x][y+1] >= heights[x][y]){
                visit[x][y+1] = true;
                q.push({x,y+1});
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        for(int i=0;i<m;i++){
            visit_p.push_back(vector<bool>(n));
            visit_a.push_back(vector<bool>(n));
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i == 0 || j == 0){
                    BFS(heights, visit_p, i,j,m,n);
                }
                if(i == m-1 || j == n-1){
                    BFS(heights, visit_a, i,j,m,n);
                }
            }
        }
        vector<vector<int> > result;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(visit_p[i][j] == true && visit_a[i][j] == true){
                    result.push_back(vector<int>{i,j});
                }
            }
        }
        return result;
    }
};
// @lc code=end

