// Meta (63) — Google (3)

// https://leetcode.com/problems/range-sum-of-bst/description/

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

// Time o(n) space o(logn)

int rangeSumBST(TreeNode* root, int low, int high) {

    if(root == NULL){
        return 0;
    }

    if(root->val < low){
        return rangeSumBST(root->right, low, high);
    }

    if(root->val > high){
        return rangeSumBST(root->left, low, high);
    }

    return root->val +
           rangeSumBST(root->left, low, high) +
           rangeSumBST(root->right, low, high);
}


int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>arr = {10,5,15,3,7,-1,18};

    TreeNode* root = BuildTree(arr);

    int sum = rangeSumBST(root, 7, 15);

    cout << sum << "\n";
}