/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b){
        if(a[0] == b[0]){
            return a[1] < b[1];
        }
        return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int> > result;
        sort(intervals.begin(), intervals.end(), cmp);
        bool now = false;
        int start = intervals[0][0];
        int end = intervals[0][1];
        for(int i=0;i<intervals.size();i++){
            if(intervals[i][0] > end){
                result.push_back(vector<int>{start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            } else{
                start = min(start, intervals[i][0]);
                end = max(end, intervals[i][1]);
            }
        }
        result.push_back(vector<int>{start, end});
        return result;
    }
};
// @lc code=end

