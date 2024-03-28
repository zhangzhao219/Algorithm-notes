/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int result = 0;
        unordered_set<char> st;
        int left = 0;
        for(int right=0; right<s.size(); right++){
            while(st.find(s[right]) != st.end()){
                st.erase(s[left]);
                left++;
            }
            st.insert(s[right]);
            result = max(result, right - left + 1);
        }
        return result;
    }
};
// @lc code=end

