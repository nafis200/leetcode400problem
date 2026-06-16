// 0 - 6 months:
// Microsoft (2) — Snowflake (2)

// 6 months ago:
// Amazon (4) — Adobe (3) — Google (2) — Meta (2) — Apple (2) — Yahoo (2)

// Problem_Link: https://leetcode.com/problems/leaf-similar-trees/description/

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

vector<int>leaf(TreeNode* root, vector<int>&nums){
     if(root == NULL){
        return nums;
     }
     if(root->left == NULL && root->right == NULL){
         nums.push_back(root->val);
         return nums;
     }

     leaf(root->left, nums);
     leaf(root->right, nums);
     return nums;
}

// Time o(n + m)
// space o(n + l + m + r)

 bool leafSimilar(TreeNode* root1, TreeNode* root2) {
    vector<int>nums1;
    vector<int>nums2;

    nums1 = leaf(root1, nums1);
    nums2 = leaf(root2, nums2);

    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    return (nums1 == nums2);
 }

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>arr = {3,5,1,6,2,9,8,-1,-1,7,4};

    TreeNode* root1 = BuildTree(arr);

    vector<int>arr1 = {3,5,1,6,7,4,2,-1,-1,-1,-1,-1,-1,9,8};

    TreeNode* root2 = BuildTree(arr1);
 
    bool ans = leafSimilar(root1, root2);
}