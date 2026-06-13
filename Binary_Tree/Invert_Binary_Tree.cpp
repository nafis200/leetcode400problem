// Meta (45) — Google (4) — Amazon (2) — Bloomberg (2) — Visa (2)

// Problem_Link: https://leetcode.com/problems/invert-binary-tree/description/

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

// bool isMirror(TreeNode* left, TreeNode* right) {
//   if (left == NULL && right == NULL) {
//     return true;
//   }
//   if (left == NULL || right == NULL) {
//     return false;
//   }
//   if (left->val != right->val) {
//     return false;
//   }

//   return isMirror(left->left, right->right) &&
//          isMirror(left->right, right->left);
// }

// bool isSymmetric(TreeNode* root) {
//   if (root == NULL) {
//     return true;
//   }
//   return isMirror(root->left, root->right);
// }

// TreeNode* invertTree(TreeNode* root) {
//     if (root == NULL) {
//         return NULL;
//     }

//     swap(root->left, root->right);

//     invertTree(root->left);
//     invertTree(root->right);

//     return root;
// }

TreeNode* invertTree(TreeNode* root) {
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        TreeNode* x = q.front();
        q.pop();
        if(x != NULL){
           swap(x->left, x->right);
           q.push(x->left);
           q.push(x->right);
        }
    }
    return root;
}


void preorder(TreeNode* root) {
    if (root == NULL) return;

    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<int> arr = {4,2,7,1,3,6,9};
  TreeNode* root = BuildTree(arr);
 
  
}