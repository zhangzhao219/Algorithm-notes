/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b){
        if(a[0] == b[0]){
            return a[1] < b[1];
        }
        return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int> > result;
        sort(intervals.begin(), intervals.end(), cmp);
        int nowstart = intervals[0][0];
        int nowend = intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0] <= nowend){
                nowstart = min(nowstart,intervals[i][0]);
                nowend = max(nowend,intervals[i][1]);
            } else{
                result.push_back(vector<int>{nowstart, nowend});
                nowstart = intervals[i][0];
                nowend = intervals[i][1];
            }
        }
        result.push_back(vector<int>{nowstart, nowend});
        return result;
    }
};
// @lc code=end

