// 0 - 6 months:
// Google (2) — Meta (2)

// 6 months ago:
// Microsoft (6) — Amazon (5) — Goldman Sachs (2) — DocuSign (2) — Josh Technology (2)

// Problem_Link: https://leetcode.com/problems/count-good-nodes-in-binary-tree/

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

int nums = 0;

void CountNodes(TreeNode* root, int mx){
    if(root == NULL){
        return;
    }

    if(root->val >= mx){
        mx = max(mx,root->val);
        nums++;
    }

    CountNodes(root->left, mx);
    CountNodes(root->right,mx);
}

int goodNodes(TreeNode* root) {
     if(root == NULL){
        return 0;
     }   
     
     CountNodes(root, INT_MIN);
     return nums;
}


int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int>arr = {3,1,4,3,-1,1,5};

    TreeNode* root = BuildTree(arr);

    int node = goodNodes(root);
    cout << node << "\n";
    
}