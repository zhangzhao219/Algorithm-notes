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
        if(preorder.size() == 0){
            return NULL;
        }
        int val = preorder[0];
        TreeNode* root = new TreeNode(val);
        int k;
        vector<int> leftpreorder, leftinorder, rightpreorder, rightinorder;
        for(int i=0;i<inorder.size();i++){
            if(inorder[i] == val){
                k = i;
                break;
            }
        }
        for(int i=1;i<preorder.size();i++){
            if(i <= k){
                leftpreorder.push_back(preorder[i]);
            } else{
                rightpreorder.push_back(preorder[i]);
            }
        }
        for(int i=0;i<inorder.size();i++){
            if(i < k){
                leftinorder.push_back(inorder[i]);
            } else if (i > k){
                rightinorder.push_back(inorder[i]);
            }
        }
        root->left = buildTree(leftpreorder, leftinorder);
        root->right = buildTree(rightpreorder, rightinorder);
        return root;
    }
};
// @lc code=end

