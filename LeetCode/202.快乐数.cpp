/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

// @lc code=start
class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int,bool> mp;
        while(1){
            if(mp.find(n) != mp.end()){
                return false;
            }
            if(n == 1){
                return true;
            }
            mp[n] = true;
            int res = 0;
            while(n != 0){
                res += (n%10) * (n%10);
                n = n/10;
            }
            n = res;
        }
        return true;
    }
};
// @lc code=end

