/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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
    vector<string> result;
public:
    void DFS(TreeNode* root, vector<int> temp){
        temp.push_back(root->val);
        if(root->left == NULL && root->right == NULL){
            string s = "";
            for(int i=0;i<temp.size();i++){
                if(i != temp.size()-1){
                    s = s + to_string(temp[i]) + "->";
                }
                else{
                    s = s + to_string(temp[i]);
                }
            }
            result.push_back(s);
            return;
        }
        if(root->left != NULL){
            DFS(root->left, temp);
        }
        if(root->right != NULL){
            DFS(root->right, temp);
        }
        temp.pop_back();
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root == NULL){
            return result;
        }
        vector<int> temp;
        DFS(root, temp);
        return result;
    }
};
// @lc code=end

