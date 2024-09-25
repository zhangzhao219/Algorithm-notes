#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
    set<char> st;
    int left = 0;
    int maxlen = 0;
    for(int right = 0;right < s.size(); right++){
        while(st.count(s[right]) != 0){
            st.erase(s[left]);
            left += 1;
        }
        maxlen = max(maxlen, right - left + 1);
        st.insert(s[right]);
    }
    return maxlen;
}
int main(){
    string s = "abcabcbb";
    int result = lengthOfLongestSubstring(s);
    cout << result << endl;
    return 0;
}