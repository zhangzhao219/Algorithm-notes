/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 */

// @lc code=start
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> mp;
        for(int i=0;i<ransomNote.size();i++){
            mp[ransomNote[i]] += 1;
        }
        for(int i=0;i<magazine.size();i++){
            mp[magazine[i]] -= 1;
        }
        for(auto it = mp.begin(); it != mp.end();it++){
            if(it->second > 0){
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

