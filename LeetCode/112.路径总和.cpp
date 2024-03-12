/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
    bool judge = false;
public:
    void DFS(TreeNode* root, int nowSum, int targetSum){
        nowSum += root->val;
        if(root->left == NULL && root->right == NULL){
            if(nowSum == targetSum){
                judge = true;
            }
            return;
        }
        if(root->left != NULL){
            DFS(root->left, nowSum, targetSum);
        }
        if(root->right != NULL){
            DFS(root->right, nowSum, targetSum);
        }
        nowSum -= root->val;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL){
            return false;
        }
        DFS(root,0, targetSum);
        return judge;
    }
};
// @lc code=end

