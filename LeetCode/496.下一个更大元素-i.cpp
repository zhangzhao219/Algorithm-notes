/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
 */

// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result(nums1.size(),-1);
        stack<int> st;
        unordered_map<int, int> mp;
        for(int i=0;i<nums1.size();i++){
            mp[nums1[i]] = i;
        }
        for(int i=0;i<nums2.size();i++){
            while(!st.empty() && st.top() < nums2[i]){
                if(mp.find(st.top()) != mp.end()){
                    result[mp[st.top()]] = nums2[i];
                }
                st.pop();
            }
            st.push(nums2[i]);
        }
        return result;
    }
};
// @lc code=end

