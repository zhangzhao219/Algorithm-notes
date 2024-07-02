/*
 * @lc app=leetcode.cn id=437 lang=cpp
 *
 * [437] 路径总和 III
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
    int DFS(TreeNode* root, long long targetSum){
        if(root == NULL){
            return 0;
        }
        int res = 0;
        if(root->val == targetSum){
            res += 1;
        }
        res += DFS(root->left, targetSum - root->val);
        res += DFS(root->right, targetSum - root->val);
        return res;
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root == NULL){
            return 0;
        }
        int nownum = DFS(root, (long long)targetSum);
        nownum += pathSum(root->left, targetSum);
        nownum += pathSum(root->right, targetSum);
        return nownum;
    }
};
// @lc code=end

