/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        bool next;
        int sign = (m + n) / 2; 
        if((m + n) % 2 == 1){
            next = false;
        } else{
            sign -= 1;
            next = true;
        }
        int res1 = 0;
        int res2 = 0;
        int globalindex = 0;
        int nums1index = 0;
        int nums2index = 0;
        while(globalindex <= sign){
            if(nums1index < m && nums2index < n){
                if(nums1[nums1index] < nums2[nums2index]){
                    res1 = nums1[nums1index];
                    nums1index += 1;
                } else{
                    res1 = nums2[nums2index];
                    nums2index += 1;
                }
            } else if (nums1index < m){
                res1 = nums1[nums1index];
                nums1index += 1;
            } else {
                res1 = nums2[nums2index];
                nums2index += 1;
            }
            globalindex += 1;
        }
        if(next == false){
            return res1;
        }
        if(nums1index < m && nums2index < n){
            if(nums1[nums1index] < nums2[nums2index]){
                res2 = nums1[nums1index];
            } else{
                res2 = nums2[nums2index];
            }
        } else if (nums1index < m){
            res2 = nums1[nums1index];
        } else {
            res2 = nums2[nums2index];
        }
        return ((double)res1 + (double)res2) / 2.0;
    }
};
// @lc code=end

