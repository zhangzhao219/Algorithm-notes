/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++){
            char a = s[i];
            if(a == '[' || a == '(' || a == '{'){
                st.push(a);
            } else{
                if(st.empty()){
                    return false;
                }
                if(a == ']' && st.top() == '['){
                    st.pop();
                } else if (a == '}' && st.top() == '{'){
                    st.pop();
                } else if (a == ')' && st.top() == '('){
                    st.pop();
                } else{
                    return false;
                }
            }
        }
        return st.empty();
    }
};
// @lc code=end

