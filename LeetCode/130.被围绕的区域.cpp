/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 */

// @lc code=start
class Solution {
private:
    vector<vector<bool> > isvisit;
public:
    void BFS(vector<vector<char>>& board, int i, int j, int m, int n){
        queue<pair<int,int> > q;
        q.push({i,j});
        isvisit[i][j] = true;
        while(!q.empty()){
            pair<int,int> cur = q.front();
            q.pop();
            int x = cur.first;
            int y = cur.second;
            if(x-1 >= 0 && board[x-1][y] == 'O' && isvisit[x-1][y] == false){
                isvisit[x-1][y] = true;
                q.push({x-1,y});
            }
            if(x+1 < m && board[x+1][y] == 'O' && isvisit[x+1][y] == false){
                isvisit[x+1][y] = true;
                q.push({x+1,y});
            }
            if(y-1 >= 0 && board[x][y-1] == 'O' && isvisit[x][y-1] == false){
                isvisit[x][y-1] = true;
                q.push({x,y-1});
            }
            if(y+1 < n && board[x][y+1] == 'O' && isvisit[x][y+1] == false){
                isvisit[x][y+1] = true;
                q.push({x,y+1});
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        for(int i=0;i<m;i++){
            isvisit.push_back(vector<bool>(n));
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i != 0 && i != m-1 && j != 0 && j != n-1){
                    continue;
                }
                if(board[i][j] == 'O' && isvisit[i][j] == false){
                    BFS(board,i,j,m,n);
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j] == 'O' && isvisit[i][j] == false){
                    board[i][j] = 'X';
                }
            }
        }
        return;
    }
};
// @lc code=end

