/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        for(int i=1;i<=numRows;i++){
            vector<int> temp;
            for(int j=0;j<i;j++){
                if(j == 0 || j == i-1){
                    temp.push_back(1);
                } else{
                    vector<int> last = result[result.size()-1];
                    temp.push_back(last[j-1] + last[j]);
                }
            }
            result.push_back(temp);
        }
        return result;
    }
};
// @lc code=end

