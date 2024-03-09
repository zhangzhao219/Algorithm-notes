/*
 * @lc app=leetcode.cn id=127 lang=cpp
 *
 * [127] 单词接龙
 */

// @lc code=start
class Solution {
private:
    int mincount = 0;
public:
    bool judgetwowords(string word1, string word2){
        int sumcount = 0;
        for(int i=0;i<word1.size();i++){
            if(word1[i] != word2[i]){
                sumcount += 1;
            }
            if(sumcount >= 2){
                return false;
            }
        }
        if(sumcount == 1){
            return true;
        }
        return false;
    }
    int BFS(vector<vector<int> >& grid, int start, int end){
        unordered_map<int, bool> visitMap;
        visitMap[start] = true;
        queue<int> q;
        q.push(start);
        int nowcount = 0;
        while(!q.empty()){
            int t = q.size();
            nowcount += 1;
            // cout << nowcount << " " << t << endl;
            for(int j=0;j<t;j++){
                int cur = q.front();
                q.pop();
                if(cur == end){
                    return nowcount;
                }
                for(int i=0;i<grid[cur].size();i++){
                    if(visitMap.find(grid[cur][i]) == visitMap.end()){
                        visitMap[grid[cur][i]] = true;
                        q.push(grid[cur][i]);
                    }
                }
            }
        }
        return 0;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int sign = -1;
        for(int i=0;i<wordList.size();i++){
            if(wordList[i] == endWord){
                sign = i+1;
            }
        }
        if(sign == -1){
            return 0;
        }
        vector<vector<int> > grid;
        vector<int> tempgrid;
        for(int i=0;i<wordList.size();i++){
            if(judgetwowords(wordList[i], beginWord)){
                // cout << i << "fgdgf" << endl;
                tempgrid.push_back(i+1);
            }
        }
        grid.push_back(tempgrid);
        for(int i=0;i<wordList.size();i++){
            vector<int> tempgrid2;
            // tempgrid2.push_back(i+2);
            for(int j=0;j<wordList.size();j++){
                if(i+1 == j+1){
                    continue;
                }
                if(judgetwowords(wordList[i], wordList[j])){
                    tempgrid2.push_back(j+1);
                }
            }
            grid.push_back(tempgrid2);
        }
        // for(int i=0;i<grid.size();i++){
        //     for(int j=0;j<grid[i].size();j++){
        //         cout << grid[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        int mincount = BFS(grid, 0, sign);
        return mincount;
    }
};
// @lc code=end

