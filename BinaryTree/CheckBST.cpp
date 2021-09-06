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

bool checkbst(node* root,node* min,node* max)
{
    if(root==NULL)
    {
        return true;
    }

    if(min!=NULL && min->data>root->data)
    {
        return false;
    }
    if(max!=NULL && max->data<root->data)
    {
        return false;
    }
    //max is root because in left BST subtree the max value is of root.
    bool leftvalid=checkbst(root->left,min,root);
    //min is root because in right BST subtree the min value is of root.
    bool rightvalid=checkbst(root->right,root,max);

    return leftvalid && rightvalid;
}

int main()
{
    node* root=new node(4);
    root->left=new node(2);
    root->right=new node(5);
    root->left->left=new node(7);
    root->left->right=new node(3);
    root->right->right=new node(6);


    cout<<checkbst(root,NULL,NULL);
}
