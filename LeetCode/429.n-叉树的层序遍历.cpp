/*
 * @lc app=leetcode.cn id=429 lang=cpp
 *
 * [429] N 叉树的层序遍历
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int> > result;
        if(root == NULL){
            return result;
        }
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int s = q.size();
            vector<int> temp;
            for(int i=0;i<s;i++){
                Node* t = q.front();
                q.pop();
                temp.push_back(t->val);
                for(int i=0;i<t->children.size();i++){
                    if(t->children[i] != NULL){
                        q.push(t->children[i]);
                    }
                }
            }
            result.push_back(temp);
        }
        return result;
    }
};
// @lc code=end

