// Google (4) — Meta (3) — Apple (2)

// Problem_Links: https://leetcode.com/problems/binary-tree-paths/description/

#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public: 
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x){
        val = x;
        left = NULL;
        right = NULL;
    }
};

TreeNode* BuildTree(vector<int>&arr){
     if(arr.empty()){
        return NULL;
     }

     TreeNode* root = new TreeNode(arr[0]);
   
     queue<TreeNode*>q;
     q.push(root);
     int i = 1;
     while(!q.empty()){
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


// Time o(n) space o(1)

vector<string>ans;

void TakePath(TreeNode* root, string s){
   if(root == NULL){   
      return;
   }
   if(root->left == NULL && root->right == NULL){
        s += to_string(root->val);
        ans.push_back(s);
        return;
   }
    
    s += to_string(root->val);
    s += "->";
    
    TakePath(root->left, s);
    TakePath(root->right, s);
   
}

 vector<string> binaryTreePaths(TreeNode* root) {
      TakePath(root, "");
      return ans;
 }


int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>arr = {1,2,3,-1,5};

    TreeNode* root = BuildTree(arr);
    
    vector<string>result = binaryTreePaths(root);

    for(auto s : result){
        cout << s << " ";
    }
    
}