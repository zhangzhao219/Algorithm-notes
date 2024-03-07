/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
class Solution {
public:

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string> > result;
        unordered_map<string, vector<string> > mp;
        int arraylen = strs.size();
        for(int i=0;i<arraylen;i++){
            string t = strs[i];
            sort(t.begin(),t.end());
            mp[t].push_back(strs[i]);
        }
        for(auto it = mp.begin(); it != mp.end(); it++){
            result.push_back(it->second);
        }
        return result;
    }
};
// @lc code=end

