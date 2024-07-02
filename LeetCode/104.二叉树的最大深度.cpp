/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
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
    int max_depth = 0;
    void DFS(TreeNode* root, int depth){
        if(root == NULL){
            max_depth = max(max_depth, depth);
            return;
        }
        DFS(root->left, depth+1);
        DFS(root->right, depth+1);
    }
    int maxDepth(TreeNode* root) {
        DFS(root,0);
        return max_depth;
    }
};
// @lc code=end

