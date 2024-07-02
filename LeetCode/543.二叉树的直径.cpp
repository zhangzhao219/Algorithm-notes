/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
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
    int maxlength = 0;
    int DFS(TreeNode* root, int nowlength){
        if(root == NULL){
            return 0;
        }
        int leftlength = DFS(root->left, nowlength+1);
        int rightlength = DFS(root->right, nowlength+1);
        maxlength = max(maxlength, leftlength + rightlength + 1);
        return max(leftlength, rightlength) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        DFS(root,0);
        return maxlength-1;
    }
};
// @lc code=end

