/*
 * @lc app=leetcode.cn id=1038 lang=cpp
 *
 * [1038] 从二叉搜索树到更大和树
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
private:
    int nowsum = 0;
public:
    TreeNode* bstToGst(TreeNode* root) {
        if(root == NULL){
            return NULL;
        }
        bstToGst(root->right);
        root->val += nowsum;
        nowsum = root->val;
        bstToGst(root->left);
        return root;
    }
};
// @lc code=end

