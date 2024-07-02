/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
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
    int maxSum  = INT_MIN;
public:
    
    int maxGain(TreeNode* node){
        if(node == NULL){
            return 0;
        }
        int leftGain  = max(maxGain(node->left), 0);
        int rightresult = max(maxGain(node->right), 0);
        int priceNewpath = node->val + leftGain  + rightresult;

        // 更新答案
        maxSum  = max(maxSum , priceNewpath);
        return node->val + max(leftGain, rightresult);
    }
    int maxPathSum(TreeNode* root) {
        maxGain(root);
        return maxSum ;
    }
};
// @lc code=end

