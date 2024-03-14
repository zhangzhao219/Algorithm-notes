/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution {
private:
    map<int, vector<string> > mp;
    vector<string> result;
    vector<string> temp;
public:
    void backtracking(string digits, int start, int end){
        if(temp.size() == end){
            string t;
            for(int i=0;i<end;i++){
                t += temp[i];
            }
            result.push_back(t);
            return;
        }
        for(int i=start;i<end;i++){
            int index = digits[i] - '0';
            vector<string> worddict = mp[index];
            for(int j=0;j<worddict.size();j++){
                temp.push_back(worddict[j]);
                backtracking(digits,i+1,digits.size());
                temp.pop_back();
            }
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0){
            return result;
        }
        mp[2] = vector<string>{"a","b","c"};
        mp[3] = vector<string>{"d","e","f"};
        mp[4] = vector<string>{"g","h","i"};
        mp[5] = vector<string>{"j","k","l"};
        mp[6] = vector<string>{"m","n","o"};
        mp[7] = vector<string>{"p","q","r","s"};
        mp[8] = vector<string>{"t","u","v"};
        mp[9] = vector<string>{"w","x","y","z"};
        backtracking(digits,0,digits.size());
        return result;
    }
};
// @lc code=end

