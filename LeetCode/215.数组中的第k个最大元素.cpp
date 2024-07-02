/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
class Solution {
public:
    void quicksort(vector<int>& nums, int i, int j, int k){
        if(i >= j){
            return;
        }
        int start = i;
        int end = j;
        int x = nums[start];
        while(start < end){
            while(start < end && nums[end] < x){
                end--;
            }
            nums[start] = nums[end];
            while(start < end && nums[start] >= x){
                start++;
            }
            nums[end] = nums[start];
        }
        nums[start] = x;
        if(k-1 == start){
            return;
        } else if(k-1 < start){
            quicksort(nums, i, start-1,k);
        } else{
            quicksort(nums,start+1,j,k);
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
        quicksort(nums,0,nums.size()-1,k);
        return nums[k-1];
    }
};
// @lc code=end
