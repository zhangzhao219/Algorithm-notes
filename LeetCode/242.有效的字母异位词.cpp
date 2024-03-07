/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> mp;
        for(int i=0;i<s.length();i++){
            mp[s[i]] += 1;
        }
        for(int i=0;i<t.length();i++){
            mp[t[i]] -= 1;
        }
        for(auto it = mp.begin();it != mp.end();it++){
            if(it->second != 0){
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

