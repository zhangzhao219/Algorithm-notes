/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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
    vector<vector<int> > result;
public:
    void DFS(TreeNode* root, int nowSum, int targetSum, vector<int> path){
        nowSum += root->val;
        path.push_back(root->val);
        if(root->left == NULL && root->right == NULL && nowSum == targetSum){
            result.push_back(path);
            return;
        }
        if(root->left != NULL){
            DFS(root->left,nowSum,targetSum, path);
        }
        if(root->right != NULL){
            DFS(root->right,nowSum,targetSum, path);
        }
        nowSum -= root->val;
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root == NULL){
            return result;
        }
        vector<int> path;
        DFS(root,0,targetSum, path);
        return result;
    }
};
// @lc code=end

