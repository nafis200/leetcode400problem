// 0 - 3 months:
// Meta (80) — Google (6) — Amazon (4) — Yandex (3)

// 0 - 6 months:
// Oracle (6) — TikTok (6) — Bloomberg (3) — Uber (3) — ServiceNow (2)

// 6 months ago:
// Microsoft (13) — Adobe (3) — Walmart Labs (3) — J.P. Morgan (2) — Accolite (2) — Flipkart (2) — Wix (2)

// Problem_Link: https://leetcode.com/problems/binary-tree-right-side-view/description/


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

 vector<int> rightSideView(TreeNode* root) {
     if(root == NULL){
        return {};
     }
     queue<TreeNode*>q;
     vector<int>ans;
     q.push(root);
     while(!q.empty()){
        int sz = q.size();
        for(int i = 1; i <= sz; i++){
            TreeNode* x = q.front();
            q.pop();
            if(i == sz){
                ans.push_back(x->val);
            }
            if(x->left){
                q.push(x->left);
            }
            if(x->right){
                q.push(x->right);
            }
        }
     }
     return ans;
 }


int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>arr = {1,2,3,-1,5,-1,4};
    TreeNode* root = BuildTree(arr);
    vector<int>ans = rightSideView(root);
    
    for(auto i : ans){
        cout << i << " ";
    }
   
}