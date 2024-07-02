/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<bool> > visit(m, vector<bool>(n, false));
        vector<vector<int> > directions{
            {0,1},{1,0},{0,-1},{-1,0}
        };
        int xIndex = 0;
        int yIndex = 0;
        result.push_back(matrix[xIndex][yIndex]);
        visit[xIndex][yIndex] = true;
        while(result.size() != m*n){
            for(int i=0;i<directions.size();i++){
                while(xIndex + directions[i][0] >= 0 && xIndex + directions[i][0] < m && yIndex + directions[i][1] >= 0 && yIndex + directions[i][1] < n && visit[xIndex + directions[i][0]][yIndex + directions[i][1]] == false){
                    xIndex = xIndex + directions[i][0];
                    yIndex = yIndex + directions[i][1];
                    result.push_back(matrix[xIndex][yIndex]);
                    visit[xIndex][yIndex] = true;
                }
            }
        }
        return result;
    }
};
// @lc code=end

