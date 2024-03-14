/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int> > result;
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size();i++){
            if(i > nums.size()-4){
                break;
            }
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            for(int l=i+3;l<nums.size();l++){
                if(l < nums.size()-1 && nums[l] == nums[l+1]){
                    continue;
                }
                int j = i + 1;
                int k = l - 1;

                while(j < k){
                    if((long long)nums[i] + nums[j] + nums[k] + nums[l] == (long long)target){
                        result.push_back(vector<int>{nums[i], nums[j], nums[k], nums[l]});
                        while(j < k && nums[j] == nums[j+1]){
                            j++;
                        }
                        while(j < k && nums[k] == nums[k-1]){
                            k--;
                        }
                        j++;
                        k--;
                    } else if((long long)nums[i] + nums[j] + nums[k] + nums[l] > (long long)target){
                        k--;
                    } else{
                        j++;
                    }
                }
            }
        }
        return result;
    }
};
// @lc code=end

