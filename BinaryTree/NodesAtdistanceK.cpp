#include <bits/stdc++.h>
#include <vector>
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
//case 1
void printsubtreenodes(node* root,int k)
{
    if(root==NULL || k<0)
    {
        return;
    }

    if(k==0)
    {
        cout<<root->data<<" ";
        return;
    }

    printsubtreenodes(root->left,k-1);
    printsubtreenodes(root->right,k-1);
}

//case 2
int printnodesatk(node* root,node* target,int k)
{
    if(root==NULL)
    {
        return -1;
    }
    if(root==target)
    {
        printsubtreenodes(root,k);
        return 0;//to indicate that target root in present
    }
    int ld=printnodesatk(root->left,target,k);
    if(ld!=-1)
    {
        if(ld+1==k)
        {
            cout<<root->data<<" ";
        }
        else
        {
            printnodesatk(root->right,target,k-ld-2);
        }
        return 1+ld;
    }
    int dr=printnodesatk(root->right,target,k);
    if(dr!=-1)
    {
        if(dr+1==k)
        {
            cout<<root->data<<" ";
        }
        else
        {
            printnodesatk(root->right,target,k-dr-2);
        }
        return 1+dr;
    }
    return -1;
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

    cout<<printnodesatk(root,root->left,2);

}