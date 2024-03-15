/*
 * @lc app=leetcode.cn id=860 lang=cpp
 *
 * [860] 柠檬水找零
 */

// @lc code=start
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        map<int,int> mp;
        mp[5] = 0;
        mp[10] = 0;
        for(int i=0;i<bills.size();i++){
            if(bills[i] == 5){
                mp[5] += 1;
            } else if (bills[i] == 10){
                if(mp[5] <= 0){
                    return false;
                }
                mp[5] -= 1;
                mp[10] += 1;
            } else{
                if(mp[10] >= 1 && mp[5] >= 1){
                    mp[5] -= 1;
                    mp[10] -= 1;
                } else if(mp[5] >= 3){
                    mp[5] -= 3;
                } else{
                    return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end

