/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */

// @lc code=start
class Solution {
private:
    vector<vector<int> > result;
    vector<int> temp;
public:
    void backtracking(int start, int end, int k, int n){
        if(temp.size() == k){
            int tempsum = 0;
            for(int i=0;i<k;i++){
                tempsum += temp[i];
            }
            if(tempsum == n){
                result.push_back(temp);
                return;
            }
        } else if(temp.size() > k){
            return;
        }
        for(int i=start;i<=end;i++){
            temp.push_back(i);
            backtracking(i+1,9,k,n);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        backtracking(1,9,k,n);
        return result;
    }
};
// @lc code=end

