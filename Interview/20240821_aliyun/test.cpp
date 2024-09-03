// #【1】根据给你的输入，生成二叉树结构，并计算此二叉树中第K个最小元素，给出算法的时间、空间复杂度。
// #
// # 示例 1:
// # 输入：root = [3,1,4,'null',2], k = 1
// # 输出：1
// # 
// # 示例 2:
// # 输入：root = [5,3,6,2,4,'null','null',1], k = 3
// # 输出：3

// # 提示：
// # 树中的节点数为 n 。
// # 1 <= k <= n <= 104
// # 0 <= Node.val <= 104
#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
  int val;
  TreeNode* left;
  TreeNode* right;
};

vector<int> nums;

void inorder(TreeNode* root){
  if(root == NULL){
    return;
  }
  nums.push_back(root->val);
  inorder(root->left);
  inorder(root->right);
}

void quicksort(vector<int> & nums, int start, int end, int k){
  if(start >= end){
    return;
  }
  int x = nums[start];
  int left = start;
  int right = end;
  while(left < right){
    while(left < right && nums[right] >= x){
      right--;
    }
    nums[left] = nums[right];
    while(left < right && nums[left] < x){
      left++;
    }
    nums[right] = nums[left];
  }
  nums[left] = x;
  if(left == k-1){
    return;
  }
  if(left < k-1){
    quicksort(nums, left+1,end , k);
  } else{
    quicksort(nums, start, left-1, k);
  }
}

TreeNode* createTree(vector<int> nums){
  TreeNode* root = new TreeNode();
  root->val = nums[0];
  queue<TreeNode*> q;
  q.push(root);
  int nowindex = 1;
  while(!q.empty() && nowindex < nums.size()){
    TreeNode* p = q.front();
    q.pop();
    if(nowindex < nums.size() && nums[nowindex] != -1){
      p->left = new TreeNode();
      p->left->val = nums[nowindex];
      q.push(p->left);
    }
    nowindex += 1;
    if(nowindex < nums.size() && nums[nowindex] != -1){
      p->right = new TreeNode();
      p->right->val = nums[nowindex];
      q.push(p->right);
    }
    nowindex += 1;
  }
  return root;
}

int main(){
  vector<int> root = {5,3,6,2,4,-1,-1,1};
  TreeNode* treeroot = createTree(root);
  inorder(treeroot);
  for(int i=0;i<nums.size();i++){
    cout << nums[i] << " ";
  }
  cout << endl;
  int k = 3;
  quicksort(nums, 0, nums.size()-1, k);
  cout << nums[k-1] << endl;
  return 0;
}
  
