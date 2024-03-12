/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.size() == 0){
            return NULL;
        }
        int maxindex = 0;
        int maxnode = nums[0];
        for(int i=0;i<nums.size();i++){
            if(nums[i] > maxnode){
                maxindex = i;
                maxnode = nums[i];
            }
        }
        TreeNode* root = new TreeNode(maxnode);
        vector<int> leftnums;
        vector<int> rightnums;
        for(int i=0;i<maxindex;i++){
            leftnums.push_back(nums[i]);
        }
        for(int i=maxindex+1;i<nums.size();i++){
            rightnums.push_back(nums[i]);
        }
        root->left = constructMaximumBinaryTree(leftnums);
        root->right = constructMaximumBinaryTree(rightnums);
        return root;
    }
};
// @lc code=end

