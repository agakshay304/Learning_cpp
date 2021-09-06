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

int countnode(node* root)
{
    if(root==NULL)
    {
        return 0;
    }

    return countnode(root->left)+countnode(root->right)+1;
}

int sumnode(node* root)
{
    if(root==NULL)
    {
        return 0;
    }

    return sumnode(root->left)+sumnode(root->right)+root->data;
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

    cout<<countnode(root)<<endl;
    cout<<sumnode(root)<<endl;
}