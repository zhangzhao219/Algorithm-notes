/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] 字符串解码
 */

// @lc code=start
class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(s[i] == ']'){
                vector<char> tempchar;
                vector<int> tempnum;
                while(st.top() != '['){
                    tempchar.push_back(st.top());
                    st.pop();
                }
                st.pop();
                while(!st.empty() && st.top() >= '0' && st.top() <= '9'){
                    tempnum.push_back(st.top() - '0');
                    st.pop();
                }
                int num = 0;
                for(int j=tempnum.size()-1;j>=0;j--){
                    num = num * 10 + tempnum[j];
                }
                for(int j=0;j<num;j++){
                    for(int k=tempchar.size()-1;k>=0;k--){
                        st.push(tempchar[k]);
                    }
                }
            }else{
                st.push(s[i]);
            }
        }
        string res;
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end

