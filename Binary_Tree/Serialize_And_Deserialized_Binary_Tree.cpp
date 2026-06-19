// 0 - 3 months:
// Amazon (3) — Google (2) — Microsoft (2) — TikTok (2)

// 0 - 6 months:
// LinkedIn (4) — Apple (4)

// 6 months ago:
// Meta (22) — Bloomberg (11) — DoorDash (10) — Uber (5) — TCS (4) — Citadel (4)
// — Nvidia (4) — Workday (3) — Yahoo (3) — Adobe (2)

// Problem_Link:
// https://leetcode.com/problems/serialize-and-deserialize-binary-tree/

#include <bits/stdc++.h>
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

class Codec {
public:

    void preorder(TreeNode* root, string& s) {
        if (root == NULL) {
            s += "-100000,";
            return;
        }

        s += to_string(root->val) + ",";
        preorder(root->left, s);
        preorder(root->right, s);
    }

    string serialize(TreeNode* root) {
        string s = "";
        preorder(root, s);
        return s;
    }

    TreeNode* build(vector<int>& arr, int& idx) {
        if (idx >= arr.size()) {
            return NULL;
        }

        if (arr[idx] == -100000) {
            idx++;
            return NULL;
        }

        TreeNode* root = new TreeNode(arr[idx++]);

        root->left = build(arr, idx);
        root->right = build(arr, idx);

        return root;
    }

    TreeNode* deserialize(string data) {
        vector<int> arr;

        string cur = "";

        for (char ch : data) {
            if (ch == ',') {
                arr.push_back(stoi(cur));
                cur = "";
            }
            else {
                cur += ch;
            }
        }

        int idx = 0;
        return build(arr, idx);
    }
};