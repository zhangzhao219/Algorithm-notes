/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0){
            return NULL;
        }
        int start = 0;
        int end = nums.size();
        int mid = (start + end) / 2;
        vector<int> numsleft;
        vector<int> numsright;
        for(int i=start;i<end;i++){
            if(i < mid){
                numsleft.push_back(nums[i]);
            } else if(i > mid){
                numsright.push_back(nums[i]);
            }
        }
        TreeNode* left = sortedArrayToBST(numsleft);
        TreeNode* root = new TreeNode(nums[mid]);
        TreeNode* right = sortedArrayToBST(numsright);
        root->left = left;
        root->right = right;
        return root;
        
    }
};
// @lc code=end

