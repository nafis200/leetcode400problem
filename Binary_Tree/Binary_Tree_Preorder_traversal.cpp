// Bloomberg (3) — Meta (2) — Microsoft (2) — Amazon (8) — Yahoo (4) — Google (3) — Apple (3) — Adobe (2)

// Problem_Link: https://leetcode.com/problems/binary-tree-preorder-traversal/description/

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

vector<int>ans;

vector<int> preorderTraversal(TreeNode* root) {
   if(root == NULL){
         return {}; 
       }     
      ans.push_back(root->val);
      preorderTraversal(root->left);
      preorderTraversal(root->right);
      return ans;        
}




int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>arr = {1,2,3,4,5,-1,8,-1,-1,6,7,9};
    TreeNode* root = BuildTree(arr);
    
    vector<int>result = preorderTraversal(root);

    for(auto it : result){
        cout << it << " ";
    }
}