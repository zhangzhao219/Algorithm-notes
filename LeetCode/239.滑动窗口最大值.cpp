/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> st;
        vector<int> result;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(!st.empty() && st.front() <= i-k){
                st.pop_front();
            }
            while(!st.empty() && nums[st.back()] < nums[i]){
                st.pop_back();
            }
            st.push_back(i);
            if(i >= k-1){
                result.push_back(nums[st.front()]);
            }
        }
        return result;
    }
};
// @lc code=end

