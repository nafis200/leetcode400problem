// 0 - 3 months:
// Amazon (7) — Meta (5) — Bloomberg (4) — Google (3) — Microsoft (3) — Nutanix
// (2)

// 0 - 6 months:
// Oracle (3) — TikTok (3) — LinkedIn (2) — Walmart Labs (2) — Sigmoid (2) —
// Yandex (2)

// 6 months ago:
// Adobe (9) — Flipkart (4) — eBay (3) — Uber (2) — ServiceNow (2) — Docusign
// (2)

// Problem_Link:
// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/

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

vector<vector<int>> levelOrder(TreeNode* root) {
  vector<vector<int>> ans;
  if (root == NULL) {
    return ans;
  }

  queue<TreeNode*> q;
  q.push(root);

  while (!q.empty()) {
    int sz = q.size();
    vector<int> result;
    while (sz--) {
      TreeNode* x = q.front();
      q.pop();
      result.push_back(x->val);
      if (x->left) {
        q.push(x->left);
      }
      if (x->right) {
        q.push(x->right);
      }
    }
    ans.push_back(result);
  }
  return ans;
}

// Time o(n) space o(n)
//  2 8 16 64

// vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
//   vector<vector<int>> ans;
//   if (root == NULL) {
//     return ans;
//   }

//   queue<TreeNode*> q;
//   q.push(root);
//   int level = 0;
//   while (!q.empty()) {
//     int sz = q.size();
//     vector<int> result;
//     while (sz--) {
//       TreeNode* x = q.front();
//       q.pop();
//       result.push_back(x->val);
//       if (x->left) {
//         q.push(x->left);
//       }
//       if (x->right) {
//         q.push(x->right);
//       }
//     }
//     if(level % 2){
//          NotReverse(result.begin(),result.end());
//     }
//     level++;
//     ans.push_back(result);
//   }
//   return ans;
// }

// More optimise

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
  vector<vector<int>> ans;
  if (root == NULL) {
    return ans;
  }

  queue<TreeNode*> q;
  q.push(root);
  bool NotReverse = true;
  
  while (!q.empty()) {
    int sz = q.size();
    vector<int> result(sz);

    for (int i = 0; i < sz; i++) {
      TreeNode* x = q.front();
      q.pop();
      int idx = NotReverse ? i : sz - i - 1;
      result[idx] = x->val;
      if (x->left) {
        q.push(x->left);
      }
      if (x->right) {
        q.push(x->right);
      }
    }

     NotReverse = !NotReverse;

    ans.push_back(result);
  }
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<int> arr = {3, 9, 20, -1, -1, 15, 7};
  TreeNode* root = BuildTree(arr);

  vector<vector<int>> ans = zigzagLevelOrder(root);

  for (auto v : ans) {
    for (auto i : v) {
      cout << i << " ";
    }
    cout << "\n";
  }
}