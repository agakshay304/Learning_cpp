#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node *left;
    Node *right;
    int data;

    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

void leftViewRecursion(Node *root, vector<int> &ans, int level)
{
    if (root == NULL)
        return;

    if (level == ans.size())
        ans.push_back(root->data);

    leftViewRecursion(root->left, ans, level + 1);
    leftViewRecursion(root->right, ans, level + 1);
}

void levelorder(Node *root, vector<int> &ans)
{
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int n = q.size();

        for (int i = 1; i <= n; i++)
        {
            Node *temp = q.front();
            q.pop();
            ans.push_back(temp->data);
            
            if (temp->left != NULL)
            {
                q.push(temp->left);
            }
            if (temp->right != NULL)
            {
                q.push(temp->right);
            }
        }
    }
}
void leftViewIterative(Node *root, vector<int> &ans)
{
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int n = q.size();
        for (int i = 1; i <= n; i++)
        {
            Node *temp = q.front();
            q.pop();
            if (i == 1)
                ans.push_back(temp->data);

            if (temp->left != NULL)
                q.push(temp->left);

            if (temp->right != NULL)
                q.push(temp->right);
        }
    }
}

Node *insertAtBST(Node *root, int value)
{
    if (root == NULL)
        return new Node(value);

    if (value < root->data)
    {
        root->left = insertAtBST(root->left, value);
    }
    else
    {
        root->right = insertAtBST(root->right, value);
    }

    return root;
}
void inorder(Node *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << "->"
         << " ";
    inorder(root->right);
}

int main()
{
    Node *root = NULL;
    root = insertAtBST(root, 10);
    insertAtBST(root, 3);
    insertAtBST(root, 2);
    insertAtBST(root, 8);
    insertAtBST(root, 6);
    insertAtBST(root, 1);
    insertAtBST(root, 7);

    inorder(root);
    cout << endl;
    vector<int> ans;

    // leftViewRecursion(root, ans, 0);
    // leftViewIterative(root, ans);
    levelorder(root, ans);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << "->"
             << " ";
    }
    cout << endl;
}