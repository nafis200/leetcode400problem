// Amazon (2) — Google (6) — Bloomberg (6)

// Problem_Link: https://leetcode.com/problems/balanced-binary-tree/description/

#include <bits/stdc++.h>
using namespace std;

class TreeNode {
 public:
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) {
    val = x;
    left = NULL;
    right = NULL;
  }
};

TreeNode* BuildTree(vector<int>& arr) {
  if (arr.size() == 0) {
    return NULL;
  }
  TreeNode* root = new TreeNode(arr[0]);

  queue<TreeNode*> q;
  q.push(root);
  int i = 1;
  while (!q.empty()) {
    TreeNode* x = q.front();
    q.pop();
    if (i < (int)arr.size() && arr[i] != -1) {
      TreeNode* left = new TreeNode(arr[i]);
      x->left = left;
      q.push(left);
    }
    i++;
    if (i < (int)arr.size() && arr[i] != -1) {
      TreeNode* right = new TreeNode(arr[i]);
      x->right = right;
      q.push(right);
    }
    i++;
  }
  return root;
}

// Time o(n^2) space o(n)

//  use map time o(n) space o(n)

unordered_map<TreeNode*,int>mp;

int depth(TreeNode* root){
  if(root == NULL){
    return 0;
  }
  
  if(mp.find(root) != mp.end()){
     return mp[root];
  }

  return mp[root] = max(depth(root->left), depth(root->right)) + 1;
}

bool isBalanced(TreeNode* root){
   
     if(root == NULL){
        return true;
     }
     int leftHeight = depth(root->left);
     int rightHeight = depth(root->right);
     if(abs(leftHeight - rightHeight) > 1){
       return false;
     }
     return isBalanced(root->left) && isBalanced(root->right);
}

// class Solution {
// public:

//     int height(TreeNode* root)
//     {
//         if(root == NULL)
//         {
//             return 0;
//         }

//         int leftHeight = height(root->left);

//         if(leftHeight == -1)
//         {
//             return -1;
//         }

//         int rightHeight = height(root->right);

//         if(rightHeight == -1)
//         {
//             return -1;
//         }

//         if(abs(leftHeight - rightHeight) > 1)
//         {
//             return -1;
//         }

//         return max(leftHeight, rightHeight) + 1;
//     }

//     bool isBalanced(TreeNode* root) {
        
//         return height(root) != -1;
//     }
// };

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<int>arr = {3,9,20,-1,-1,15,7};
  TreeNode* root = BuildTree(arr);
  // cout << isBalanced(root) << "\n";
}