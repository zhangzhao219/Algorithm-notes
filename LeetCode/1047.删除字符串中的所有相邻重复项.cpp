/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 *
 * [1047] 删除字符串中的所有相邻重复项
 */

// @lc code=start
class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++){
            char a = s[i];
            if(st.empty()){
                st.push(a);
                continue;
            }
            if(st.top() == a){
                st.pop();
            } else{
                st.push(a);
            }
        }
        vector<char> c;
        while(!st.empty()){
            c.push_back(st.top());
            st.pop();
        }
        string s2 = "";
        for(int i=c.size()-1;i>=0;i--){
            s2 += c[i];
        }
        return s2;
    }
};
// @lc code=end

