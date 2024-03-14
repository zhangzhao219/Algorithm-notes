/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */

// @lc code=start
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(int i=0;i<tokens.size();i++){
            string s = tokens[i];
            if(s == "+" || s == "-" || s == "*" || s == "/"){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                if(s == "+"){
                    st.push(a+b);
                } else if (s == "-"){
                    st.push(b - a);
                } else if(s == "*"){
                    st.push(a * b);
                } else{
                    st.push(b/a);
                }
            } else{
                st.push(atoi(s.c_str()));
            }
        }
        return st.top();
    }
};
// @lc code=end

