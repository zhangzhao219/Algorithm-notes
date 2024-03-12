/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
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
    unordered_map<int,int> mp;
public:
    void inorder(TreeNode* root){
        if(root == NULL){
            return;
        }
        inorder(root->left);
        mp[root->val] += 1;
        inorder(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        inorder(root);
        int result = 0;
        vector<int> res;
        for(auto it = mp.begin();it != mp.end();it++){
            if(it->second > result){
                res.clear();
                res.push_back(it->first);
                result = it->second;
            } else if (it->second == result){
                res.push_back(it->first);
            }
        }
        return res;
    }
};
// @lc code=end

