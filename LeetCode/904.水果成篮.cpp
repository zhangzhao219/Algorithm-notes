/*
 * @lc app=leetcode.cn id=904 lang=cpp
 *
 * [904] 水果成篮
 */

// @lc code=start
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int res = 0;
        int left = 0;
        map<int,int> mp;
        for(int right=0;right < fruits.size();right += 1){
            mp[fruits[right]]++;
            while (mp.size() > 2){
                mp[fruits[left]]--;
                if (mp[fruits[left]] == 0){
                    mp.erase(mp.find(fruits[left]));
                }
                left++;
            }
            res = max(res,right-left+1);
        }
        return res;
    }
};
// @lc code=end

