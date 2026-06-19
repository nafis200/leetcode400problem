

// 0 - 3 months:
// Meta (2) — Microsoft (2)

// 0 - 6 months:
// Google (2)

// 6 months ago:
// Amazon (15) — Bloomberg (6) — Adobe (2) — LinkedIn (2) — Uber (2)

// https://leetcode.com/problems/binary-search-tree-iterator/description/

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

// Time o(n) space o(n)

// vector<int> inorderTraversal;
// int ptr;

// void inorder(TreeNode* root) {
//   if (root == NULL) {
//     return;
//   }

//   inorder(root->left);
//   inorderTraversal.push_back(root->val);
//   inorder(root->right);
// }

// TreeNode* BSTIterator(TreeNode* root) {
//   inorder(root);
//   ptr = 0;
// }

// int next() {
//     return inorderTraversal[ptr++];
// }


// bool hasNext() {
//     return ptr < inorderTraversal.size();
// }


// Time o(n) space o(h)

stack<TreeNode*>st;

void PushLeft(TreeNode* root){
    if(root == NULL){
        return;
    }
    st.push(root);
    PushLeft(root->left);
}

TreeNode* BSTIterator(TreeNode* root) {
   PushLeft(root); 
}

int next() {
    TreeNode* x = st.top();
    st.pop();
    if(x->right){
        PushLeft(x->right);
    }
    return x->val;
}


bool hasNext() {
    return !st.empty();
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<int> arr = {7, 3, 15, -1, -1, 9, 20};
  TreeNode* root = BuildTree(arr);
}