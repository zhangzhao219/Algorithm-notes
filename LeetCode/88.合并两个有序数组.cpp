/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int index = m + n - 1;
        m -= 1;
        n -= 1;
        while(index >= 0){
            if(m < 0){
                nums1[index] = nums2[n];
                n--;
            } else if (n < 0){
                nums1[index] = nums1[m];
                m--;
            } else{
                if(nums1[m] > nums2[n]){
                    nums1[index] = nums1[m];
                    m--;
                } else{
                    nums1[index] = nums2[n];
                    n--;
                }
            }
            index--;
        }
        return;
    }
};
// @lc code=end

