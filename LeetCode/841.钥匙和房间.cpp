/*
 * @lc app=leetcode.cn id=841 lang=cpp
 *
 * [841] 钥匙和房间
 */

// @lc code=start
class Solution {
private:
    
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int lenrooms = rooms.size();
        vector<bool> isvisit(lenrooms);
        queue<int> q;
        q.push(0);
        isvisit[0] = true;
        while(!q.empty()){
            int t = q.front();
            q.pop();
            for(int i=0;i<rooms[t].size();i++){
                if (isvisit[rooms[t][i]] == false){
                    isvisit[rooms[t][i]] = true;
                    q.push(rooms[t][i]);
                }
            }
        }
        for(int i=0;i<lenrooms;i++){
            if(isvisit[i] == false){
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

