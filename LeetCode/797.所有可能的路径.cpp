/*
 * @lc app=leetcode.cn id=797 lang=cpp
 *
 * [797] 所有可能的路径
 */

// @lc code=start
class Solution {
private:
    vector<vector<int> > result;
    vector<int> path;
public:
    void DFS(vector<vector<int>>& graph, int node){
        if(node == graph.size()-1){
            result.push_back(path);
            return;
        }
        for(int i=0;i<graph[node].size();i++){
            path.push_back(graph[node][i]);
            DFS(graph, graph[node][i]);
            path.pop_back();
        }
    }
    vector<vector<int> > allPathsSourceTarget(vector<vector<int>>& graph) {
        path.push_back(0);
        DFS(graph,0);
        return result;
    }
};
// @lc code=end

