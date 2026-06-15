// 0 - 3 months:
// Meta (6) — Amazon (6) — Uber (5) — Google (4) — Bloomberg (2)

// 0 - 6 months:
// Oracle (2)

// 6 months ago:
// Apple (6) — Microsoft (4) — Yahoo (3) — Adobe (2) — Agoda (2)

// Problem_Link: https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/

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

 int cnt = 0;
int ans = -1;

void inorder(TreeNode* root, int k) {
    if (!root) return;

    inorder(root->left, k);

    cnt++;
    if (cnt == k) {
        ans = root->val;
        return;
    }

    inorder(root->right, k);
}

int kthSmallest(TreeNode* root, int k) {
    cnt = 0;
    ans = -1;
    inorder(root, k);
    return ans;
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>arr = {5,3,6,2,4,-1,-1,1};

    TreeNode* root = BuildTree(arr);

    cout << kthSmallest(root, 3) << "\n";
 
}



//           5 (6)
//         /       \
//      3 (4)      6 (1)
//      /   \
//   2 (2)   4 (1)
//    /
//  1 (1)



// #include <bits/stdc++.h>
// using namespace std;

// class Node {
// public:
//     int val;
//     Node* left;
//     Node* right;
//     int size; // subtree size

//     Node(int x) {
//         val = x;
//         left = right = NULL;
//         size = 1;
//     }
// };

// // get size safely
// int getSize(Node* root) {
//     return root ? root->size : 0;
// }

// // update size after changes
// void update(Node* root) {
//     if (root) {
//         root->size = 1 + getSize(root->left) + getSize(root->right);
//     }
// }

// // INSERT in BST + update size
// Node* insert(Node* root, int val) {
//     if (!root) return new Node(val);

//     if (val < root->val)
//         root->left = insert(root->left, val);
//     else
//         root->right = insert(root->right, val);

//     update(root);
//     return root;
// }

// // Kth smallest using subtree size
// int kthSmallest(Node* root, int k) {
//     if (!root) return -1;

//     int leftSize = getSize(root->left);

//     // go left
//     if (k <= leftSize) {
//         return kthSmallest(root->left, k);
//     }

//     // root is answer
//     if (k == leftSize + 1) {
//         return root->val;
//     }

//     // go right
//     return kthSmallest(root->right, k - leftSize - 1);
// }

// // inorder print (debug)
// void inorder(Node* root) {
//     if (!root) return;
//     inorder(root->left);
//     cout << root->val << " ";
//     inorder(root->right);
// }

// int main() {
//     Node* root = NULL;

//     vector<int> arr = {5, 3, 6, 2, 4, 1};

//     for (int x : arr) {
//         root = insert(root, x);
//     }

//     cout << "Inorder (sorted): ";
//     inorder(root);
//     cout << "\n";

//     int k = 4;
//     cout << k << "th smallest = " << kthSmallest(root, k) << "\n";

//     return 0;
// }