/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start
class Solution {
public:
    vector<vector<string> > result;
    vector<int> temp;
    bool judge(int now, int end){
        int now_size = temp.size();
        for(int i=0;i<now_size;i++){
            if(now == temp[i]){
                return false;
            }
        }
        int x = now_size - 1;
        int y = now - 1;
        while(x >= 0 && y >= 0){
            if(temp[x] == y){
                return false;
            }
            x -= 1;
            y -= 1;
        }
        x = now_size - 1;
        y = now + 1;
        while(x >= 0 && y < end){
            if(temp[x] == y){
                return false;
            }
            x -= 1;
            y += 1;
        }
        return true;
    }
    void backtracking(int start, int end){
        if(start == end){
            vector<string> s;
            for(int i=0;i<end;i++){
                int a = temp[i];
                string temp_s = "";
                for(int j=0;j<end;j++){
                    if(j == a){
                        temp_s += "Q";
                    } else{
                        temp_s += ".";
                    }
                }
                s.push_back(temp_s);
            }
            result.push_back(s);
            return;
        }
        for(int i=0;i<end;i++){
            if(judge(i,end)){
                temp.push_back(i);
                backtracking(start+1, end);
                temp.pop_back();
            }
        }
    }
    vector<vector<string> > solveNQueens(int n) {
        backtracking(0,n);
        return result;
    }
};
// @lc code=end

