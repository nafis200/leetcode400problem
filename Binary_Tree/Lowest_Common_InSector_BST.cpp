// LinkedIn (5) — Amazon (4) — Google (3) — Meta (3) — Bloomberg (3)

// Problem_Link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/

//         6
//       /   \
//      2     8
//     / \
//    0   4
//       / \
//      3   5


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

TreeNode* Build(int l, int r,vector<int>& nums){
    if(l > r){
        return NULL;
    }
    int mid = l + (r - l) / 2;
    TreeNode* root = new TreeNode(nums[mid]);
    
    root->left = Build(l, mid - 1, nums);
    root->right = Build(mid + 1, r, nums);
    return root;
}

TreeNode* findNode(TreeNode* root, int target) {

    if(root == NULL) {
        return NULL;
    }

    if(root->val == target) {
        return root;
    }

    if(target < root->val) {
        return findNode(root->left, target);
    }

    return findNode(root->right, target);
}

// Time o(logn) space o(logn)

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    while(root != NULL){
        if(p->val < root->val && q->val < root->val){
            root = root->left;
        }
        else if(p->val > root->val && q->val > root->val){
            root = root->right;
        }
        else{
            return root;
        }
    }

    return NULL;
}


int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>arr = {6,2,8,0,4,7,9,-1,-1,3,5};

    TreeNode* root = Build(0, arr.size() - 1, arr);
    
    TreeNode* p = findNode(root, 2);
    TreeNode* q = findNode(root, 6);

    TreeNode* ans = lowestCommonAncestor(root, p, q);

    cout << ans->val << "\n";
}