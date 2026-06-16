
// 0 - 3 months:
// Meta (70) — Amazon (11) — Google (7) — Microsoft (3) — Oracle (3) — LinkedIn (2) — Apple (2) — TikTok (2)

// 0 - 6 months:
// Bloomberg (3) — Wix (2)

// 6 months ago:
// Adobe (11) — Yandex (6) — Yahoo (3) — GE Healthcare (3) — Flipkart (2) — Morgan Stanley (2) — Walmart Labs (2) — Wayfair (2) — PayPal (2) — Salesforce (2)

// Problem_Link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/


    //       3
    //     /   \
    //    5     1
    //   / \   / \
    //  6   2 0   8
    //     / \
    //    7   4

    class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root,
                                   TreeNode* p,
                                   TreeNode* q) {
        
        if (root == NULL)
            return NULL;

        if (root == p || root == q)
            return root;

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

       
        if (left && right)
            return root;

        return left ? left : right;
    }
};