/*
 * @lc app=leetcode.cn id=685 lang=cpp
 *
 * [685] 冗余连接 II
 */

// @lc code=start
class Solution {
private:
    vector<int> father;
public:
    int findfather(int a){
        return a == father[a] ? a : father[a] = findfather(father[a]);
    }
    void join(int a, int b){
        a = findfather(a);
        b = findfather(b);
        if(a == b){
            return;
        }
        father[a] = b;
    }
    bool issamefather(int a, int b){
        a = findfather(a);
        b = findfather(b);
        if(a == b){
            return true;
        }
        return false;
    }
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        for(int i=0;i<n+1;i++){
            father.push_back(i);
        }
        for(int i=0;i<n;i++){
            int x = edges[i][0];
            int y = edges[i][1];
            if(issamefather(x,y)){
                return edges[i];
            }
            join(x,y);
        }
        return edges[0];
    }
};
// @lc code=end

