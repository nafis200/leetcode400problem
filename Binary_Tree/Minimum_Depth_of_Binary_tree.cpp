// Bloomberg (2) — Meta (14) — Amazon (9) — Google (4) — Uber (4) — Microsoft (3) — Adobe (3) — Apple (3)

// Problem_Link: https://leetcode.com/problems/minimum-depth-of-binary-tree/submissions/2032144095/

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

// Time o(n) space o(logn)

// int depth(TreeNode* root){
//     if(root == NULL){
//         return 0;
//     }
//     if(root->left == NULL && root->right == NULL){
//         return 1;
//     }
//     if(root->left == NULL){
//         return depth(root->right) + 1;
//     }
//     if(root->right == NULL){
//         return depth(root->left) + 1;
//     }
//     return min(depth(root->right),depth(root->left)) + 1;
// }

// int minDepth(TreeNode* root) {
//     int ans = depth(root);
//     return ans;       
// }



int minDepth(TreeNode* root) {
     if(root == NULL){
        return 0;
     }
     queue<TreeNode*>q;
     q.push(root);
     int depth = 0;
     while(!q.empty()){
        int sz = q.size();
        while(sz--){
            TreeNode* cur = q.front();
            if(cur->left == NULL && cur->right == NULL){
                return depth + 1;
            }
            if(cur->left){
                q.push(cur->left);
            }
            if(cur->right){
                q.push(cur->right);
            }
            q.pop();
        }
        depth++;
     }
     return depth;
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>arr = {3,9,20,-1,-1,15,7};
    TreeNode* root = BuildTree(arr);
   
    int ans = minDepth(root);
    cout << ans << "\n";
}