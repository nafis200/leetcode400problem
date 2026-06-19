// 0 - 3 months:
// Google (3) — Meta (2)

// 0 - 6 months:
// Microsoft (2) — Amazon (2)

// 6 months ago:
// Bloomberg (2) — eBay (2) — Compass (2)

// Problem_Link: https://leetcode.com/problems/subtree-of-another-tree/description/

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

bool isTree(TreeNode* root, TreeNode* subroot){
    if(root == NULL && subroot == NULL){
        return true;
    }
    if(root == NULL || subroot == NULL){
        return false;
    }
    if(root->val != subroot->val){
        return false;
    }
    return isTree(root->left, subroot->left) && isTree(root->right, subroot->right);
}

 bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if(root == NULL){
        return false;
    }
    if(isTree(root, subRoot)){
        return true;
    }     

    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
 }

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
}