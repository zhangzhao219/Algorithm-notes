/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 */

// @lc code=start
class Solution {
public:
    // void quicksort(vector<int>& nums, int start, int end){
    //     if(start >= end){
    //         return;
    //     }
    //     int randomIndex = rand() % (end - start + 1) + start;
    //     swap(nums[randomIndex], nums[start]);
    //     int x = nums[start];
    //     int left = start;
    //     int right = end;
    //     while(left < right){
    //         while(left < right && nums[right] >= x){
    //             right--;
    //         }
    //         nums[left] = nums[right];
    //         while(left < right && nums[left] < x){
    //             left++;
    //         }
    //         nums[right] = nums[left];
    //     }
    //     nums[left] = x;
    //     quicksort(nums, start, left-1);
    //     quicksort(nums, left+1, end);
    // }
    void mergesort(vector<int>& nums, int start, int end){
        if(start >= end){
            return;
        }
        int mid = (end - start) / 2 + start;
        mergesort(nums, start, mid);
        mergesort(nums, mid+1, end);
        vector<int> temp;
        int left = start;
        int right = mid+1;
        while(left <= mid || right <= end){
            if(right > end){
                temp.push_back(nums[left]);
                left += 1;
            } else if(left > mid){
                temp.push_back(nums[right]);
                right += 1;
            } else{
                if(nums[left] < nums[right]){
                    temp.push_back(nums[left]);
                    left += 1;
                } else{
                    temp.push_back(nums[right]);
                    right += 1;
                }
            }
        }
        for(int i=start;i<=end;i++){
            nums[i] = temp[i-start];
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        // quicksort(nums, 0, nums.size()-1);
        mergesort(nums, 0, nums.size()-1);
        return nums;
    }
};
// @lc code=end

