// 0 - 6 months:
// Google (3) — Meta (2)

// 6 months ago:
// Amazon (3) — Adobe (3) — Goldman Sachs (2)

// Problem_Link: https://leetcode.com/problems/minimum-absolute-difference-in-bst/

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

// int getMinimumDifference(TreeNode* root) {
//      vector<int>result = inorderTraversal(root);
     
//      int mn = INT_MAX;
//      for(int i = 1; i < result.size(); i++){
//         mn = min(mn, result[i] - result[i - 1]);
//      }
//      return mn;
// }


int ans = INT_MAX;
TreeNode* prev = NULL;

void InorderTraversal(TreeNode* root){
    if(root == NULL){
        return;
    }

    InorderTraversal(root->left);

    if(prev != NULL){
        ans = min(ans, root->val - prev->val);
    }

    prev = root;

    InorderTraversal(root->right);
}

int getMinimumDifference(TreeNode* root) {
     InorderTraversal(root);
     return ans;    
}




int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
   
}