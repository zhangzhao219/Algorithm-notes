/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 */

// @lc code=start
class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> result;
        int n = s.size();
        vector<int> alphabet(26,0);
        for(int i=0;i<s.size();i++){
            alphabet[s[i] - 'a'] = i;
        }
        int start = 0;
        int end = 0;
        for(int i=0;i<s.size();i++){
            end = max(end, alphabet[s[i] - 'a']);
            if(i == end){
                result.push_back(end - start + 1);
                start = end + 1;
            }
        }
        return result;
    }
};
// @lc code=end

