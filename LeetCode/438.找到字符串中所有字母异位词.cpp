/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> schar(26, 0);
        for(int i=0;i<p.size();i++){
            schar[p[i]-'a'] += 1;
        }
        vector<int> result;
        if(p.size() > s.size()){
            return result;
        }
        int left = 0;
        for(int right = 0;right < s.size();right++){
            schar[s[right]-'a'] -= 1;
            if (right < p.size()-1){
                continue;
            }
            bool flag = false;
            for(int i=0;i<26;i++){
                if(schar[i] != 0){
                    flag = true;
                    break;
                }
            }
            if(flag == false){
                result.push_back(left);
            }
            schar[s[left]-'a'] += 1;
            left += 1;
        }
        return result;
    }
};
// @lc code=end

