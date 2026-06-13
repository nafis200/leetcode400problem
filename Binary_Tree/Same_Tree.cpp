// 0 - 3 months:
// Google (11) — Amazon (4)

// 0 - 6 months:
// Bloomberg (3) — Meta (2) — Microsoft (2) — Apple (2)

// 6 months ago:
// Adobe (5) — tcs (3) — LinkedIn (2) — Flipkart (2) — Yahoo (2)

// Problem_Link: https://leetcode.com/problems/same-tree/description/

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

bool isSameTree(TreeNode* p, TreeNode* q){

    if(p == NULL && q == NULL){
        return true;
    }
    if(p == NULL || q == NULL){
        return false;
    }
    if(p->val != q->val){
        return false;
    }

    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int> p = {1, 2, 3};
    vector<int> q = {1, 2, 3};
    TreeNode* root1 = BuildTree(p);
    TreeNode* root2 = BuildTree(q);

    cout << isSameTree(root1, root2) << "\n";
}