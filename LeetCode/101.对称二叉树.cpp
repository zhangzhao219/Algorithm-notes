/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
    bool isSame(TreeNode* left, TreeNode* right){
        if(left == NULL && right == NULL){
            return true;
        } else if(left == NULL){
            return false;
        } else if(right == NULL){
            return false;
        } else{
            if(left->val != right->val){
                return false;
            }
        }
        return isSame(left->left, right->right) && isSame(left->right, right->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL){
            return true;
        }
        return isSame(root->left, root->right);
    }
};
// @lc code=end

