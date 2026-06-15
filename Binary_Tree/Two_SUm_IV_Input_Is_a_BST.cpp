// Microsoft (4) — Meta (3) — Samsung (2)
// 6 months ago: Amazon (14) — Google (3) — Apple (3) — Adobe (2)

// Problem_Link: https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/

#include<bits/stdc++.h>
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

TreeNode* BuildTree(vector<int>& arr){
    if(arr.empty()){
        return NULL;
    }

    TreeNode* root = new TreeNode(arr[0]);

    queue<TreeNode*> q;
    q.push(root);

    int i = 1;

    while(!q.empty() && i < arr.size()){
        TreeNode* cur = q.front();
        q.pop();

        if(i < arr.size() && arr[i] != -1){
            cur->left = new TreeNode(arr[i]);
            q.push(cur->left);
        }
        i++;

        if(i < arr.size() && arr[i] != -1){
            cur->right = new TreeNode(arr[i]);
            q.push(cur->right);
        }
        i++;
    }

    return root;
}

void preorder(TreeNode* root) {
    if (root == NULL) return;

    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

// Time o(n) space o(n)

// vector<int>ans;
//  vector<int> inorderTraversal(TreeNode* root) {
//        if(root == NULL){
//          return {}; 
//        }     
//       inorderTraversal(root->left);
//       ans.push_back(root->val);
//       inorderTraversal(root->right);
//       return ans;
//  }

//  bool findTarget(TreeNode* root, int k) {
//     vector<int>result = inorderTraversal(root);
//     int l = 0, r = result.size() - 1;
//     while(l < r){
//         if(result[l] + result[r] == k){
//             return true;
//         }
//         else if(result[l] + result[r] > k){
//             r--;
//         }
//         else{
//             l++;
//         }
//     }
//     return false;
//  }


 set<int>st;
 bool findTarget(TreeNode* root, int k) {
      if(root == NULL){
        return false;
      }
      if(st.find(k - root->val) != st.end()){
         return true;
      }
      st.insert(root->val);
      return findTarget(root->left, k) || findTarget(root->right, k);
 }

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>arr = {5,3,6,2,4,-1,7};
    TreeNode* root = BuildTree(arr);
    
    cout << findTarget(root, 9) << "\n";
}