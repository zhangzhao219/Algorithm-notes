/*
 * @lc app=leetcode.cn id=1971 lang=cpp
 *
 * [1971] 寻找图中是否存在路径
 */

// @lc code=start
class Solution {
private:
    vector<int> father;
public:
    int findfather(int a){
        if(a == father[a]){
            return a;
        }
        return father[a] = findfather(father[a]);
    }
    void join(int a, int b){
        a = findfather(a);
        b = findfather(b);
        if(a == b){
            return;
        }
        father[a] = b;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        for(int i=0;i<n;i++){
            father.push_back(i);
        }
        for(int i=0;i<edges.size();i++){
            join(edges[i][0], edges[i][1]);
        }
        if(findfather(source) == findfather(destination)){
            return true;
        }
        return false;
    }
};
// @lc code=end

