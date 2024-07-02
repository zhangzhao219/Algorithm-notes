/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start
class Solution {
private:
    vector<vector<string>> result;
public:
    bool judge(vector<vector<char> > &board, int i, int j, int n){
        for(int p=0;p<i;p++){
            if(board[p][j] == 'Q'){
                return false;
            }
        }
        int l = i-1;
        int r = j-1;
        while(l >= 0 && r >= 0){
            if(board[l][r] == 'Q'){
                return false;
            }
            l--;
            r--;
        }
        l = i-1;
        r = j+1;
        while(l >= 0 && r < n){
            if(board[l][r] == 'Q'){
                return false;
            }
            l--;
            r++;
        }
        return true;
    }
    void backtracking(vector<vector<char> > &board, int start, int n){
        if(start == n){
            vector<string> vt;
            for(int i=0;i<n;i++){
                string temp = "";
                for(int j=0;j<n;j++){
                    temp += board[i][j];
                }
                vt.push_back(temp);
            }
            result.push_back(vt);
            return;
        }
        for(int i=0;i<n;i++){
            board[start][i] = 'Q';
            if(judge(board,start,i,n)){
                backtracking(board,start+1,n);
            }
            board[start][i] = '.';
        }
    }
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<char> > board(n, vector<char>(n, '.'));
        backtracking(board,0,n);
        return result; 
    }
};
// @lc code=end

// 输入：n = 4
// 输出：[[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
// 解释：如上图所示，4 皇后问题存在两个不同的解法。