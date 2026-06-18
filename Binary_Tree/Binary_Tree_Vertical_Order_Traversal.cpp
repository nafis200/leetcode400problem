// 0 - 3 months:
// Meta (113) — Google (3) — Amazon (3) — Bloomberg (2)

// 0 - 6 months:
// DoorDash (2)

// 6 months ago:
// Microsoft (8) — Apple (4) — TikTok (4) — Oracle (2) — Snap (2)

// Problem_Link: https://algo.monster/liteproblems/314

//        3(0)
//       /    \
//    9(-1)  20(+1)
//           /   \
//       15(0)   7(+2)


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

//        3(0)
//       /    \
//    9(-1)  20(+1)
//           /   \
//       15(0)   7(+2)

vector<vector<int>> verticalOrder(TreeNode* root){
    vector<vector<int>>ans;
    queue<pair<TreeNode*, int>>q;
    if(root == NULL){
        return ans;
    }
   q.push({root, 0});
   map<int,vector<int>>mp;
   while(!q.empty()){
      pair<TreeNode*, int> x = q.front();
      q.pop();

      TreeNode* node = x.first;
      int col = x.second;
      mp[col].push_back(node->val);
      if(node->left){
        q.push({node->left, col - 1});
      }
      if(node->right){
        q.push({node->right, col + 1});
      }
   }

   for(auto it : mp){
      ans.push_back(it.second);
   }
   return ans;
}


int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>arr = {3, 9, 20, -1, -1, 15, 7, -1, -1, -1, -1};
    TreeNode* root = BuildTree(arr);
    
    vector<vector<int>>ans = verticalOrder(root);

    for(auto v : ans){
        for(auto i : v){
            cout << i << " ";
        }
        cout << "\n";
    }
}