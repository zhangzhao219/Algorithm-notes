/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层序遍历 II
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int> > result;
        queue<TreeNode*> q;
        if(root == NULL){
            return result;
        }
        q.push(root);
        while(!q.empty()){
            int t = q.size();
            vector<int> temp;
            for(int i=0;i<t;i++){
                TreeNode* node = q.front();
                q.pop();
                temp.push_back(node->val);
                if(node->left != NULL){
                    q.push(node->left);
                }
                if(node->right != NULL){
                    q.push(node->right);
                }
            }
            result.push_back(temp);
        }
        vector<vector<int> > result2;
        for(int i=result.size()-1;i>=0;i--){
            result2.push_back(result[i]);
        }
        return result2;
    }
};
// @lc code=end

