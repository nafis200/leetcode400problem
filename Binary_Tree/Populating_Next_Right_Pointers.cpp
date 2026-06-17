// 0 - 3 months:
// Meta (12) — Amazon (6) — Bloomberg (4) — Google (2)

// 0 - 6 months:
// Microsoft (3)

// 6 months ago:
// Snowflake (5) — Oracle (4) — Adobe (3) — Flipkart (3) — Salesforce (3) — Apple (2) — Walmart Labs (2) — ServiceNow (2)

// Problem_Links: https://leetcode.com/problems/populating-next-right-pointers-in-each-node/description/

//         1
//       /   \
//      2     3
//     / \   / \
//    4   5 6   7

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node(int x) {
        val = x;
        left = NULL;
        right = NULL;
        next = NULL;
    }
};


Node* BuildTree(vector<int>& arr) {
    if (arr.empty()) return NULL;

    Node* root = new Node(arr[0]);

    queue<Node*> q;
    q.push(root);

    int i = 1;

    while (!q.empty() && i < arr.size()) {
        Node* cur = q.front();
        q.pop();

        if (i < arr.size()) {
            cur->left = new Node(arr[i++]);
            q.push(cur->left);
        }

        if (i < arr.size()) {
            cur->right = new Node(arr[i++]);
            q.push(cur->right);
        }
    }

    return root;
}


//         1
//       /   \
//      2     3
//     / \   / \
//    4   5 6   7

 Node* connect(Node* root) {
    
      if(root == NULL){
         return NULL;
      }

      if(root->left){
        root->left->next = root->right;
      }
      if(root->right && root->next){
        root->right->next = root->next->left;
      }
      connect(root->left);
      connect(root->right);

      return root;
 } 


int main() {

    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};

    Node* root = BuildTree(arr);
    
    root = connect(root);
   
}