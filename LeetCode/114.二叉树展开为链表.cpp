/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
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
    void flatten(TreeNode* root) {
        if (root == NULL){
            return;
        }
        flatten(root->left);
        flatten(root->right);
        if (root->left != NULL) {
            auto pre = root->left;
            while (pre->right != NULL){
                pre = pre->right;
            }
            pre->right = root->right;
            root->right = root->left;
            root->left = NULL;
        }
        root = root->right;
        return;
    }
};
// @lc code=end

