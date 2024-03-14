/*
 * @lc app=leetcode.cn id=491 lang=cpp
 *
 * [491] 非递减子序列
 */

// @lc code=start
class Solution {
public:
    vector<vector<int> > result;
    vector<int> temp;
    bool judge(vector<int> t){
        for(int i=0;i<t.size()-1;i++){
            if(t[i+1] <= t[i]){
                return false;
            }
        }
        return true;
    }
    void backtracking(vector<int>& nums, int startIndex) {
        if (temp.size() > 1) {
            result.push_back(temp);
        }
        unordered_set<int> uset; 
        for (int i = startIndex; i < nums.size(); i++) {
            if ((!temp.empty() && nums[i] < temp.back())
                    || uset.find(nums[i]) != uset.end()) {
                    continue;
            }
            uset.insert(nums[i]);
            temp.push_back(nums[i]);
            backtracking(nums, i + 1);
            temp.pop_back();
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backtracking(nums,0);
        return result;
    }
};
// @lc code=end

