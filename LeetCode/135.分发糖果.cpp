/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] 分发糖果
 */

// @lc code=start
class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> temp(ratings.size(),1);
        for(int i=0;i<ratings.size();i++){
            if(i == 0){
                continue;
            }
            if(ratings[i] > ratings[i-1]){
                temp[i] = temp[i-1] + 1;
            }
        }
        for(int i=ratings.size()-1;i>=0;i--){
            if(i == ratings.size()-1){
                continue;
            }
            if(ratings[i] > ratings[i+1]){
                temp[i] = max(temp[i], temp[i+1] + 1);
            }
        }
        int totalsum = 0;
        for(int i=0;i<temp.size();i++){
            totalsum += temp[i];
        }
        return totalsum;
    }
};
// @lc code=end

