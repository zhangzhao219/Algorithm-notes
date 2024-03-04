#include <bits/stdc++.h>
using namespace std;

string minWindow(string s, string t) {
    map<char,int> mp;
    int zero_count = 0;
    for (int i=0;i<t.size();i++){
        mp[t[i]] += 1;
        if (mp[t[i]] == 1){
            zero_count += 1;
        } 
    }
    int min_begin = 0;
    int min_end = s.size();
    int left = 0;
    for(int right=0;right < s.size();right += 1){
        
        mp[s[right]]--;
        if (mp[s[right]] == 0){
            zero_count -= 1;
        }
        while(zero_count == 0){
            if (right - left < min_end - min_begin){
                min_end = right;
                min_begin = left;
            }
            if(mp[s[left]] == 0){
                zero_count = 1;
            }
            mp[s[left]] += 1;
            left += 1;
        }

    }
    if (zero_count == 0){
        return s.substr(min_begin,min_end-min_begin+1);
    }
    return "";
}

int main(){
    string s = "a";
    string t = "aa";
    cout << minWindow(s,t) << endl;
}