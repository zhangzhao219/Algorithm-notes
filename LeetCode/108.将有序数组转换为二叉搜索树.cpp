/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0){
            return NULL;
        }
        int mid = nums.size() / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        vector<int> leftnums;
        vector<int> rightnums;
        for(int i=0;i<mid;i++){
            leftnums.push_back(nums[i]);
        }
        for(int i=mid+1;i<nums.size();i++){
            rightnums.push_back(nums[i]);
        }
        root->left = sortedArrayToBST(leftnums);
        root->right = sortedArrayToBST(rightnums);
        return root;
    }
};
// @lc code=end

