    //       18
    //      /  \
    //     7    21
    //      \   / \
    //      12 20 26
    //     /  \
    //    9   15

    #include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;

    Node(int val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

// Level Order Input
Node* input_tree()
{
    int val;
    cin >> val;

    if (val == -1)
        return NULL;

    Node* root = new Node(val);

    queue<Node*> q;
    q.push(root);

    while (!q.empty())
    {
        Node* parent = q.front();
        q.pop();

        int l, r;
        cin >> l >> r;

        Node* myLeft = NULL;
        Node* myRight = NULL;

        if (l != -1)
            myLeft = new Node(l);

        if (r != -1)
            myRight = new Node(r);

        parent->left = myLeft;
        parent->right = myRight;

        if (parent->left)
            q.push(parent->left);

        if (parent->right)
            q.push(parent->right);
    }

    return root;
}

    //       18
    //      /  \
    //     7    21
    //      \   / \
    //      12 20 26
    //     /  \
    //    9   15

void insert(Node* &root, int val)
{
    if(root == NULL)
    {
        root = new Node(val);
        return;
    }

    if(val < root->val)
    {
        insert(root->left, val);
    }
    else if(val > root->val)
    {
        insert(root->right, val);
    }
}

Node* findMin(Node* root)
{
    while(root->left)
    {
        root = root->left;
    }
    return root;
}


    //       18
    //      /  \
    //     7    21
    //      \   / \
    //      12 20 26
    //     /  \
    //    9   15



Node* deleteNode(Node* root, int val)
{
    if(root == NULL)
        return NULL;

    if(val < root->val)
    {
        root->left = deleteNode(root->left, val);
    }
    else if(val > root->val)
    {
        root->right = deleteNode(root->right, val);
    }
    else
    {
        // 0 child
        if(root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        // 1 child (right)
        if(root->left == NULL)
        {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        // 1 child (left)
        if(root->right == NULL)
        {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // 2 children
        Node* mn = findMin(root->right);

        root->val = mn->val;

        root->right =
            deleteNode(root->right, mn->val);
    }

    return root;
}

// BST Search
bool searchBST(Node* root, int val)
{
    if (root == NULL)
        return false;

    if (root->val == val)
        return true;

    if (val < root->val)
        return searchBST(root->left, val);

    return searchBST(root->right, val);
}

int main()
{
    Node* root = input_tree();

    int val;
    cin >> val;

    if (searchBST(root, val))
        cout << "FOUND\n";
    else
        cout << "NOT FOUND\n";

    return 0;
}