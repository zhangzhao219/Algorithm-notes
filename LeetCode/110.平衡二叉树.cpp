/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
    int getHeight(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        int left = getHeight(root->left);
        if(left == -1){
            return -1;
        }
        int right = getHeight(root->right);
        if(right == -1){
            return -1;
        }
        if(abs(right - left) <= 1){
            return 1 + max(left, right);
        }
        return -1;
    }
    bool isBalanced(TreeNode* root) {
        int a = getHeight(root);
        if(a == -1){
            return false;
        }
        return true;
    }
};
// @lc code=end

