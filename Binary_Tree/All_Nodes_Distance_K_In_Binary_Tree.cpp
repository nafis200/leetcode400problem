// 0 - 3 months:
// Meta (3) — Microsoft (3) — Amazon (3)

// 0 - 6 months:
// Salesforce (2)

// 6 months ago:
// Google (17) — Bloomberg (4) — Okta (4) — TikTok (3) — Oracle (2) — Flipkart
// (2) — Wix (2) — Nutanix (2)

// Problem_Link:
// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/description/

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
  if (arr.empty()) {
    return NULL;
  }

  TreeNode* root = new TreeNode(arr[0]);

  queue<TreeNode*> q;
  q.push(root);
  int i = 1;
  while (!q.empty()) {
    TreeNode* cur = q.front();
    q.pop();
    if (i < arr.size() && arr[i] != -1) {
      cur->left = new TreeNode(arr[i]);
      q.push(cur->left);
    }
    i++;
    if (i < arr.size() && arr[i] != -1) {
      cur->right = new TreeNode(arr[i]);
      q.push(cur->right);
    }
    i++;
  }
  return root;
}

vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
  unordered_map<TreeNode*, TreeNode*> mp;

  queue<TreeNode*> q;
  q.push(root);
  TreeNode* cur = root;

  while (!q.empty()) {
    TreeNode* x = q.front();
    q.pop();
    if (x->left) {
      q.push(x->left);
      mp[x->left] = x;
    }
    if (x->right) {
      q.push(x->right);
      mp[x->right] = x;
    }
  }

  int dis = 0;

  cur = target;
  q.push(target);
  unordered_set<TreeNode*> vis;
  vis.insert(target);

  while (!q.empty()) {
    if (dis == k) {
      break;
    }
    int sz = q.size();
    while (sz--) {
      TreeNode* x = q.front();
      q.pop();
      if (x->left && !vis.count(x->left)) {
        q.push(x->left);
        vis.insert(x->left);
      }
      if (x->right && !vis.count(x->right)) {
        q.push(x->right);
        vis.insert(x->right);
      }
      if (mp.count(x) && !vis.count(mp[x])) {
        q.push(mp[x]);
        vis.insert(mp[x]);
      }
    }
    dis++;
  }

  vector<int> ans;
  while (!q.empty()) {
    TreeNode* x = q.front();
    q.pop();
    ans.push_back(x->val);
  }
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  vector<int> arr = {3, 5, 1, 6, 2, 0, 8, -1, -1, 7, 4};

  TreeNode* root = BuildTree(arr);
}