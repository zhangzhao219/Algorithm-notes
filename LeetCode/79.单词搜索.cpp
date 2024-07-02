/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

// @lc code=start
class Solution {
private:
    bool sign = false;
    string temp = "";
public:
    void backtracking(vector<vector<char>>& board, vector<vector<bool> > &visited, string word, int i, int j, int m, int n, int now){
        if(temp == word){
            sign = true;
            return;
        }
        if(now >= word.size()){
            return;
        }
        if(i < 0 || i >= m || j < 0 || j >= n){
            return;
        }
        if(visited[i][j] == true){
            return;
        }
        if(board[i][j] != word[now]){
            return;
        }
        visited[i][j] = true;
        string t = temp;
        temp += board[i][j];
        backtracking(board, visited, word, i+1, j, m, n, now+1);
        backtracking(board, visited, word, i-1, j, m, n, now+1);
        backtracking(board, visited, word, i, j+1, m, n, now+1);
        backtracking(board, visited, word, i, j-1, m, n, now+1);
        temp = t;
        visited[i][j] = false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                vector<vector<bool> > visited(m, vector<bool>(n,false));
                temp = "";
                backtracking(board, visited, word, i, j, m, n, 0);
                if(sign == true){
                    return true;
                }
            }
        }
        return false;
    }
};
// @lc code=end

// A B C E
// S F E S
// A D E E

// ABCESEEEFS