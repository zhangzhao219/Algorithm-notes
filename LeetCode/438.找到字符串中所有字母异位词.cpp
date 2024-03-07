/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
class Solution {
public:
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
            if(judgemp(mp)){
                result.push_back(left);
            }
            mp[s[left]] += 1;
            left += 1;
        }
        return result;
    }
};
// @lc code=end

