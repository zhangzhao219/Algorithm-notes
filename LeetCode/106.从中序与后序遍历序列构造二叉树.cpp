/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postordersize = postorder.size();
        int rootval = postorder[postordersize-1];
        TreeNode* root = new TreeNode(rootval);
        vector<int> newinorderleft;
        vector<int> newinorderright;
        vector<int> newpostorderleft;
        vector<int> newpostorderright;
        int inordersign = -1;
        for(int i=0;i<inorder.size();i++){
            if(inorder[i] == rootval){
                inordersign = i;
                newpostorderright.push_back(postorder[i]);
                continue;
            }
            if(inordersign == -1){
                newinorderleft.push_back(inorder[i]);
                newpostorderleft.push_back(postorder[i]);
            } else{
                newinorderright.push_back(inorder[i]);
                if(i != inorder.size() -1){
                    newpostorderright.push_back(postorder[i]);
                }
            }
        }
        if(newinorderleft.size() != 0){
            root->left = buildTree(newinorderleft,newpostorderleft);
        }
        if(newinorderright.size() != 0){
            root->right = buildTree(newinorderright,newpostorderright);
        }
        return root;
    }
};
// @lc code=end

