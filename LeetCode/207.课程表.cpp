/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */

// @lc code=start
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int> > table(numCourses, vector<int>(0,0));
        vector<int> judge(numCourses,0);
        vector<bool> visit(numCourses,false);
        for(int i=0;i<prerequisites.size();i++){
            int pre = prerequisites[i][1];
            int post = prerequisites[i][0];
            table[pre].push_back(post);
            judge[post] += 1;
        }
        
        while(1){
            bool modify = false;
            for(int i=0;i<numCourses;i++){
                if(visit[i] == false && judge[i] == 0){
                    modify = true;
                    visit[i] = true;
                    for(int j=0;j<table[i].size();j++){
                        judge[table[i][j]] -= 1;
                    }
                }
            }
            if(modify == false){
                break;
            }
        }
        for(int i=0;i<numCourses;i++){
            if(judge[i] != 0){
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

