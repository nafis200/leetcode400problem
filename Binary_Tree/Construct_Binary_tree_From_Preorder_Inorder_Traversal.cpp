// 0 - 3 months:
// Google (4) — Amazon (2) — Snowflake (2)

// 0 - 6 months:
// Microsoft (6) — Meta (4) — Bloomberg (4)

// 6 months ago:
// Adobe (11) — TikTok (9) — Apple (4) — Salesforce (4) — Yahoo (3) — Tesla (2) — VMware (2)

// Problem_Link: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

// Preorder:  Root → Left → Right
// Inorder: Left → Root → Right

// preorder = [3,9,20,15,7]
// inorder  = [9,3,15,20,7]

//       3
//   9       20  15  7
//  9        20
//         15    7

//  0   4

// 0 0   2 4
  
// 2 2   4 4  

// 2 1  3 2    3 4  4 5

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

// Time o(n) space o(n)

int index = 0;
unordered_map<int,int>pos;
TreeNode* Build(vector<int>& preorder, vector<int>& inorder, int start, int end){
    if(start > end){
        return NULL;
    }

    int mid = pos[preorder[index]];
    index++;

    TreeNode* root = new TreeNode(inorder[mid]);
    root->left = Build(preorder, inorder, start, mid - 1);
    root->right = Build(preorder, inorder, mid + 1, end);
    return root;

}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    for(int i = 0; i < (int)inorder.size(); i++){
        pos[inorder[i]] = i;
    }
    TreeNode* root = Build(preorder, inorder, 0, inorder.size() - 1);

    return root;
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>preorder = {3,9,20,15,7};
    vector<int>inorder = {9,3,15,20,7};

}