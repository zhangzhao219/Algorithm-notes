/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] 无重叠区间
 */

// @lc code=start
class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b){
        if(a[1] == b[1]){
            return a[0] < b[0];
        }
        return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int result = 0;
        sort(intervals.begin(), intervals.end(), cmp);
        int nowend = intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0] < nowend){
                result += 1;
            } else{
                nowend = intervals[i][1];
            }
        }
        return result;
    }
};
// @lc code=end

