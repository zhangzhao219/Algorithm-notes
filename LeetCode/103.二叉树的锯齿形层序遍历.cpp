/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > result;
        if(root == NULL){
            return result;
        }
        queue<TreeNode*> q;
        q.push(root);
        int sign = 0;
        while(!q.empty()){
            int t = q.size();
            vector<int> temp;
            for(int i=0;i<t;i++){
                TreeNode* x = q.front();
                q.pop();
                temp.push_back(x->val);
                if(x->left != NULL){
                    q.push(x->left);
                }
                if(x->right != NULL){
                    q.push(x->right);
                }
            }
            if(sign == 1){
                reverse(temp.begin(), temp.end());
            }
            result.push_back(temp);
            sign = 1 - sign;
        }
        return result;
    }
};
// @lc code=end

