/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int n = s.size();
        int result = 0;
        int left = 0;
        for(int right=0;right < s.size();right++){
            if(st.count(s[right]) == 0){
                st.insert(s[right]);
                result = max(result, right - left + 1);
                continue;
            }
            while(left < right && st.count(s[right]) != 0){
                st.erase(s[left]);
                left++;
            }
            st.insert(s[right]);
        }
        return result;
    }
};
// @lc code=end

