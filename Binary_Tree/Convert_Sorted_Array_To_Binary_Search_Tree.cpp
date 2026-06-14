// Amazon (3) — Microsoft (2) — Bloomberg (2) — Airbnb (2) — Apple (5) — Google (4) — Meta (4) — Adobe (4) — Samsung (2) — Yahoo (2)

// Problem_Link: https://leetcode.com/problems/convert-sorted-numsay-to-binary-search-tree/description/

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

TreeNode* sortedArrayToBST(vector<int>& nums) {
    int l = 0, r = nums.size() - 1;
    TreeNode* root = Build(l, r, nums);
    return root;
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>arr = {-10, -3, 0, 5, 9};

    TreeNode* root = sortedArrayToBST(arr);
    
}