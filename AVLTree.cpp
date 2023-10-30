#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int height;
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
        height = 1;
    }
};

class AVLTree
{
public:
    Node *root;
    AVLTree()
    {
        root = NULL;
    }
    int height(Node *node)
    {
        if (node == NULL)
        {
            return 0;
        }
        return node->height;
    }
    int getBalance(Node *node)
    {
        if (node == NULL)
        {
            return 0;
        }
        return height(node->left) - height(node->right);
    }
    Node *leftRotate(Node *x)
    {
        Node *y = x->right;
        Node *T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        return y;
    }
    Node *rightRotate(Node *y)
    {
        Node *x = y->left;
        Node *T2 = x->right;

        x->right = y;
        y->left = T2;

        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        return x;
    }
    Node *minNode(Node *root)
    {
        Node *current = root;
        while (current->left != NULL)
        {
            current = current->left;
        }
        return current;
    }
    Node *insert(Node *root, int data)
    {
        if (root == NULL)
        {
            return (new Node(data));
        }
        else if (data < root->data)
        {
            root->left = insert(root->left, data);
        }
        else if (data > root->data)
        {
            root->right = insert(root->right, data);
        }
        else
        {
            return root;
        }

        root->height = max(height(root->left), height(root->right)) + 1;
        int balance = getBalance(root);

        if (balance > 1 && data < root->left->data)
        {
            return rightRotate(root);
        }
        if (balance < -1 && data > root->right->data)
        {
            return leftRotate(root);
        }
        if (balance > 1 && data > root->left->data)
        {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
        if (balance < -1 && data < root->right->data)
        {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
        return root;
    }
    Node *del(Node *root, int data)
    {
        if (root == NULL)
        {
            return root;
        }

        if (data < root->data)
        {
            root->left = del(root->left, data);
        }
        else if (data > root->data)
        {
            root->right = del(root->right, data);
        }
        else
        {
            if (root->left == NULL)
            {
                Node *temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == NULL)
            {
                Node *temp = root->left;
                delete root;
                return temp;
            }

            Node *temp = minNode(root->right);
            root->data = temp->data;
            root->right = del(root->right, temp->data);
        }

        if (root == NULL)
        {
            return root;
        }

        root->height = 1 + max(height(root->left), height(root->right));
        int balance = getBalance(root);

        if (balance > 1 && getBalance(root->left) >= 0)
        {
            return rightRotate(root);
        }
        if (balance < -1 && getBalance(root->right) <= 0)
        {
            return leftRotate(root);
        }
        if (balance > 1 && getBalance(root->left) < 0)
        {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
        if (balance < -1 && getBalance(root->right) > 0)
        {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }
    void inorderTreversal(Node *root)
    {
        if (root == NULL)
        {
            return;
        }
        inorderTreversal(root->left);
        cout << root->data << " ";
        inorderTreversal(root->right);
    }
    void level(Node *root)
    {
        if (root == NULL)
        {
            return;
        }
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            Node *current = q.front();
            cout << current->data << " ";
            q.pop();
            if (current->left != NULL)
            {
                q.push(current->left);
            }
            if (current->right != NULL)
            {
                q.push(current->right);
            }
        }
    }
};

int main()
{
    int n = 0;
    cin >> n;
    AVLTree a1;
    for (int i = 0; i < n; i++)
    {
        int k = 0;
        cin >> k;
        a1.root = a1.insert(a1.root, k);
    }
    a1.inorderTreversal(a1.root);
    cout << endl;
    int t = 0;
    cin >> t;
    a1.root = a1.del(a1.root, t);
    a1.inorderTreversal(a1.root);
    return 0;
}