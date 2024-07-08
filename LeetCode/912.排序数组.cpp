/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 */

// @lc code=start
class Solution {
public:
    void mergesort(vector<int>& nums, int left, int right){
        if(left >= right){
            return;
        }
        int mid = (right - left) / 2 + left;
        mergesort(nums, left, mid);
        mergesort(nums, mid + 1, right);
        vector<int> temp;
        int l1_start = left;
        int l2_start = mid+1;
        int l1_end = mid;
        int l2_end = right;
        while(l1_start <= l1_end || l2_start <= l2_end){
            if(l1_start > l1_end){
                temp.push_back(nums[l2_start]);
                l2_start += 1;
            } else if(l2_start > l2_end){
                temp.push_back(nums[l1_start]);
                l1_start += 1;
            } else{
                if(nums[l1_start] < nums[l2_start]){
                    temp.push_back(nums[l1_start]);
                    l1_start += 1;
                } else{
                    temp.push_back(nums[l2_start]);
                    l2_start += 1;
                }
            }
        }
        for(int i=0;i<temp.size();i++){
            nums[left+i] = temp[i];
        }
    }
    void quicksort(vector<int>& nums, int left, int right){
        if(left >= right){
            return;
        }
        int x = nums[left];
        int start = left;
        int end = right;
        while(start < end){
            while(start < end && nums[end] > x){
                end--;
            }
            nums[start] = nums[end];
            while(start < end && nums[start] <= x){
                start++;
            }
            nums[end] = nums[start];
        }
        nums[start] = x;
        quicksort(nums, left, start-1);
        quicksort(nums, start+1, right);
    }
    vector<int> sortArray(vector<int>& nums) {
        mergesort(nums, 0, nums.size()-1);
        return nums;
    }
};
// @lc code=end

