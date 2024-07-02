/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int result = 0;
        int right = 0;
        unordered_set<char> st;
        for(int left = 0;left < n;left++){
            while(right < n && !st.count(s[right])){
                st.insert(s[right]);
                right++;
            }
            result = max(result, right - left);
            st.erase(s[left]);
        }
        return result;
    }
};
// @lc code=end

