//if in the tree all node abs(lh-rh)<=1 then it is balanced height binary tree.

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

int height(node* root)
{
    if(root==NULL)
    {
        return 0;
    }

    int lh=height(root->left);
    int rh=height(root->right);

    return max(lh,rh)+1;
}

bool isbalanced(node* root)
{
    if(root==NULL)
    {
        return true;
    }

    if(isbalanced(root->left)==false)
    {
        return false;
    }
    if(isbalanced(root->right)==false)
    {
        return false;
    }

    int lh=height(root->left);
    int rh=height(root->right);

    if(abs(lh-rh)<=1)
    {
        return true;
    }
    return false;
}


//Optimised Version
bool isbalanced2(node* root,int* height)
{
    if(root==NULL)
    {
        return true;
    }
    int lh,rh=0;
    if(isbalanced2(root->left,&lh)==false)
    {
        return false;
    }
    if(isbalanced2(root->right,&rh)==false)
    {
        return false;
    }

    *height=max(lh,rh)+1;
     if(abs(lh-rh)<=1)
    {
        return true;
    }
    return false;
}
int main()
{
    node* root=new node(1);
    root->left=new node(2);
    root->right=new node(3);

    root->left->left=new node(4);
    root->left->right=new node(5);
    root->right->left=new node(6);
    root->right->right=new node(7);


    node* root2=new node(1);
    root2->left=new node(2);
    root2->left->left=new node(3);
    int height=0;
    if(isbalanced2(root,&height))
    {
        cout<<"Tree is balanced";
    }
    else
    {
        cout<<"Tree is not balanced";
    }
}