// Google (6) — Bloomberg (3) — Meta (2) — Amazon (2) — LinkedIn (2) — Yandex
// (2) — Microsoft (4) — Apple (16) — Adobe (6) — Yahoo (5) — TikTok (3) — Uber
// (2)

// Problem_Link: https://leetcode.com/problems/symmetric-tree/description/

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

bool isSymmetric(TreeNode* root){
    if(root == NULL){
        return true;
    }
    queue<TreeNode*>q;
    q.push(root->left);
    q.push(root->right);
    while(!q.empty()){
        TreeNode* left = q.front();
        q.pop();
        TreeNode* right = q.front();
        q.pop();
        if(left == NULL && right == NULL){
            continue;
        }
        if(left == NULL || right == NULL){
            return false;
        }
        if(left->val != right->val){
            return false;
        }
        q.push(left->left);
        q.push(right->right);

        q.push(left->right);
        q.push(right->left);
    }
    return true;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<int> arr = {1, 2, 2, 3, 4, 4, 3};
  TreeNode* root = BuildTree(arr);
  bool ans = isSymmetric(root);
  cout << ans << "\n";
}