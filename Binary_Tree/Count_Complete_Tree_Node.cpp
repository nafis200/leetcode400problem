// 0 - 3 months:
// Google (4)

// 0 - 6 months:
// Amazon (2) — Bloomberg (2)

// 6 months ago:
// Meta (6) — Microsoft (5) — Apple (3) — TikTok (2) — Yahoo (2)

// Problem_Link: https://leetcode.com/problems/count-complete-tree-nodes/description/

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

int inorder(TreeNode* root, int count){
    if(root == NULL){
        return 0;
    }
    int left = inorder(root->left, count);
    int right = inorder(root->right,count);

    count = left + right + 1;
    return count;
}

int countNodes(TreeNode* root) {
    return inorder(root, 0);    
}


int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>arr = {1,2,3,-1,5};

    TreeNode* root = BuildTree(arr);
       
}