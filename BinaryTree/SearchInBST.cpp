#include <bits/stdc++.h>
using namespace std;

class node
{
    public:
int data;
node* left;
node* right;

node(int value)
{
    data=value;
    left=NULL;
    right=NULL;
}
};

node* search(node* root,int key)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(key==root->data)
    {
        return root;
    }
    else if(key<root->data)
    {
        return search(root->left,key);
    }
    else
    {
        return search(root->right,key);
    }
}

int main()
{
    node* root=new node(4);
    root->left=new node(2);
    root->right=new node(5);
    root->left->left=new node(1);
    root->left->right=new node(3);
    root->right->right=new node(6);

    if(search(root,9)==NULL)
    {
        cout<<"No not present";
    }
    else
    {
        cout<<"No. present";
    }
}