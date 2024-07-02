/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */

// @lc code=start
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n,0);
        stack<int> st;
        for(int i=0;i<temperatures.size();i++){
            while(!st.empty() && temperatures[st.top()] < temperatures[i]){
                result[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        return result;
    }
};
// @lc code=end

