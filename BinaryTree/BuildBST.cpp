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

node* insert(node* root,int val)
{
    if(root==NULL)
    {
        return new node(val);
    }
    if(val < root->data)
    {
        root->left=insert(root->left,val);
    }
    else
    {
        root->right=insert(root->right,val);
    }
    return root;
}
void inorderdisplay(node* root)
{
    if(root==NULL)
    {
        return ;
    }

    inorderdisplay(root->left);
    cout<<root->data<<" ";
    inorderdisplay(root->right);
}

int main()
{
    node* root=NULL;
    root=insert(root,5);
    insert(root,1);
    insert(root,3);
    insert(root,4);
    insert(root,2);
    insert(root,7);

    inorderdisplay(root);
}