#include <bits/stdc++.h>
using namespace std;

bool judgemp(unordered_map<char, int> mp){
    for(auto it = mp.begin();it != mp.end();it++){
        if(it->second != 0){
            return false;
        }
    }
    return true;
}
vector<int> findAnagrams(string s, string p) {
    vector<int> result;
    unordered_map<char, int> mp;
    for(int i=0;i<p.length();i++){
        mp[p[i]] += 1;
    }
    int left = 0;
    for(int right=0;right < s.length();right++){
        mp[s[right]] -= 1;
        if(right - left != p.length()-1){
            continue;
        }
        cout << right << endl;
        for(auto it = mp.begin();it != mp.end();it++){
            cout << it->first << " " << it->second << endl;
        }
        if(judgemp(mp)){
            result.push_back(left);
        }
        mp[s[left]] += 1;
        left += 1;
    }
    return result;
}

int main(){
    string s = "cbaebabacd";
    string t = "abc";
    vector<int> result = findAnagrams(s,t);
    for(int i=0;i<result.size();i++){
        cout << result[i] << endl;
    }
}