// 0 - 3 months:
// Bloomberg (11) — Microsoft (5) — Amazon (5) — Google (4) — Meta (2)

// 0 - 6 months:
// IBM (3) — Wix (2)

// 6 months ago:
// Yandex (22) — Apple (12) — TikTok (8) — Adobe (6) — Oracle (6) — SIG (6) — Citadel (5) — Nvidia (5) — Uber (4) — ServiceNow (4)

// Problem_Link: https://leetcode.com/problems/validate-binary-search-tree/description/


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

// Wrong way
    //   10
    //  /  \
    // 5    15
    //     /  \
    //    6   20

//  6 < 15 but it is must > 10 not 6 is not

// (-∞ , +∞)
// left value -infinity to root value
// right value root value to infinity
// mn < node->val < mx

// 10  to infinity 

// 10 < 6 < 15


// Valid
    //     10
    //    /  \
    //   5    15
    //  / \   / \
    // 2   7 12 20

// Time o(n) space depthlogn or o(n)

bool validBST(TreeNode* root, long long mn, long long mx){
  if(root == NULL){
    return true;
  }
  if(root->val <= mn || root->val >= mx){
    return false;
  }
  return validBST(root->left, mn, root->val) && validBST(root->right, root->val, mx);
  
}

bool isValidBST(TreeNode* root) {
    return validBST(root, LONG_LONG_MIN, LONG_LONG_MAX);
}


int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>arr = {2,1,3};

    TreeNode* root = BuildTree(arr);

    bool ans = isValidBST(root);
    cout << ans << "\n";


  
}