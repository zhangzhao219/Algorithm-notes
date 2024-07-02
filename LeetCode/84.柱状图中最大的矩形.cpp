/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */

// @lc code=start
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int result = 0;
        int n = heights.size();
        if(n == 1){
            return heights[0];
        }
        vector<int> minLeftIndex(n,0);
        vector<int> minRightIndex(n,0);
        minLeftIndex[0] = -1;
        for(int i=1;i<n;i++){
            int t = i - 1;
            while (t >= 0 && heights[t] >= heights[i]){
                t = minLeftIndex[t];
            }
            minLeftIndex[i] = t;
        }
        minRightIndex[n-1] = n;
        for(int i=n-2;i>=0;i--){
            int t = i + 1;
            while (t < n && heights[t] >= heights[i]){
                t = minRightIndex[t];
            }
            minRightIndex[i] = t;
        }
        for(int i=0;i<n;i++){
            result = max(result, heights[i] * (minRightIndex[i] - minLeftIndex[i] - 1));
        }
        return result;
    }
};
// @lc code=end

