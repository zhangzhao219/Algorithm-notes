/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int rootval = preorder[0];
        TreeNode* root = new TreeNode(rootval);
        vector<int> newinorderleft;
        vector<int> newinorderright;
        vector<int> newpreorderleft;
        vector<int> newpreorderright;
        int inordersign = -1;
        for(int i=0;i<inorder.size();i++){
            if(inorder[i] == rootval){
                inordersign = i;
                newpreorderleft.push_back(preorder[i]);
                continue;
            }
            if(inordersign == -1){
                newinorderleft.push_back(inorder[i]);
                if(i != 0){
                    newpreorderleft.push_back(preorder[i]);
                }
            } else{
                newinorderright.push_back(inorder[i]);
                newpreorderright.push_back(preorder[i]);
            }
        }
        if(newinorderleft.size() != 0){
            root->left = buildTree(newpreorderleft,newinorderleft);
        }
        if(newinorderright.size() != 0){
            root->right = buildTree(newpreorderright,newinorderright);
        }
        return root;
    }
};
// @lc code=end

