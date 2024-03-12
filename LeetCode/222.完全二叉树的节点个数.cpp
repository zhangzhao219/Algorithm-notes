/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
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
    int countNodes(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int leftCount = 0;
        int rightCount = 0;
        TreeNode* leftt = root->left;
        TreeNode* rightt = root->right;
        while(leftt != NULL){
            leftCount += 1;
            leftt = leftt->left;
        }
        while(rightt != NULL){
            rightCount += 1;
            rightt = rightt->right;
        }
        if(leftCount == rightCount){
            return (2 << leftCount) - 1;
        }
        return countNodes(root->left)  + countNodes(root->right) + 1;
    }
};
// @lc code=end

