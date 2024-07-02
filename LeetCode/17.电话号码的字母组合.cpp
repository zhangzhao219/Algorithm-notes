/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution {
private:
    vector<string> result;
    vector<char> temp;
public:
    void backtracking(string digits, map<char, vector<char> > &mp, int start){
        if(start == digits.size()){
            string t = "";
            for(int i=0;i<temp.size();i++){
                t += temp[i];
            }
            result.push_back(t);
            return;
        }
        vector<char> now = mp[digits[start]];
        for(int i=0;i<now.size();i++){
            temp.push_back(now[i]);
            backtracking(digits, mp, start+1);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits == ""){
            return result;
        }
        map<char, vector<char> > mp;
        mp['2'] = vector<char>{'a', 'b', 'c'};
        mp['3'] = vector<char>{'d', 'e', 'f'};
        mp['4'] = vector<char>{'g', 'h', 'i'};
        mp['5'] = vector<char>{'j', 'k', 'l'};
        mp['6'] = vector<char>{'m', 'n', 'o'};
        mp['7'] = vector<char>{'p', 'q', 'r', 's'};
        mp['8'] = vector<char>{'t', 'u', 'v'};
        mp['9'] = vector<char>{'w', 'x', 'y', 'z'};
        backtracking(digits, mp, 0);
        return result;
    }
};
// @lc code=end

