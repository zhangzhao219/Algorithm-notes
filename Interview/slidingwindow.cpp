#include <bits/stdc++.h>
using namespace std;

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
int main(){
    string s = "abcabcbb";
    int result = lengthOfLongestSubstring(s);
    cout << result << endl;
    return 0;
}