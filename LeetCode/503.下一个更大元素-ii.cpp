/*
 * @lc app=leetcode.cn id=503 lang=cpp
 *
 * [503] 下一个更大元素 II
 */

// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> numsall(nums.size()*2);
        for(int i=0;i<numsall.size();i++){
            numsall[i] = nums[i%nums.size()];
        }
        stack<int> st;
        vector<int> result(nums.size(),-1);
        for(int i=0;i<numsall.size();i++){
            while(!st.empty() && numsall[st.top()] < numsall[i]){
                if(result[st.top()%nums.size()] == -1){
                    result[st.top()%nums.size()] = numsall[i];
                }
                st.pop();
            }
            st.push(i);
        }
        return result;
    }
};
// @lc code=end

