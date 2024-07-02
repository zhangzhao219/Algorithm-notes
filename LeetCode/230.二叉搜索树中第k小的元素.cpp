/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第K小的元素
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
    int num = 0;
    int result = 0;
    void inorder(TreeNode* root,int k){
        if(root == NULL){
            return;
        }
        inorder(root->left, k);
        num += 1;
        if(num == k){
            result = root->val;
        }
        inorder(root->right, k);
    }
   
    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k);
        return result;
    }
};
// @lc code=end

